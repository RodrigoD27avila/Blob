/*
 * rZ80 - Z80 Emulator.
 * Copyright (C) 2014  Rodrigo D'avila <r0dra42@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define M_LDWord(Reg) \
	Reg.b.l=RdMem8(PC++); Reg.b.h=RdMem8(PC++)

#define M_INC(Val) \
	Val++;     \
	F = SZTable[Val]|((Val==0x80)? VF : 0x0)|((Val&0xf)? HF : 0x0)

#define M_DEC(Val) \
	Val--;     \
	F = NF|SZTable[Val]|((Val==0x7f)? VF : 0x0)|(((Val&0xf)==0xf)? HF : 0x0)

#define M_ADD(Val)       \
	p.w.l = A + Val; \
	F = SZTable[p.b.l] | (((~A^Val)&(A^p.b.l)&0x80) ? VF : 0x0) | ((A^Val^p.b.l)&HF) | ((p.w.l&0x100) ? CF : 0x0); \
        A = p.b.l

#define M_ADC(Val)                  \
	p.w.l = A + Val + (F & CF); \
	F = SZTable[p.b.l] | (((~A^Val)&(A^p.b.l)&0x80) ? VF : 0x0) | ((A^Val^p.b.l)&HF) | ((p.w.l&0x100) ? CF : 0x0); \
        A = p.b.l

#define M_SUB(Val)       \
	p.w.l = A - Val; \
	F = NF|SZTable[p.b.l] | (((A^Val)&(A^p.b.l))&0x80) ? VF : 0x0 | ((A^Val^p.b.l)&HF) | ((p.w.l&0x100) ? CF : 0x0); \
        A = p.b.l

#define M_SBC(Val)                  \
	p.w.l = A - Val - (F & CF); \
	F = NF|SZTable[p.b.l] | (((A^Val)&(A^p.b.l))&0x80) ? VF : 0x0 | ((A^Val^p.b.l)&HF) | ((p.w.l&0x100) ? CF : 0x0); \
        A = p.b.l

#define M_AND(Val)        \
	p.b.l =  A & Val; \
	F = HF|SZTable[p.b.l] | (((A^Val)&(A^p.b.l))&0x80) ? VF : 0x0; \
	A = p.b.l

#define M_XOR(Val)       \
	p.b.l = A ^ Val; \
	F = SZTable[p.b.l] | (((A^Val)&(A^p.b.l))&0x80) ? VF : 0x0; \
	A = p.b.l

#define M_OR(Val)        \
	p.b.l = A | Val; \
	F = SZTable[p.b.l] | (((A^Val)&(A^p.b.l))&0x80) ? VF : 0x0; \
	A = p.b.l

#define M_CP(Val)        \
	p.w.l = A - Val; \
	F = NF|SZTable[p.b.l] | (((A^Val)&(A^p.b.l))&0x80) ? VF : 0x0 | ((A^Val^p.b.l)&HF) | ((p.w.l&0x100) ? CF : 0x0)

#define M_JP                \
	p.b.l=RdMem8(PC++); \
        p.b.h=RdMem8(PC++); \
        PC=p.w.l;           \
        Jump(PC)

#define M_JR                \
	p.b.l=RdMem8(PC+1); \
        PC  +=p.b.l;        \
        Jump(PC)

#define M_CALL                                  \
	p.b.l=RdMem8(PC++); p.b.h=RdMem8(PC++); \
	WrMem8(--SP, PCH); WrMem8(--SP, PCL);   \
	PC = p.w.l;                             \
	Jump(PC)

#define M_RET                 \
	p.b.l = RdMem8(SP++); \
	p.b.h = RdMem8(SP++); \
	PC    = p.w.l;        \
	Jump(PC)

#define M_PUSH(Reg) \
	WrMem8(--SP, Reg.b.h); WrMem8(--SP, Reg.b.l)

#define M_POP(Reg) \
	Reg.b.l=RdMem8(SP++); Reg.b.h=RdMem8(SP++)

#define M_RST(Val)                              \
	p.b.l=RdMem8(PC++); p.b.h=RdMem8(PC++); \
	WrMem8(--SP, PCH); WrMem8(--SP, PCL);   \
	PC = Val;                               \
	Jump(PC)

#define M_RLC(Ref)                    \
	p.b.l = Ref >> 7;             \
	Ref = Ref << 1; Ref |= p.b.l; \
	F = p.b.l | SZPTable[Ref]

#define M_RRC(Ref)                    \
	p.b.l = (Ref & 0x1);          \
	Ref = Ref >> 1; Ref |= p.b.l; \
	F = p.b.l | SZPTable[Ref]

#define M_RL(Ref)                        \
	p.b.l = Ref >> 7;                \
	Ref = Ref << 1; Ref |= (F & CF); \
	F = p.b.l | SZPTable[Ref]

#define M_RR(Ref)                             \
	p.b.l = (Ref & 0x1);                  \
	Ref = Ref >> 1; Ref |= (F & CF) << 7; \
	F = p.b.l | SZPTable[Ref]

#define M_SLA(Ref)         \
	p.b.l = Ref >> 7;  \
	Ref = Ref << 1;    \
	F = p.b.l | SZPTable[Ref]

#define M_SRA(Ref) \
	v     = (Ref & 0x80); \
	p.b.l = (Ref & 0x01); \
	Ref = (Ref >> 1) | v; \
	F = p.b.l | SZPTable[Ref]

#define M_SLL(Ref)              \
	p.b.l = Ref >> 7;       \
	Ref = (Ref << 1) | 0x1; \
	F = p.b.l | SZPTable[Ref]

#define M_SRL(Ref)           \
	p.b.l = (Ref & 0x1); \
	Ref = (Ref >> 1);    \
	F = p.b.l | SZPTable[p.b.l]

#define M_BIT(Ref, Bit) \
	F = (F&CF)|HF|SZPTable[Ref&(1<<Bit)]

#define M_RES(Ref, Bit) \
	Ref &= ~(1<<Bit)

#define M_SET(Ref, Bit) \
	Ref |= (1<<Bit)

#define M_OUT(Ref, Prt)  \
	Output(Ref, Prt)

#define M_IN(Ref, Prt)   \
	Ref=Input(Prt);  \
	F  = (F&CF) | SZPTable[Ref]

#define M_ADD16(Val)   \
	p.d = HL + Val; \
	F  = (((~HL^Val^p.w.l)&0x8000) ? VF : 0x0) | ((p.d&0x10000) ? CF : 0x0); \
        HL = p.w.l

#define M_ADC16(Val)                                           \
	p.d = HL + Val + (F&CF);                               \
	F  = ((p.w.l & 0x8000) ? SF : (p.w.l == 0) ? SF : 0x0) \
		| (((~HL^Val^p.w.l)&0x8000) ? VF : 0x0)        \
		| ((p.d&0x10000) ? CF : 0x0)                   \
		| (((HL^Val^p.w.l)&0x800)? HF : 0x0);          \
        HL = p.w.l

#define M_SBC16(Val)                                                 \
	p.w.l = HL - Val - (F & CF);                                 \
	F = NF  | ((p.w.l & 0x8000) ? SF : (p.w.l == 0) ? SF : 0x0)  \
		| ((((HL^Val)&(HL^p.w.l))&0x8000) ? VF : 0x0)        \
		| ((p.w.l&0x10000) ? CF : 0x0)                       \
		| (((HL^Val^p.w.l)&0x800) ? HF : 0x0);               \
        HF = p.w.l

#define M_RdMem16(Reg)                                      \
	p.b.l=RdMem8(PC++); p.b.h=RdMem8(PC++);             \
	Reg.b.h = RdMem8(p.w.l); Reg.b.l = RdMem8(p.w.l+1); \
	Reg.w.l = p.w.l

#define M_WrMem16(Reg)                                      \
	p.b.l=RdMem8(PC++); p.b.h=RdMem8(PC++);             \
	WrMem8(Reg.w.l, p.b.l); WrMem8(Reg.w.l+1, p.b.h)

#define M_ADD16_I(Val)   \
	p.d = HL + Val; \
	F  = (((~HL^Val^p.w.l)&0x8000) ? VF : 0x0) | ((p.d&0x10000) ? CF : 0x0); \
        HL = p.w.l

#define M_LD_Id(Val) b=RdMem8(PC++); WrMem8(IX+b, Val)

#define M_I_RLC(Ind, Ref)          \
	b = RdMem8(Ind+h);         \
	p.b.l = b >> 7;            \
	Ref = b << 1; b |= p.b.l;  \
	F = p.b.l | SZPTable[Ref]; \
	WrMem8(Ind+h, Ref)

#define M_I_RRC(Ind, Ref)          \
	b = RdMem8(Ind+h);         \
	p.b.l = (b & 0x1);         \
	Ref = b >> 1; b |= p.b.l;  \
	F = p.b.l | SZPTable[Ref]; \
	WrMem8(Ind+h, Ref)


#define M_I_RL(Ind, Ref)             \
	b = RdMem8(Ind+h);           \
	p.b.l = b >> 7;              \
	Ref = b << 1; b |= (F & CF); \
	F = p.b.l | SZPTable[Ref];   \
	WrMem8(Ind+h, Ref)

#define M_I_RR(Ind, Ref)                  \
	b = RdMem8(Ind+h);                \
	p.b.l = (b & 0x1);                \
	Ref = b >> 1; b |= (F & CF) << 7; \
	F = p.b.l | SZPTable[Ref];        \
	WrMem8(Ind+h, Ref)

#define M_I_SLA(Ind, Ref)             \
	b = RdMem8(Ind+h);            \
	p.b.l = b >> 7;               \
	Ref = b << 1;                 \
	F = p.b.l | SZPTable[Ref];    \
	WrMem8(Ind+h, Ref)

#define M_I_SRA(Ind, Ref)           \
	b = RdMem8(Ind+h);          \
	v     = (b & 0x80);         \
	p.b.l = (b & 0x01);         \
	Ref = (b >> 1) | v;         \
	F = p.b.l | SZPTable[Ref];  \
	WrMem8(Ind+h, Ref)

#define M_I_SLL(Ind, Ref)          \
	b = RdMem8(Ind+h);         \
	p.b.l =b >> 7;             \
	Ref = (b << 1) | 0x1;      \
	F = p.b.l | SZPTable[Ref]; \
	WrMem8(Ind+h, Ref)

#define M_I_SRL(Ind, Ref)             \
	b = RdMem8(Ind+h);           \
	p.b.l = (b & 0x1);           \
	Ref = (b >> 1);              \
	F = p.b.l | SZPTable[p.b.l]; \
	WrMem8(Ind+h, Ref)

#define M_I_BIT(Ind, Bit)                     \
	b = RdMem8(Ind+h);                    \
	F = (F&CF)|HF|SZPTable[b&(1<<Bit)]

#define M_I_RES(Ind, Ref, Bit)   \
	b = RdMem8(Ind+h);  \
	b &= ~(1<<Bit);     \
	Ref = b;            \
	WrMem8(Ind+h, b)

#define M_I_SET(Ind, Ref, Bit)   \
	b = RdMem8(Ind+h);  \
	b |= (1<<Bit);      \
	Ref = b;            \
	WrMem8(Ind+h, b)

