/*
 * rZ80 - Z80 Emulator.
 * Copyright (C) 2014  Rodrigo D'avila <r0dra42@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under Gthe terms of the GNU General Public License as published by
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
	IN_B_pC=0x40, OUT_pC_B, SBC_HL_BC, LD_pnn_BC, NEG1, RETN1, IM_0_1 , LD_I_A,
	IN_C_pC     , OUT_pC_C, ADC_HL_BC, LD_BC_pnn, NEG2, RETI , IM_01_1, LD_R_A,
	IN_D_pC     , OUT_pC_D, SBC_HL_DE, LD_pnn_DE, NEG3, RETN2, IM_1_1 , LD_A_I,
	IN_E_pC     , OUT_pC_E, ADC_HL_DE, LD_DE_pnn, NEG4, RETN3, IM_2_1 , LD_A_R,
	IN_H_pC     , OUT_pC_H, SBC_HL_HL, LD_pnn_HL, NEG5, RETN4, IM_0_2 , RRD   ,
	IN_L_pC     , OUT_pC_L, ADC_HL_HL, LD_HL_pnn, NEG6, RETN5, IM_01_2, RLD   ,
	IN_pC       , OUT_pC  , SBC_HL_SP, LD_pnn_SP, NEG7, RETN6, IM_1_2 ,
	IN_A_pC=0x78, OUT_pc_A, ADC_HL_SP, LD_SP_pnn, NEG8, RETN7, IM_2_2 ,

	LDI=0xa0, CPI, INI, OUTI,
	LDD=0xa8, CPD, IND, OUTD,

	LDIR=0xb0, CPIR, INIR, OTIR,
	LDDR=0xb8, CPDR, INDR, OTDR,

};

case IN_B_pC: M_IN(B,C);break;
case IN_C_pC: M_IN(C,C);break;
case IN_D_pC: M_IN(D,C);break;
case IN_E_pC: M_IN(E,C);break;
case IN_H_pC: M_IN(H,C);break;
case IN_L_pC: M_IN(L,C);break;
case IN_A_pC: M_IN(A,C);break;
case IN_pC: M_IN(p.b.l,C);break;

case OUT_pC_B: M_OUT(B, C);break;
case OUT_pC_C: M_OUT(C, C);break;
case OUT_pC_D: M_OUT(D, C);break;
case OUT_pC_E: M_OUT(E, C);break;
case OUT_pC_H: M_OUT(H, C);break;
case OUT_pC_L: M_OUT(L, C);break;
case OUT_pc_A: M_OUT(A, C);break;
case OUT_pC: M_OUT(0, C);break;

case ADC_HL_BC: M_ADC16(BC);break;
case ADC_HL_DE: M_ADC16(DE);break;
case ADC_HL_HL: M_ADC16(HL);break;
case ADC_HL_SP: M_ADC16(SP);break;

case SBC_HL_BC: M_SBC(BC);break;
case SBC_HL_DE: M_SBC(DE);break;
case SBC_HL_HL: M_SBC(HL);break;
case SBC_HL_SP: M_SBC(SP);break;

case LD_pnn_BC: M_RdMem16(bc);break;
case LD_pnn_DE: M_RdMem16(de);break;
case LD_pnn_HL: M_RdMem16(hl);break;
case LD_pnn_SP: M_RdMem16(sp);break;

case LD_BC_pnn: M_WrMem16(bc);break;
case LD_DE_pnn: M_WrMem16(de);break;
case LD_HL_pnn: M_WrMem16(hl);break;
case LD_SP_pnn: M_WrMem16(sp);break;

case NEG1:
case NEG2:
case NEG3:
case NEG4:
case NEG5:
case NEG6:
case NEG7:
case NEG8:
   p.b.l = A; A = 0; M_SUB(p.b.l);
   break;

case RETI:
case RETN1:
case RETN2:
case RETN3:
case RETN4:
case RETN5:
case RETN6:
case RETN7:
   if (IFF & IFF_2) {IFF |= IFF_1;} else {IFF &= ~IFF_1;}
   break;

case IM_0_1:
case IM_0_2:
   IFF &= ~(IFF_M1|IFF_M2);
   break;

case IM_01_1:
case IM_01_2:
   IFF &= (IFF_M1|IFF_M2); IFF |= (IFF_M1|IFF_M2);
   break;

case IM_1_1:
case IM_1_2:
   IFF &= ~(IFF_M1); IFF |= IFF_M2;
   break;

case IM_2_1:
case IM_2_2:
   IFF &= ~(IFF_M2); IFF |= IFF_M1;
   break;

case LD_I_A: I=A;break;
case LD_R_A: R=A;break;

case LD_A_I: A=I; F=(F&CF)|SZTable[A]|((IFF&IFF_2) ? VF : 0x0);break;
case LD_A_R: A=R; F=(F&CF)|SZTable[A]|((IFF&IFF_2) ? VF : 0x0);break;

case RRD:
   b    =RdMem8(HL);
   v    =A;
   A    =(A&0xf0)|(b&0x0f);
   p.b.l=(b>>4)|(v<<4);
   F    = (F&CF) | SZPTable[A];
   WrMem8(HL, p.b.l);
   break;

case RLD:
   b    =RdMem8(HL);
   v    =A;
   A    =(A&0xf0)|(b>>4);
   p.b.l=(b<<4)|(v&0x0f);
   F    = (F&CF) | SZPTable[A];
   WrMem8(HL, p.b.l);
   break;

case LDI:
   WrMem8(DE, RdMem8(HL));
   DE+=1; HL+=1; BC-=1;
   F=(F&(CF|SF|ZF))|((BC == 0) ? 0x0 : VF);
   break;

case LDD:
   WrMem8(DE, RdMem8(HL));
   DE-=1; HL-=1; BC-=1;
   F=(F&(CF|SF|ZF))|((BC==0) ? 0x0 : VF);
   break;

case LDIR:
   do {
      WrMem8(DE, RdMem8(HL));
      DE+=1; HL+=1; BC-=1;
      icount-=21;
   } while (BC && icount > 0);
   F=(F&(CF|SF|ZF));
   if (BC > 0) {PC-=2;} else {icount+=5;};
   break;

case LDDR:
   do {
      WrMem8(DE, RdMem8(HL));
      DE-=1; HL-=1; BC-=1;
      icount-=21;;
   } while (BC && icount > 0);
   F=(F&(CF|SF|ZF));
   if (BC > 0) {PC-=2;} else {icount+=5;};
   break;

case CPI:
   p.b.l=RdMem8(HL);
   F = NF|(F&CF);
   if (A < p.b.l)
      F |= SF;
   else if (A == p.b.l)
      F |= ZF;

   BC-=1;HL+=1;
   F |= ((BC == 0) ? 0x0 : VF)|((A^(A-p.b.l)^p.b.l)&HF);
   break;

case CPD:
   p.b.l=RdMem8(HL);
   F = NF|(F&CF);
   if (A < p.b.l)
      F |= SF;
   else if (A == p.b.l)
      F |= ZF;

   BC-=1;HL-=1;
   F |= ((BC==0) ? 0x0 : VF)|((A^(A-p.b.l)^p.b.l)&HF);
   break;

case CPIR:
   do {
      p.b.l=RdMem8(HL);
      BC-=1;HL+=1;
      icount -= 21;
   } while(BC && icount > 0);
   if (BC) {PC-=2;} else {icount-=5;};

   F = NF|(F&CF);
   if (A < p.b.l)
      F |= SF;
   else if (A == p.b.l)
      F |= ZF;

   F |= ((BC == 0) ? 0x0 : VF)|((A^(A-p.b.l)^p.b.l)&HF);
   break;

case CPDR:
   do {
      p.b.l=RdMem8(HL);
      BC-=1;HL-=1;
      icount -= 21;
   } while(BC && icount > 0);
   if (BC) {PC-=2;} else {icount-=5;};

   F = NF|(F&CF);
   if (A < p.b.l)
      F |= SF;
   else if (A == p.b.l)
      F |= ZF;

   F |= ((BC == 0) ? 0x0 : VF)|((A^(A-p.b.l)^p.b.l)&HF);
   break;


case INI:
   WrMem8(HL, Input(C));
   B-=1; HL+=1;
   F = (F&CF)|((B==0) ? ZF : 0x0)|NF;
   break;

case IND:
   WrMem8(HL, Input(C));
   B-=1; HL-=1;
   F = (F&CF)|((B==0) ? ZF : 0x0)|NF;
   break;

case INIR:
   do {
      WrMem8(HL, Input(C));
      B-=1; HL+=1;
      icount -= 21;
   } while (BC && icount > 0);
   if (BC) {PC-=2;} else {icount-=5;};

   F = (F&CF)|((B==0) ? ZF : 0x0)|NF;
   break;

case INDR:
   do {
      WrMem8(HL, Input(C));
      B-=1; HL-=1;
      icount -= 21;
   } while (BC && icount > 0);
   if (BC) {PC-=2;} else {icount-=5;};

   F = (F&CF)|((B==0) ? ZF : 0x0)|NF;
   break;

case OUTI:
   Output(C, RdMem8(HL));
   B-=1; HL+=1;
   F = (F&CF)|((B==0) ? ZF : 0x0)|NF;
   break;

case OUTD:
   Output(C, RdMem8(HL));
   B-=1; HL-=1;
   F = (F&CF)|((B==0) ? ZF : 0x0)|NF;
   break;

case OTIR:
   do {
      Output(C, RdMem8(HL));
      B-=1; HL+=1;
      icount -= 21;;
   } while (BC && icount > 0);
   if (BC) {PC-=2;} else {icount-=5;};

   F = (F&CF)|((B==0) ? ZF : 0x0)|NF;
   break;

case OTDR:
   do {
      Output(C, RdMem8(HL));
      B-=1; HL-=1;
      icount -= 21;;
   } while (BC && icount > 0);
   if (BC) {PC-=2;} else {icount-=5;};

   F = (F&CF)|((B==0) ? ZF : 0x0)|NF;
   break;
