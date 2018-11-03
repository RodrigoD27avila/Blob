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
	ADD_IY_BC=0x09, ADD_IY_DE=0x19,
	LD_IY_nn =0x21, LD_pnn_IY, INC_IY, INC_IYh, DEC_IYh, LD_IYh_n,
	ADD_IY_IY=0x29, LD_IY_pnn, DEC_IY, INC_IYl, DEC_IYl, LD_IYl_n,

	INC_IYd  =0x34, DEC_IYd, LD_IYd_n,
	ADD_IY_SP=0x39,

	LD_B_IYh=0x44, LD_B_IYl, LD_B_IYd,
	LD_C_IYh=0x4c, LD_C_IYl, LD_C_IYd,
	LD_D_IYh=0x54, LD_D_IYl, LD_D_IYd,
	LD_E_IYh=0x5c, LD_E_IYl, LD_E_IYd,

	LD_IYh_B=0x60, LD_IYh_C, LD_IYh_D, LD_IYh_E, LD_IYh_IYh, LD_IYh_IYl, LD_H_IYd, LD_IYh_A,
	LD_IYl_B=0x68, LD_IYl_C, LD_IYl_D, LD_IYl_E, LD_IYl_IYh, LD_IYl_IYl, LD_L_IYd, LD_IYl_A,

	LD_IYd_B=0x70, LD_IYd_C, LD_IYd_D, LD_IYd_E, LD_IYd_H, LD_IYd_L, LD_IYd_A,

	LD_A_IYh=0x7c, LD_A_IYl, LD_A_IYd,

	ADD_A_IYh=0x84, ADD_A_IYl, ADD_A_IYd,
	ADC_A_IYh=0x8c, ADC_A_IYl, ADC_A_IYd,
	SUB_A_IYh=0x94, SUB_A_IYl, SUB_A_IYd,
	SBC_A_IYh=0x9c, SBC_A_IYl, SBC_A_IYd,

	AND_IYh=0xa4, AND_IYl, AND_IYd,
	XOR_IYh=0xac, XOR_IYl, XOR_IYd,
	OR_IYh =0xb4, OR_IYl , OR_IYd ,
	CP_IYh =0xbc, CP_IYl , CP_IYd ,

	OP_FDCB=0xcb,

	POP_IY=0xe1, EX_pSP_IY=0xe3, PUSH_IY=0xe5, JP_pIY=0xe9, LD_SP_IY=0xf9,
};

case OP_FDCB:
	b  = RdMem8(PC++);
	v = RdMem8(PC++);
	OpFDCB(v, b);
	break;

/*TODO: set the other flags*/
case ADD_IY_BC: IY=BC; F=(F&(ZF|CF));break;
case ADD_IY_DE: IY=DE; F=(F&(ZF|CF));break;
case ADD_IY_IY: IY=IY; F=(F&(ZF|CF));break;
case ADD_IY_SP: IY=SP; F=(F&(ZF|CF));break;


case INC_IY: IY+=1;break;
case DEC_IY: IY-=1;break;

case INC_IYh: M_INC(IYH);break;
case INC_IYl: M_INC(IYL);break;

case INC_IYd:
   b=RdMem8(PC++);
   v=RdMem8(IY+b);
   M_INC(v);
   WrMem8(IY+b, v);
   break;

case DEC_IYh: M_DEC(IYH);break;
case DEC_IYl: M_DEC(IYL);break;

case DEC_IYd:
   b=RdMem8(PC++);
   v=RdMem8(IY+b);
   M_INC(v);
   WrMem8(IY+b, v);
   break;

case LD_IYh_n: IYH=RdMem8(PC++);break;
case LD_IYl_n: IYL=RdMem8(PC++);break;

case LD_IY_pnn:
   M_RdMem16(iy);
   break;

case LD_pnn_IY:
   M_WrMem16(iy);
   break;

case LD_IY_nn:
   M_LDWord(iy);
   break;

case LD_IYh_B: IYH=B;break;
case LD_IYh_C: IYH=C;break;
case LD_IYh_D: IYH=D;break;
case LD_IYh_E: IYH=E;break;
case LD_IYh_A: IYH=A;break;

case LD_IYh_IYh: IYH=IYH;break;
case LD_IYh_IYl: IYH=IYL;break;

case LD_H_IYd:
   b=RdMem8(PC++);
   H=RdMem8(IY+b);
   break;


case LD_IYl_B: IYL=B;break;
case LD_IYl_C: IYL=C;break;
case LD_IYl_D: IYL=D;break;
case LD_IYl_E: IYL=E;break;
case LD_IYl_A: IYL=A;break;

case LD_IYl_IYh: IYL=IYH;break;
case LD_IYl_IYl: IYL=IYL;break;

case LD_L_IYd:
   b=RdMem8(PC++);
   L=RdMem8(IY+b);
   break;

case LD_IYd_B: M_LD_Id(B);break;
case LD_IYd_C: M_LD_Id(B);break;
case LD_IYd_D: M_LD_Id(B);break;
case LD_IYd_E: M_LD_Id(B);break;
case LD_IYd_H: M_LD_Id(B);break;
case LD_IYd_L: M_LD_Id(B);break;
case LD_IYd_A: M_LD_Id(B);break;

case LD_IYd_n: v=RdMem8(PC++); M_LD_Id(v);break;

case LD_A_IYh: A=IYH;break;
case LD_A_IYl: A=IYL;break;
case LD_A_IYd: A=RdMem8(IY+RdMem8(PC++));break;

case ADD_A_IYh: M_ADD(IYH);break;
case ADD_A_IYl: M_ADD(IYL);break;

case ADD_A_IYd:
   b=RdMem8(PC++);
   v=RdMem8(IY+b);
   M_ADD(v);
   break;

case ADC_A_IYh: M_ADC(IYH);break;
case ADC_A_IYl: M_ADC(IYL);break;

case ADC_A_IYd:
   b=RdMem8(PC++);
   v=RdMem8(IY+b);
   M_ADC(v);
   break;

case SUB_A_IYh: M_SUB(IYH);break;
case SUB_A_IYl: M_SUB(IYL);break;

case SUB_A_IYd:
   b=RdMem8(PC++);
   v=RdMem8(IY+b);
   M_SUB(v);
   break;

case SBC_A_IYh: M_SBC(IYH);break;
case SBC_A_IYl: M_SBC(IYL);break;

case SBC_A_IYd:
   b=RdMem8(PC++);
   v=RdMem8(IY+b);
   M_SBC(v);
   break;

case AND_IYh: M_AND(IYH);break;
case AND_IYl: M_AND(IYL);break;

case AND_IYd:
   b=RdMem8(PC++);
   v=RdMem8(IY+b);
   M_AND(v);
   break;

case XOR_IYh: M_XOR(IYH);break;
case XOR_IYl: M_XOR(IYL);break;

case XOR_IYd:
   b=RdMem8(PC++);
   v=RdMem8(IY+b);
   M_XOR(v);
   break;

case OR_IYh: M_OR(IYH);break;
case OR_IYl: M_OR(IYL);break;

case OR_IYd:
   b=RdMem8(PC++);
   v=RdMem8(IY+b);
   M_OR(v);
   break;

case CP_IYh: M_CP(IYH);break;
case CP_IYl: M_CP(IYL);break;

case CP_IYd:
   b=RdMem8(PC++);
   v=RdMem8(IY+b);
   M_CP(v);
   break;

case POP_IY: M_POP(iy);break;
case PUSH_IY: M_PUSH(iy);break;

case EX_pSP_IY:
   p.b.l=RdMem8(SP-1); p.b.h=RdMem8(SP-2);
   WrMem8(SP-1, IYH) ; WrMem8(SP-2, IYL) ;
   IY=p.w.l;
   break;

case JP_pIY:
   p.w.l=RdMem8(IY);
   p.w.h=RdMem8(IY+1);
   PC=p.w.l;
   Jump(PC);
   break;

case LD_SP_IY: SP=IY;break;
