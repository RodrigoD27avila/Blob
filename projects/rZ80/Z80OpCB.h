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
	RLC_B, RLC_C, RLC_D, RLC_E, RLC_H, RLC_L, RLC_pHL, RLC_A,
	RRC_B, RRC_C, RRC_D, RRC_E, RRC_H, RRC_L, RRC_pHL, RRC_A,
	RL_B , RL_C , RL_D , RL_E , RL_H , RL_L , RL_pHL , RL_A ,
	RR_B , RR_C , RR_D , RR_E , RR_H , RR_L , RR_pHL , RR_A ,
	SLA_B, SLA_C, SLA_D, SLA_E, SLA_H, SLA_L, SLA_pHL, SLA_A,
	SRA_B, SRA_C, SRA_D, SRA_E, SRA_H, SRA_L, SRA_pHL, SRA_A,

	SLL_B, SLL_C, SLL_D, SLL_E, SLL_H, SLL_L, SLL_pHL, SLL_A,

	SRL_B, SRL_C, SRL_D, SRL_E, SRL_H, SRL_L, SRL_pHL, SRL_A,

	BIT_0_B, BIT_0_C, BIT_0_D, BIT_0_E, BIT_0_H, BIT_0_L, BIT_0_pHL, BIT_0_A,
	BIT_1_B, BIT_1_C, BIT_1_D, BIT_1_E, BIT_1_H, BIT_1_L, BIT_1_pHL, BIT_1_A,
	BIT_2_B, BIT_2_C, BIT_2_D, BIT_2_E, BIT_2_H, BIT_2_L, BIT_2_pHL, BIT_2_A,
	BIT_3_B, BIT_3_C, BIT_3_D, BIT_3_E, BIT_3_H, BIT_3_L, BIT_3_pHL, BIT_3_A,
	BIT_4_B, BIT_4_C, BIT_4_D, BIT_4_E, BIT_4_H, BIT_4_L, BIT_4_pHL, BIT_4_A,
	BIT_5_B, BIT_5_C, BIT_5_D, BIT_5_E, BIT_5_H, BIT_5_L, BIT_5_pHL, BIT_5_A,
	BIT_6_B, BIT_6_C, BIT_6_D, BIT_6_E, BIT_6_H, BIT_6_L, BIT_6_pHL, BIT_6_A,
	BIT_7_B, BIT_7_C, BIT_7_D, BIT_7_E, BIT_7_H, BIT_7_L, BIT_7_pHL, BIT_7_A,

        RES_0_B, RES_0_C, RES_0_D, RES_0_E, RES_0_H, RES_0_L, RES_0_pHL, RES_0_A,
        RES_1_B, RES_1_C, RES_1_D, RES_1_E, RES_1_H, RES_1_L, RES_1_pHL, RES_1_A,
        RES_2_B, RES_2_C, RES_2_D, RES_2_E, RES_2_H, RES_2_L, RES_2_pHL, RES_2_A,
        RES_3_B, RES_3_C, RES_3_D, RES_3_E, RES_3_H, RES_3_L, RES_3_pHL, RES_3_A,
        RES_4_B, RES_4_C, RES_4_D, RES_4_E, RES_4_H, RES_4_L, RES_4_pHL, RES_4_A,
        RES_5_B, RES_5_C, RES_5_D, RES_5_E, RES_5_H, RES_5_L, RES_5_pHL, RES_5_A,
        RES_6_B, RES_6_C, RES_6_D, RES_6_E, RES_6_H, RES_6_L, RES_6_pHL, RES_6_A,
        RES_7_B, RES_7_C, RES_7_D, RES_7_E, RES_7_H, RES_7_L, RES_7_pHL, RES_7_A,

	SET_0_B, SET_0_C, SET_0_D, SET_0_E, SET_0_H, SET_0_L, SET_0_pHL, SET_0_A,
        SET_1_B, SET_1_C, SET_1_D, SET_1_E, SET_1_H, SET_1_L, SET_1_pHL, SET_1_A,
        SET_2_B, SET_2_C, SET_2_D, SET_2_E, SET_2_H, SET_2_L, SET_2_pHL, SET_2_A,
        SET_3_B, SET_3_C, SET_3_D, SET_3_E, SET_3_H, SET_3_L, SET_3_pHL, SET_3_A,
        SET_4_B, SET_4_C, SET_4_D, SET_4_E, SET_4_H, SET_4_L, SET_4_pHL, SET_4_A,
        SET_5_B, SET_5_C, SET_5_D, SET_5_E, SET_5_H, SET_5_L, SET_5_pHL, SET_5_A,
        SET_6_B, SET_6_C, SET_6_D, SET_6_E, SET_6_H, SET_6_L, SET_6_pHL, SET_6_A,
        SET_7_B, SET_7_C, SET_7_D, SET_7_E, SET_7_H, SET_7_L, SET_7_pHL, SET_7_A,
};


case RLC_B: M_RLC(B);break;
case RLC_C: M_RLC(C);break;
case RLC_D: M_RLC(D);break;
case RLC_E: M_RLC(E);break;
case RLC_H: M_RLC(H);break;
case RLC_L: M_RLC(L);break;
case RLC_A: M_RLC(A);break;

case RLC_pHL:
   b = RdMem8(HL);
   M_RLC(b);
   WrMem8(HL, b);
   break;

case RRC_B: M_RRC(B);break;
case RRC_C: M_RRC(C);break;
case RRC_D: M_RRC(D);break;
case RRC_E: M_RRC(E);break;
case RRC_H: M_RRC(H);break;
case RRC_L: M_RRC(L);break;
case RRC_A: M_RRC(A);break;

case RRC_pHL:
   b = RdMem8(HL);
   M_RRC(b);
   WrMem8(HL, b);
   break;

case RL_B: M_RL(B);break;
case RL_C: M_RL(C);break;
case RL_D: M_RL(D);break;
case RL_E: M_RL(E);break;
case RL_H: M_RL(H);break;
case RL_L: M_RL(L);break;
case RL_A: M_RL(A);break;

case RL_pHL:
   b = RdMem8(HL);
   M_RL(b);
   WrMem8(HL, b);
   break;

case RR_B: M_RR(B);break;
case RR_C: M_RR(C);break;
case RR_D: M_RR(D);break;
case RR_E: M_RR(E);break;
case RR_H: M_RR(H);break;
case RR_L: M_RR(L);break;
case RR_A: M_RR(A);break;

case RR_pHL:
   b = RdMem8(HL);
   M_RR(b);
   WrMem8(HL, b);
   break;

case SLA_B: M_SLA(B);break;
case SLA_C: M_SLA(C);break;
case SLA_D: M_SLA(D);break;
case SLA_E: M_SLA(E);break;
case SLA_H: M_SLA(H);break;
case SLA_L: M_SLA(L);break;
case SLA_A: M_SLA(A);break;

case SLA_pHL:
   b = RdMem8(HL);
   M_SLA(b);
   WrMem8(HL, b);
   break;

case SRA_B: M_SRA(B);break;
case SRA_C: M_SRA(C);break;
case SRA_D: M_SRA(D);break;
case SRA_E: M_SRA(E);break;
case SRA_H: M_SRA(H);break;
case SRA_L: M_SRA(L);break;
case SRA_A: M_SRA(A);break;

case SRA_pHL:
   b = RdMem8(HL);
   M_SRA(b);
   WrMem8(HL, b);
   break;

case SLL_B: M_SLL(B);break;
case SLL_C: M_SLL(C);break;
case SLL_D: M_SLL(D);break;
case SLL_E: M_SLL(E);break;
case SLL_H: M_SLL(H);break;
case SLL_L: M_SLL(L);break;
case SLL_A: M_SLL(A);break;

case SLL_pHL:
   b = RdMem8(HL);
   M_SLL(b);
   WrMem8(HL, b);
   break;

case SRL_B: M_SRL(B);break;
case SRL_C: M_SRL(B);break;
case SRL_D: M_SRL(B);break;
case SRL_E: M_SRL(B);break;
case SRL_H: M_SRL(B);break;
case SRL_L: M_SRL(B);break;
case SRL_A: M_SRL(B);break;

case SRL_pHL:
   b = RdMem8(HL);
   M_SRL(b);
   WrMem8(HL, b);
   break;

case BIT_0_B: M_BIT(B, 0);break;
case BIT_0_C: M_BIT(C, 0);break;
case BIT_0_D: M_BIT(D, 0);break;
case BIT_0_E: M_BIT(E, 0);break;
case BIT_0_H: M_BIT(H, 0);break;
case BIT_0_L: M_BIT(L, 0);break;
case BIT_0_A: M_BIT(A, 0);break;

case BIT_0_pHL:
   b = RdMem8(HL);
   M_BIT(b, 0);
   WrMem8(HL, b);
   break;


case BIT_1_B: M_BIT(B, 1);break;
case BIT_1_C: M_BIT(C, 1);break;
case BIT_1_D: M_BIT(D, 1);break;
case BIT_1_E: M_BIT(E, 1);break;
case BIT_1_H: M_BIT(H, 1);break;
case BIT_1_L: M_BIT(L, 1);break;
case BIT_1_A: M_BIT(A, 1);break;

case BIT_1_pHL:
   b = RdMem8(HL);
   M_BIT(b, 1);
   WrMem8(HL, b);
   break;

case BIT_2_B: M_BIT(B, 2);break;
case BIT_2_C: M_BIT(C, 2);break;
case BIT_2_D: M_BIT(D, 2);break;
case BIT_2_E: M_BIT(E, 2);break;
case BIT_2_H: M_BIT(H, 2);break;
case BIT_2_L: M_BIT(L, 2);break;
case BIT_2_A: M_BIT(A, 2);break;

case BIT_2_pHL:
   b = RdMem8(HL);
   M_BIT(b, 2);
   WrMem8(HL, b);
   break;

case BIT_3_B: M_BIT(B, 3);break;
case BIT_3_C: M_BIT(C, 3);break;
case BIT_3_D: M_BIT(D, 3);break;
case BIT_3_E: M_BIT(E, 3);break;
case BIT_3_H: M_BIT(H, 3);break;
case BIT_3_L: M_BIT(L, 3);break;
case BIT_3_A: M_BIT(A, 3);break;

case BIT_3_pHL:
   b = RdMem8(HL);
   M_BIT(b, 3);
   WrMem8(HL, b);
   break;

case BIT_4_B: M_BIT(B, 4);break;
case BIT_4_C: M_BIT(C, 4);break;
case BIT_4_D: M_BIT(D, 4);break;
case BIT_4_E: M_BIT(E, 4);break;
case BIT_4_H: M_BIT(H, 4);break;
case BIT_4_L: M_BIT(L, 4);break;
case BIT_4_A: M_BIT(A, 4);break;

case BIT_4_pHL:
   b = RdMem8(HL);
   M_BIT(b, 4);
   WrMem8(HL, b);
   break;

case BIT_5_B: M_BIT(B, 5);break;
case BIT_5_C: M_BIT(C, 5);break;
case BIT_5_D: M_BIT(D, 5);break;
case BIT_5_E: M_BIT(E, 5);break;
case BIT_5_H: M_BIT(H, 5);break;
case BIT_5_L: M_BIT(L, 5);break;
case BIT_5_A: M_BIT(A, 5);break;

case BIT_5_pHL:
   b = RdMem8(HL);
   M_BIT(b, 5);
   WrMem8(HL, b);
   break;

case BIT_6_B: M_BIT(B, 6);break;
case BIT_6_C: M_BIT(C, 6);break;
case BIT_6_D: M_BIT(D, 6);break;
case BIT_6_E: M_BIT(E, 6);break;
case BIT_6_H: M_BIT(H, 6);break;
case BIT_6_L: M_BIT(L, 6);break;
case BIT_6_A: M_BIT(A, 6);break;

case BIT_6_pHL:
   b = RdMem8(HL);
   M_BIT(b, 6);
   WrMem8(HL, b);
   break;

case BIT_7_B: M_BIT(B, 7);break;
case BIT_7_C: M_BIT(C, 7);break;
case BIT_7_D: M_BIT(D, 7);break;
case BIT_7_E: M_BIT(E, 7);break;
case BIT_7_H: M_BIT(H, 7);break;
case BIT_7_L: M_BIT(L, 7);break;
case BIT_7_A: M_BIT(A, 7);break;

case BIT_7_pHL:
   b = RdMem8(HL);
   M_BIT(b, 7);
   WrMem8(HL, b);
   break;

case RES_0_B: M_RES(B, 0);break;
case RES_0_C: M_RES(C, 0);break;
case RES_0_D: M_RES(D, 0);break;
case RES_0_E: M_RES(E, 0);break;
case RES_0_H: M_RES(H, 0);break;
case RES_0_L: M_RES(L, 0);break;
case RES_0_A: M_RES(A, 0);break;

case RES_0_pHL:
   b = RdMem8(HL);
   M_RES(b, 0);
   WrMem8(HL, b);
   break;


case RES_1_B: M_RES(B, 1);break;
case RES_1_C: M_RES(C, 1);break;
case RES_1_D: M_RES(D, 1);break;
case RES_1_E: M_RES(E, 1);break;
case RES_1_H: M_RES(H, 1);break;
case RES_1_L: M_RES(L, 1);break;
case RES_1_A: M_RES(A, 1);break;

case RES_1_pHL:
   b = RdMem8(HL);
   M_RES(b, 1);
   WrMem8(HL, b);
   break;

case RES_2_B: M_RES(B, 2);break;
case RES_2_C: M_RES(C, 2);break;
case RES_2_D: M_RES(D, 2);break;
case RES_2_E: M_RES(E, 2);break;
case RES_2_H: M_RES(H, 2);break;
case RES_2_L: M_RES(L, 2);break;
case RES_2_A: M_RES(A, 2);break;

case RES_2_pHL:
   b = RdMem8(HL);
   M_RES(b, 2);
   WrMem8(HL, b);
   break;

case RES_3_B: M_RES(B, 3);break;
case RES_3_C: M_RES(C, 3);break;
case RES_3_D: M_RES(D, 3);break;
case RES_3_E: M_RES(E, 3);break;
case RES_3_H: M_RES(H, 3);break;
case RES_3_L: M_RES(L, 3);break;
case RES_3_A: M_RES(A, 3);break;

case RES_3_pHL:
   b = RdMem8(HL);
   M_RES(b, 3);
   WrMem8(HL, b);
   break;

case RES_4_B: M_RES(B, 4);break;
case RES_4_C: M_RES(C, 4);break;
case RES_4_D: M_RES(D, 4);break;
case RES_4_E: M_RES(E, 4);break;
case RES_4_H: M_RES(H, 4);break;
case RES_4_L: M_RES(L, 4);break;
case RES_4_A: M_RES(A, 4);break;

case RES_4_pHL:
   b = RdMem8(HL);
   M_RES(b, 4);
   WrMem8(HL, b);
   break;

case RES_5_B: M_RES(B, 5);break;
case RES_5_C: M_RES(C, 5);break;
case RES_5_D: M_RES(D, 5);break;
case RES_5_E: M_RES(E, 5);break;
case RES_5_H: M_RES(H, 5);break;
case RES_5_L: M_RES(L, 5);break;
case RES_5_A: M_RES(A, 5);break;

case RES_5_pHL:
   b = RdMem8(HL);
   M_RES(b, 5);
   WrMem8(HL, b);
   break;

case RES_6_B: M_RES(B, 6);break;
case RES_6_C: M_RES(C, 6);break;
case RES_6_D: M_RES(D, 6);break;
case RES_6_E: M_RES(E, 6);break;
case RES_6_H: M_RES(H, 6);break;
case RES_6_L: M_RES(L, 6);break;
case RES_6_A: M_RES(A, 6);break;

case RES_6_pHL:
   b = RdMem8(HL);
   M_RES(b, 6);
   WrMem8(HL, b);
   break;

case RES_7_B: M_RES(B, 7);break;
case RES_7_C: M_RES(C, 7);break;
case RES_7_D: M_RES(D, 7);break;
case RES_7_E: M_RES(E, 7);break;
case RES_7_H: M_RES(H, 7);break;
case RES_7_L: M_RES(L, 7);break;
case RES_7_A: M_RES(A, 7);break;

case RES_7_pHL:
   b = RdMem8(HL);
   M_RES(b, 7);
   WrMem8(HL, b);
   break;

case SET_0_B: M_SET(B, 0);break;
case SET_0_C: M_SET(C, 0);break;
case SET_0_D: M_SET(D, 0);break;
case SET_0_E: M_SET(E, 0);break;
case SET_0_H: M_SET(H, 0);break;
case SET_0_L: M_SET(L, 0);break;
case SET_0_A: M_SET(A, 0);break;

case SET_0_pHL:
   b = RdMem8(HL);
   M_SET(b, 0);
   WrMem8(HL, b);
   break;


case SET_1_B: M_SET(B, 1);break;
case SET_1_C: M_SET(C, 1);break;
case SET_1_D: M_SET(D, 1);break;
case SET_1_E: M_SET(E, 1);break;
case SET_1_H: M_SET(H, 1);break;
case SET_1_L: M_SET(L, 1);break;
case SET_1_A: M_SET(A, 1);break;

case SET_1_pHL:
   b = RdMem8(HL);
   M_SET(b, 1);
   WrMem8(HL, b);
   break;

case SET_2_B: M_SET(B, 2);break;
case SET_2_C: M_SET(C, 2);break;
case SET_2_D: M_SET(D, 2);break;
case SET_2_E: M_SET(E, 2);break;
case SET_2_H: M_SET(H, 2);break;
case SET_2_L: M_SET(L, 2);break;
case SET_2_A: M_SET(A, 2);break;

case SET_2_pHL:
   b = RdMem8(HL);
   M_SET(b, 2);
   WrMem8(HL, b);
   break;

case SET_3_B: M_SET(B, 3);break;
case SET_3_C: M_SET(C, 3);break;
case SET_3_D: M_SET(D, 3);break;
case SET_3_E: M_SET(E, 3);break;
case SET_3_H: M_SET(H, 3);break;
case SET_3_L: M_SET(L, 3);break;
case SET_3_A: M_SET(A, 3);break;

case SET_3_pHL:
   b = RdMem8(HL);
   M_SET(b, 3);
   WrMem8(HL, b);
   break;

case SET_4_B: M_SET(B, 4);break;
case SET_4_C: M_SET(C, 4);break;
case SET_4_D: M_SET(D, 4);break;
case SET_4_E: M_SET(E, 4);break;
case SET_4_H: M_SET(H, 4);break;
case SET_4_L: M_SET(L, 4);break;
case SET_4_A: M_SET(A, 4);break;

case SET_4_pHL:
   b = RdMem8(HL);
   M_SET(b, 4);
   WrMem8(HL, b);
   break;

case SET_5_B: M_SET(B, 5);break;
case SET_5_C: M_SET(C, 5);break;
case SET_5_D: M_SET(D, 5);break;
case SET_5_E: M_SET(E, 5);break;
case SET_5_H: M_SET(H, 5);break;
case SET_5_L: M_SET(L, 5);break;
case SET_5_A: M_SET(A, 5);break;

case SET_5_pHL:
   b = RdMem8(HL);
   M_SET(b, 5);
   WrMem8(HL, b);
   break;

case SET_6_B: M_SET(B, 6);break;
case SET_6_C: M_SET(C, 6);break;
case SET_6_D: M_SET(D, 6);break;
case SET_6_E: M_SET(E, 6);break;
case SET_6_H: M_SET(H, 6);break;
case SET_6_L: M_SET(L, 6);break;
case SET_6_A: M_SET(A, 6);break;

case SET_6_pHL:
   b = RdMem8(HL);
   M_SET(b, 6);
   WrMem8(HL, b);
   break;

case SET_7_B: M_SET(B, 7);break;
case SET_7_C: M_SET(C, 7);break;
case SET_7_D: M_SET(D, 7);break;
case SET_7_E: M_SET(E, 7);break;
case SET_7_H: M_SET(H, 7);break;
case SET_7_L: M_SET(L, 7);break;
case SET_7_A: M_SET(A, 7);break;

case SET_7_pHL:
   b = RdMem8(HL);
   M_SET(b, 7);
   WrMem8(HL, b);
   break;
