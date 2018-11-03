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
	ADD_IX_BC=0x09, ADD_IX_DE=0x19,
	LD_IX_nn =0x21, LD_pnn_IX, INC_IX, INC_IXh, DEC_IXh, LD_IXh_n,
	ADD_IX_IX=0x29, LD_IX_pnn, DEC_IX, INC_IXl, DEC_IXl, LD_IXl_n,

	INC_IXd  =0x34, DEC_IXd, LD_IXd_n,
	ADD_IX_SP=0x39,

	LD_B_IXh=0x44, LD_B_IXl, LD_B_IXd,
	LD_C_IXh=0x4c, LD_C_IXl, LD_C_IXd,
	LD_D_IXh=0x54, LD_D_IXl, LD_D_IXd,
	LD_E_IXh=0x5c, LD_E_IXl, LD_E_IXd,

	LD_IXh_B=0x60, LD_IXh_C, LD_IXh_D, LD_IXh_E, LD_IXh_IXh, LD_IXh_IXl, LD_H_IXd, LD_IXh_A,
	LD_IXl_B=0x68, LD_IXl_C, LD_IXl_D, LD_IXl_E, LD_IXl_IXh, LD_IXl_IXl, LD_L_IXd, LD_IXl_A,

	LD_IXd_B=0x70, LD_IXd_C, LD_IXd_D, LD_IXd_E, LD_IXd_H, LD_IXd_L, LD_IXd_A,

	LD_A_IXh=0x7c, LD_A_IXl, LD_A_IXd,

	ADD_A_IXh=0x84, ADD_A_IXl, ADD_A_IXd,
	ADC_A_IXh=0x8c, ADC_A_IXl, ADC_A_IXd,
	SUB_A_IXh=0x94, SUB_A_IXl, SUB_A_IXd,
	SBC_A_IXh=0x9c, SBC_A_IXl, SBC_A_IXd,

	AND_IXh=0xa4, AND_IXl, AND_IXd,
	XOR_IXh=0xac, XOR_IXl, XOR_IXd,
	OR_IXh =0xb4, OR_IXl , OR_IXd ,
	CP_IXh =0xbc, CP_IXl , CP_IXd ,

	OP_DDCB=0xcb,

	POP_IX=0xe1, EX_pSP_IX=0xe3, PUSH_IX=0xe5, JP_pIX=0xe9, LD_SP_IX=0xf9,
};


case OP_DDCB:
	b   = RdMem8(PC++);
	v   = RdMem8(PC++);
	OpDDCB(v, b);
	break;

/*TODO: set the other flags*/
case ADD_IX_BC: IX=BC; F=(F&(ZF|CF));break;
case ADD_IX_DE: IX=DE; F=(F&(ZF|CF));break;
case ADD_IX_IX: IX=IX; F=(F&(ZF|CF));break;
case ADD_IX_SP: IX=SP; F=(F&(ZF|CF));break;


case INC_IX: IX+=1;break;
case DEC_IX: IX-=1;break;

case INC_IXh: M_INC(IXH);break;
case INC_IXl: M_INC(IXL);break;

case INC_IXd:
   b=RdMem8(PC++);
   v=RdMem8(IX+b);
   M_INC(v);
   WrMem8(IX+b, v);
   break;

case DEC_IXh: M_DEC(IXH);break;
case DEC_IXl: M_DEC(IXL);break;

case DEC_IXd:
   b=RdMem8(PC++);
   v=RdMem8(IX+b);
   M_INC(v);
   WrMem8(IX+b, v);
   break;

case LD_IXh_n: IXH=RdMem8(PC++);break;
case LD_IXl_n: IXL=RdMem8(PC++);break;

case LD_IX_pnn:
   M_RdMem16(ix);
   break;

case LD_pnn_IX:
   M_WrMem16(ix);
   break;

case LD_IX_nn:
   M_LDWord(ix);
   break;

case LD_IXh_B: IXH=B;break;
case LD_IXh_C: IXH=C;break;
case LD_IXh_D: IXH=D;break;
case LD_IXh_E: IXH=E;break;
case LD_IXh_A: IXH=A;break;

case LD_IXh_IXh: IXH=IXH;break;
case LD_IXh_IXl: IXH=IXL;break;

case LD_H_IXd:
   b=RdMem8(PC++);
   H=RdMem8(IX+b);
   break;


case LD_IXl_B: IXL=B;break;
case LD_IXl_C: IXL=C;break;
case LD_IXl_D: IXL=D;break;
case LD_IXl_E: IXL=E;break;
case LD_IXl_A: IXL=A;break;

case LD_IXl_IXh: IXL=IXH;break;
case LD_IXl_IXl: IXL=IXL;break;

case LD_L_IXd:
   b=RdMem8(PC++);
   L=RdMem8(IX+b);
   break;

case LD_IXd_B: M_LD_Id(B);break;
case LD_IXd_C: M_LD_Id(B);break;
case LD_IXd_D: M_LD_Id(B);break;
case LD_IXd_E: M_LD_Id(B);break;
case LD_IXd_H: M_LD_Id(B);break;
case LD_IXd_L: M_LD_Id(B);break;
case LD_IXd_A: M_LD_Id(B);break;

case LD_IXd_n: v=RdMem8(PC++); M_LD_Id(v);break;

case LD_A_IXh: A=IXH;break;
case LD_A_IXl: A=IXL;break;
case LD_A_IXd: A=RdMem8(IX+RdMem8(PC++));break;

case ADD_A_IXh: M_ADD(IXH);break;
case ADD_A_IXl: M_ADD(IXL);break;

case ADD_A_IXd:
   b=RdMem8(PC++);
   v=RdMem8(IX+b);
   M_ADD(v);
   break;

case ADC_A_IXh: M_ADC(IXH);break;
case ADC_A_IXl: M_ADC(IXL);break;

case ADC_A_IXd:
   b=RdMem8(PC++);
   v=RdMem8(IX+b);
   M_ADC(v);
   break;

case SUB_A_IXh: M_SUB(IXH);break;
case SUB_A_IXl: M_SUB(IXL);break;

case SUB_A_IXd:
   b=RdMem8(PC++);
   v=RdMem8(IX+b);
   M_SUB(v);
   break;

case SBC_A_IXh: M_SBC(IXH);break;
case SBC_A_IXl: M_SBC(IXL);break;

case SBC_A_IXd:
   b=RdMem8(PC++);
   v=RdMem8(IX+b);
   M_SBC(v);
   break;

case AND_IXh: M_AND(IXH);break;
case AND_IXl: M_AND(IXL);break;

case AND_IXd:
   b=RdMem8(PC++);
   v=RdMem8(IX+b);
   M_AND(v);
   break;

case XOR_IXh: M_XOR(IXH);break;
case XOR_IXl: M_XOR(IXL);break;

case XOR_IXd:
   b=RdMem8(PC++);
   v=RdMem8(IX+b);
   M_XOR(v);
   break;

case OR_IXh: M_OR(IXH);break;
case OR_IXl: M_OR(IXL);break;

case OR_IXd:
   b=RdMem8(PC++);
   v=RdMem8(IX+b);
   M_OR(v);
   break;

case CP_IXh: M_CP(IXH);break;
case CP_IXl: M_CP(IXL);break;

case CP_IXd:
   b=RdMem8(PC++);
   v=RdMem8(IX+b);
   M_CP(v);
   break;

case POP_IX: M_POP(ix);break;
case PUSH_IX: M_PUSH(ix);break;

case EX_pSP_IX:
   p.b.l=RdMem8(SP-1); p.b.h=RdMem8(SP-2);
   WrMem8(SP-1, IXH) ; WrMem8(SP-2, IXL) ;
   IX=p.w.l;
   break;

case JP_pIX:
   p.w.l=RdMem8(IX);
   p.w.h=RdMem8(IX+1);
   PC=p.w.l;
   Jump(PC);
   break;

case LD_SP_IX: SP=IX;break;
