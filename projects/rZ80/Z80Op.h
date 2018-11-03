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

enum {
	NOP      , LD_BC_nn , LD_pBC_A , INC_BC, INC_B  , DEC_B  , LD_B_n  , RLCA,
	EX_AF_AF , ADD_HL_BC, LD_A_pBC , DEC_BC, INC_C  , DEC_C  , LD_C_n  , RRCA,
	DJNZ     , LD_DE_nn , LD_pDE_A , INC_DE, INC_D  , DEC_D  , LD_D_n  , RLA ,
	JR       , ADD_HL_DE, LD_A_pDE , DEC_DE, INC_E  , DEC_E  , LD_E_n  , RRA ,
	JR_NZ    , LD_HL_nn , LD_pnn_HL, INC_HL, INC_H  , DEC_H  , LD_H_n  , DAA ,
	JR_Z     , ADD_HL_HL, LD_HL_pnn, DEC_HL, INC_L  , DEC_L  , LD_L_n  , CPL ,
	JR_NC    , LD_SP_nn , LD_pnn_A , INC_SP, INC_pHL, DEC_pHL, LD_pHL_n, SCF ,
	JR_C     , ADD_HL_SP, LD_A_pnn , DEC_SP, INC_A  , DEC_A  , LD_A_n  , CCF ,

	LD_B_B, LD_B_C, LD_B_D, LD_B_E, LD_B_H, LD_B_L, LD_B_pHL, LD_B_A,
	LD_C_B, LD_C_C, LD_C_D, LD_C_E, LD_C_H, LD_C_L, LD_C_pHL, LD_C_A,
	LD_D_B, LD_D_C, LD_D_D, LD_D_E, LD_D_H, LD_D_L, LD_D_pHL, LD_D_A,
	LD_E_B, LD_E_C, LD_E_D, LD_E_E, LD_E_H, LD_E_L, LD_E_pHL, LD_E_A,
	LD_H_B, LD_H_C, LD_H_D, LD_H_E, LD_H_H, LD_H_L, LD_H_pHL, LD_H_A,
	LD_L_B, LD_L_C, LD_L_D, LD_L_E, LD_L_H, LD_L_L, LD_L_pHL, LD_L_A,

	LD_pHL_B, LD_pHL_C, LD_pHL_D, LD_pHL_E, LD_pHL_H, LD_pHL_L, HALT, LD_pHL_A,

	LD_A_B, LD_A_C, LD_A_D, LD_A_E, LD_A_H, LD_A_L, LD_A_pHL, LD_A_A,

	ADD_A_B, ADD_A_C, ADD_A_D, ADD_A_E, ADD_A_H, ADD_A_L, ADD_A_pHL, ADD_A_A,
	ADC_A_B, ADC_A_C, ADC_A_D, ADC_A_E, ADC_A_H, ADC_A_L, ADC_A_pHL, ADC_A_A,
	SUB_A_B, SUB_A_C, SUB_A_D, SUB_A_E, SUB_A_H, SUB_A_L, SUB_A_pHL, SUB_A_A,
	SBC_A_B, SBC_A_C, SBC_A_D, SBC_A_E, SBC_A_H, SBC_A_L, SBC_A_pHL, SBC_A_A,

	AND_B, AND_C, AND_D, AND_E, AND_H, AND_L, AND_pHL, AND_A,
	XOR_B, XOR_C, XOR_D, XOR_E, XOR_H, XOR_L, XOR_pHL, XOR_A,
	OR_B , OR_C , OR_D , OR_E , OR_H , OR_L , OR_pHL , OR_A ,
	CP_B , CP_C , CP_D , CP_E , CP_H , CP_L , CP_pHL , CP_A ,

	RET_NZ, POP_BC  , JP_NZ, JP       , CALL_NZ, PUSH_BC , ADD_n, RST_0H ,
	RET_Z , RET     , JP_Z , CB_OP    , CALL_Z , CALL    , ADC_n, RST_8H ,
	RET_NC, POP_DE  , JP_NC, OUT_A    , CALL_NC, PUSH_DE , SUB_n, RST_10H,
	RET_C , EXX     , JP_C , IN_A     , CALL_C , DD_OP   , SBC_n, RST_18H,
	RET_PO, POP_HL  , JP_PO, EX_pSP_HL, CALL_PO, PUSH_HL , AND_n, RST_20H,
	RET_PE, JP_HL   , JP_PE, EX_DE_HL , CALL_PE, ED_OP   , XOR_n, RST_28H,
	RET_P , POP_AF  , JP_P , DI       , CALL_P , PUSH_AF , OR_n , RST_30H,
	RET_M , LD_SP_HL, JP_M , EI       , CALL_M , FD_OP   , CP_n , RST_38H,
};

case CB_OP: v=RdMem8(PC++); OpCB(v); break;
case DD_OP: v=RdMem8(PC++); OpDD(v); break;
case ED_OP: v=RdMem8(PC++); OpED(v); break;
case FD_OP: v=RdMem8(PC++); OpFD(v); break;

case LD_B_B: B=B;break;
case LD_B_C: B=C;break;
case LD_B_D: B=D;break;
case LD_B_E: B=E;break;
case LD_B_H: B=H;break;
case LD_B_L: B=L;break;
case LD_B_A: B=A;break;

case LD_C_B: C=B;break;
case LD_C_C: C=C;break;
case LD_C_D: C=D;break;
case LD_C_E: C=E;break;
case LD_C_H: C=H;break;
case LD_C_L: C=L;break;
case LD_C_A: C=A;break;

case LD_D_B: D=B;break;
case LD_D_C: D=C;break;
case LD_D_D: D=D;break;
case LD_D_E: D=E;break;
case LD_D_H: D=H;break;
case LD_D_L: D=L;break;
case LD_D_A: D=A;break;

case LD_E_B: E=B;break;
case LD_E_C: E=C;break;
case LD_E_D: E=D;break;
case LD_E_E: E=E;break;
case LD_E_H: E=H;break;
case LD_E_L: E=L;break;
case LD_E_A: E=A;break;

case LD_H_B: H=B;break;
case LD_H_C: H=C;break;
case LD_H_D: H=D;break;
case LD_H_E: H=E;break;
case LD_H_H: H=H;break;
case LD_H_L: H=L;break;
case LD_H_A: H=A;break;

case LD_L_B: L=B;break;
case LD_L_C: L=C;break;
case LD_L_D: L=D;break;
case LD_L_E: L=E;break;
case LD_L_H: L=H;break;
case LD_L_L: L=L;break;
case LD_L_A: L=A;break;

case LD_A_B: A=B;break;
case LD_A_C: A=C;break;
case LD_A_D: A=D;break;
case LD_A_E: A=E;break;
case LD_A_H: A=H;break;
case LD_A_L: A=L;break;
case LD_A_A: A=A;break;

case LD_B_pHL: B=RdMem8(HL);break;
case LD_C_pHL: C=RdMem8(HL);break;
case LD_D_pHL: D=RdMem8(HL);break;
case LD_E_pHL: E=RdMem8(HL);break;
case LD_H_pHL: H=RdMem8(HL);break;
case LD_L_pHL: L=RdMem8(HL);break;
case LD_A_pHL: A=RdMem8(HL);break;

case LD_pHL_B: WrMem8(HL, B);break;
case LD_pHL_C: WrMem8(HL, C);break;
case LD_pHL_D: WrMem8(HL, D);break;
case LD_pHL_E: WrMem8(HL, E);break;
case LD_pHL_H: WrMem8(HL, H);break;
case LD_pHL_L: WrMem8(HL, L);break;
case LD_pHL_A: WrMem8(HL, A);break;

case LD_BC_nn: M_LDWord(bc);break;
case LD_DE_nn: M_LDWord(de);break;
case LD_HL_nn: M_LDWord(hl);break;
case LD_SP_nn: M_LDWord(sp);break;

case LD_pBC_A: WrMem8(BC, A);break;
case LD_pDE_A: WrMem8(DE, A);break;

case LD_pnn_A: break;
   M_LDWord(p);
   WrMem8(p.w.l, A);
   break;

case LD_A_pnn:
  M_LDWord(p);
  A=RdMem8(p.w.l);
  break;

case LD_pnn_HL:
   M_LDWord(p);
   WrMem8(p.w.l++, L);
   WrMem8(p.w.l  , H);
   break;

case LD_HL_pnn:
   M_LDWord(p);
   L=RdMem8(p.w.l++);
   H=RdMem8(p.w.l  );
   break;

case LD_A_pBC: A=RdMem8(BC);break;
case LD_A_pDE: A=RdMem8(DE);break;

case LD_B_n: B=RdMem8(PC++);break;
case LD_C_n: C=RdMem8(PC++);break;
case LD_D_n: D=RdMem8(PC++);break;
case LD_E_n: E=RdMem8(PC++);break;
case LD_H_n: H=RdMem8(PC++);break;
case LD_L_n: L=RdMem8(PC++);break;
case LD_A_n: A=RdMem8(PC++);break;

case LD_pHL_n:
   WrMem8(HL, RdMem8(PC++));
   break;

case LD_SP_HL: SP=HL;break;

case INC_BC: ++BC;break;
case INC_DE: ++DE;break;
case INC_HL: ++HL;break;
case INC_SP: ++SP;break;

case DEC_BC: --BC;break;
case DEC_DE: --DE;break;
case DEC_HL: --HL;break;
case DEC_SP: --SP;break;

case INC_B: M_INC(B);break;
case INC_C: M_INC(C);break;
case INC_D: M_INC(D);break;
case INC_E: M_INC(E);break;
case INC_H: M_INC(H);break;
case INC_L: M_INC(L);break;
case INC_A: M_INC(A);break;

case INC_pHL:
   p.b.l=RdMem8(HL);
   M_INC(p.b.l);
   WrMem8(HL, p.b.l);
   break;

case DEC_B: M_DEC(B);break;
case DEC_C: M_DEC(C);break;
case DEC_D: M_DEC(D);break;
case DEC_E: M_DEC(E);break;
case DEC_H: M_DEC(H);break;
case DEC_L: M_DEC(L);break;
case DEC_A: M_DEC(A);break;

case DEC_pHL:
   p.b.l=RdMem8(HL);
   M_DEC(p.b.l);
   WrMem8(HL, p.b.l);
   break;

case ADD_A_B: M_ADD(B);break;
case ADD_A_C: M_ADD(C);break;
case ADD_A_D: M_ADD(D);break;
case ADD_A_E: M_ADD(E);break;
case ADD_A_H: M_ADD(H);break;
case ADD_A_L: M_ADD(L);break;
case ADD_A_A: M_ADD(A);break;

case ADD_A_pHL:
   b = RdMem8(HL);
   M_ADD(b);
   break;

case ADD_n:
   b = RdMem8(PC++);
   M_ADD(b);
   break;

case ADD_HL_BC: M_ADD16(BC);break;
case ADD_HL_DE: M_ADD16(DE);break;
case ADD_HL_HL: M_ADD16(HL);break;
case ADD_HL_SP: M_ADD16(SP);break;

case ADC_A_B: M_ADC(B);break;
case ADC_A_C: M_ADC(C);break;
case ADC_A_D: M_ADC(D);break;
case ADC_A_E: M_ADC(E);break;
case ADC_A_H: M_ADC(H);break;
case ADC_A_L: M_ADC(L);break;
case ADC_A_A: M_ADC(A);break;

case ADC_A_pHL:
   b = RdMem8(HL);
   M_ADC(b);
   break;

case ADC_n:
   b = RdMem8(PC++);
   M_ADC(b);
   break;

case SUB_A_B: M_SUB(B);break;
case SUB_A_C: M_SUB(C);break;
case SUB_A_D: M_SUB(D);break;
case SUB_A_E: M_SUB(E);break;
case SUB_A_H: M_SUB(H);break;
case SUB_A_L: M_SUB(L);break;
case SUB_A_A: M_SUB(A);break;

case SUB_A_pHL:
   b = RdMem8(HL);
   M_SUB(b);
   break;

case SUB_n:
   b = RdMem8(PC++);
   M_SUB(b);
   break;

case SBC_A_B: M_SBC(B);break;
case SBC_A_C: M_SBC(C);break;
case SBC_A_D: M_SBC(D);break;
case SBC_A_E: M_SBC(E);break;
case SBC_A_H: M_SBC(H);break;
case SBC_A_L: M_SBC(L);break;
case SBC_A_A: M_SBC(A);break;

case SBC_A_pHL:
   b = RdMem8(HL);
   M_SBC(b);
   break;

case SBC_n:
   b = RdMem8(PC++);
   M_SBC(b);
   break;

case AND_B: M_AND(B);break;
case AND_C: M_AND(C);break;
case AND_D: M_AND(D);break;
case AND_E: M_AND(E);break;
case AND_H: M_AND(H);break;
case AND_L: M_AND(L);break;
case AND_A: M_AND(A);break;

case AND_pHL:
   b = RdMem8(HL);
   M_AND(b);
   break;

case AND_n:
   b = RdMem8(PC++);
   M_AND(b);
   break;

case XOR_B: M_XOR(B);break;
case XOR_C: M_XOR(C);break;
case XOR_D: M_XOR(D);break;
case XOR_E: M_XOR(E);break;
case XOR_H: M_XOR(H);break;
case XOR_L: M_XOR(L);break;
case XOR_A: M_XOR(A);break;

case XOR_pHL:
   b = RdMem8(HL);
   M_XOR(b);
   break;

case XOR_n:
   b = RdMem8(PC++);
   M_XOR(b);
   break;

case OR_B: M_OR(B);break;
case OR_C: M_OR(C);break;
case OR_D: M_OR(D);break;
case OR_E: M_OR(E);break;
case OR_H: M_OR(H);break;
case OR_L: M_OR(L);break;
case OR_A: M_OR(A);break;

case OR_pHL:
   b = RdMem8(HL);
   M_OR(b);
   break;

case OR_n:
   b = RdMem8(PC++);
   M_OR(b);
   break;

case CP_B: M_CP(B);break;
case CP_C: M_CP(C);break;
case CP_D: M_CP(D);break;
case CP_E: M_CP(E);break;
case CP_H: M_CP(H);break;
case CP_L: M_CP(L);break;
case CP_A: M_CP(A);break;

case CP_pHL:
   b = RdMem8(HL);
   M_CP(b);
   break;

case CP_n:
   b = RdMem8(PC++);
   M_CP(b);
   break;

case JP: M_JP;break;

case JP_HL: PC=HL;Jump(PC);break;

case JP_NZ: if (F & ZF) {PC+=2;} else {M_JP;}break;
case JP_NC: if (F & CF) {PC+=2;} else {M_JP;}break;
case JP_PO: if (F & PF) {PC+=2;} else {M_JP;}break;
case JP_P:  if (F & SF) {PC+=2;} else {M_JP;}break;

case JP_Z:  if (F & ZF) {M_JP;} else {PC+=2;}break;
case JP_C:  if (F & CF) {M_JP;} else {PC+=2;}break;
case JP_PE: if (F & PF) {M_JP;} else {PC+=2;}break;
case JP_M:  if (F & SF) {M_JP;} else {PC+=2;}break;


case JR: M_JR;break;

case JR_NZ: if (F & ZF) {PC+=2;} else {M_JR;}break;
case JR_NC: if (F & CF) {PC+=2;} else {M_JR;}break;

case JR_Z:  if (F & ZF) {M_JR;} else {PC+=2;}break;
case JR_C:  if (F & CF) {M_JR;} else {PC+=2;}break;

case CALL: M_CALL;break;

case CALL_NZ: if (F & ZF) {icount-=7;PC+=2;} else {M_CALL;}break;
case CALL_NC: if (F & CF) {icount-=7;PC+=2;} else {M_CALL;}break;
case CALL_PO: if (F & PF) {icount-=7;PC+=2;} else {M_CALL;}break;
case CALL_P:  if (F & SF) {icount-=7;PC+=2;} else {M_CALL;}break;

case CALL_Z:  if (F & ZF) {M_CALL;} else {icount-=7;PC+=2;}break;
case CALL_C:  if (F & CF) {M_CALL;} else {icount-=7;PC+=2;}break;
case CALL_PE: if (F & PF) {M_CALL;} else {icount-=7;PC+=2;}break;
case CALL_M:  if (F & SF) {M_CALL;} else {icount-=7;PC+=2;}break;

case RET: M_RET;break;

case RET_NZ: if (F & ZF) {icount-=6;} else {M_RET;}break;
case RET_NC: if (F & CF) {icount-=6;} else {M_RET;}break;
case RET_PO: if (F & PF) {icount-=6;} else {M_RET;}break;
case RET_P:  if (F & SF) {icount-=6;} else {M_RET;}break;

case RET_Z:  if (F & ZF) {M_RET;} else {icount-=6;}break;
case RET_C:  if (F & CF) {M_RET;} else {icount-=6;}break;
case RET_PE: if (F & PF) {M_RET;} else {icount-=6;}break;
case RET_M:  if (F & SF) {M_RET;} else {icount-=6;}break;

case PUSH_BC: M_PUSH(bc);break;
case PUSH_DE: M_PUSH(de);break;
case PUSH_HL: M_PUSH(hl);break;
case PUSH_AF: M_PUSH(af);break;

case POP_BC: M_POP(bc);break;
case POP_DE: M_POP(de);break;
case POP_HL: M_POP(hl);break;
case POP_AF: M_POP(af);break;

case EXX:
   p.w.l=BC;BC=_BC;_BC=p.w.l;
   p.w.l=DE;DE=_DE;_DE=p.w.l;
   p.w.l=HL;HL=_HL;_HL=p.w.l;
   break;

case OUT_A: Output(RdMem8(PC++), A);break;
case IN_A:  A=Input(RdMem8(PC++));break;

case EX_DE_HL: p.w.l=DE;DE=HL;HL=p.w.l;break;

case EX_pSP_HL:
   p.b.l=RdMem8(SP+1);p.b.h=RdMem8(SP+2);
   WrMem8(SP+2, H);WrMem8(SP+1, L);
   HL = p.w.l;
   break;

case DI: iff  = 0; break;
case EI: iff  = (IFF_1 | IFF_2); break;

case RST_0H:  M_RST(0x00);break;
case RST_8H:  M_RST(0x08);break;
case RST_10H: M_RST(0x10);break;
case RST_18H: M_RST(0x18);break;
case RST_20H: M_RST(0x20);break;
case RST_28H: M_RST(0x28);break;
case RST_30H: M_RST(0x30);break;
case RST_38H: M_RST(0x38);break;

case EX_AF_AF:
   p.w.l=AF;AF=_AF;_AF=p.w.l;
   break;

case DJNZ: if (--B) {M_JR;} else {PC++;}break;

case RLCA: M_RLC(A);break;
case RRCA: M_RRC(A);break;
case RLA: M_RL(A);break;
case RRA: M_RR(A);break;

case CPL:
   A = ~A;
   F = NF | HF;
   break;

case SCF: F |= CF; break;
case CCF: F |= (~F & CF); break;

case DAA:
   v = A;
   if(F & NF) {
      if((F & HF) | ((A & 0xf) > 9)) v -= 6;
      if((F & CF) | (A > 0x99)) v -= 0x60;
   }
   else {
      if((F & HF) | ((A & 0xf) > 9)) v += 6;
      if((F & CF) | (A > 0x99)) v += 0x60;
   }
   F = (F & (CF | NF)) | (A > 0x99) | ((A ^ v) & HF)| SZPTable[A];
   A = v;
   break;


case HALT:
   PC--;
   halt = true;
   break;

case NOP: break;
