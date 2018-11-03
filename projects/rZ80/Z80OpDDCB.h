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
	RLC_IXd_B, RLC_IXd_C, RLC_IXd_D, RLC_IXd_E, RLC_IXd_H, RLC_IXd_L, RLC_IXd, RLC_IXd_A,
	RRC_IXd_B, RRC_IXd_C, RRC_IXd_D, RRC_IXd_E, RRC_IXd_H, RRC_IXd_L, RRC_IXd, RRC_IXd_A,
	RL_IXd_B , RL_IXd_C , RL_IXd_D , RL_IXd_E , RL_IXd_H , RL_IXd_L , RL_IXd , RL_IXd_A ,
	RR_IXd_B , RR_IXd_C , RR_IXd_D , RR_IXd_E , RR_IXd_H , RR_IXd_L , RR_IXd , RR_IXd_A ,
	SLA_IXd_B, SLA_IXd_C, SLA_IXd_D, SLA_IXd_E, SLA_IXd_H, SLA_IXd_L, SLA_IXd, SLA_IXd_A,
	SRA_IXd_B, SRA_IXd_C, SRA_IXd_D, SRA_IXd_E, SRA_IXd_H, SRA_IXd_L, SRA_IXd, SRA_IXd_A,

	SLL_IXd_B, SLL_IXd_C, SLL_IXd_D, SLL_IXd_E, SLL_IXd_H, SLL_IXd_L, SLL_IXd, SLL_IXd_A,

	SRL_IXd_B, SRL_IXd_C, SRL_IXd_D, SRL_IXd_E, SRL_IXd_H, SRL_IXd_L, SRL_IXd, SRL_IXd_A,

	BIT_0_IXd0, BIT_0_IXd1, BIT_0_IXd2, BIT_0_IXd3, BIT_0_IXd4, BIT_0_IXd5, BIT_0_IXd, BIT_0_IXd6,
	BIT_1_IXd0, BIT_1_IXd1, BIT_1_IXd2, BIT_1_IXd3, BIT_1_IXd4, BIT_1_IXd5, BIT_1_IXd, BIT_1_IXd6,
	BIT_2_IXd0, BIT_2_IXd1, BIT_2_IXd2, BIT_2_IXd3, BIT_2_IXd4, BIT_2_IXd5, BIT_2_IXd, BIT_2_IXd6,
	BIT_3_IXd0, BIT_3_IXd1, BIT_3_IXd2, BIT_3_IXd3, BIT_3_IXd4, BIT_3_IXd5, BIT_3_IXd, BIT_3_IXd6,
	BIT_4_IXd0, BIT_4_IXd1, BIT_4_IXd2, BIT_4_IXd3, BIT_4_IXd4, BIT_4_IXd5, BIT_4_IXd, BIT_4_IXd6,
	BIT_5_IXd0, BIT_5_IXd1, BIT_5_IXd2, BIT_5_IXd3, BIT_5_IXd4, BIT_5_IXd5, BIT_5_IXd, BIT_5_IXd6,
	BIT_6_IXd0, BIT_6_IXd1, BIT_6_IXd2, BIT_6_IXd3, BIT_6_IXd4, BIT_6_IXd5, BIT_6_IXd, BIT_6_IXd6,
	BIT_7_IXd0, BIT_7_IXd1, BIT_7_IXd2, BIT_7_IXd3, BIT_7_IXd4, BIT_7_IXd5, BIT_7_IXd, BIT_7_IXd6,

        RES_0_IXd_B, RES_0_IXd_C, RES_0_IXd_D, RES_0_IXd_E, RES_0_IXd_H, RES_0_IXd_L, RES_0_IXd, RES_0_IXd_A,
        RES_1_IXd_B, RES_1_IXd_C, RES_1_IXd_D, RES_1_IXd_E, RES_1_IXd_H, RES_1_IXd_L, RES_1_IXd, RES_1_IXd_A,
        RES_2_IXd_B, RES_2_IXd_C, RES_2_IXd_D, RES_2_IXd_E, RES_2_IXd_H, RES_2_IXd_L, RES_2_IXd, RES_2_IXd_A,
        RES_3_IXd_B, RES_3_IXd_C, RES_3_IXd_D, RES_3_IXd_E, RES_3_IXd_H, RES_3_IXd_L, RES_3_IXd, RES_3_IXd_A,
        RES_4_IXd_B, RES_4_IXd_C, RES_4_IXd_D, RES_4_IXd_E, RES_4_IXd_H, RES_4_IXd_L, RES_4_IXd, RES_4_IXd_A,
        RES_5_IXd_B, RES_5_IXd_C, RES_5_IXd_D, RES_5_IXd_E, RES_5_IXd_H, RES_5_IXd_L, RES_5_IXd, RES_5_IXd_A,
        RES_6_IXd_B, RES_6_IXd_C, RES_6_IXd_D, RES_6_IXd_E, RES_6_IXd_H, RES_6_IXd_L, RES_6_IXd, RES_6_IXd_A,
        RES_7_IXd_B, RES_7_IXd_C, RES_7_IXd_D, RES_7_IXd_E, RES_7_IXd_H, RES_7_IXd_L, RES_7_IXd, RES_7_IXd_A,

	SET_0_IXd_B, SET_0_IXd_C, SET_0_IXd_D, SET_0_IXd_E, SET_0_IXd_H, SET_0_IXd_L, SET_0_IXd, SET_0_IXd_A,
        SET_1_IXd_B, SET_1_IXd_C, SET_1_IXd_D, SET_1_IXd_E, SET_1_IXd_H, SET_1_IXd_L, SET_1_IXd, SET_1_IXd_A,
        SET_2_IXd_B, SET_2_IXd_C, SET_2_IXd_D, SET_2_IXd_E, SET_2_IXd_H, SET_2_IXd_L, SET_2_IXd, SET_2_IXd_A,
        SET_3_IXd_B, SET_3_IXd_C, SET_3_IXd_D, SET_3_IXd_E, SET_3_IXd_H, SET_3_IXd_L, SET_3_IXd, SET_3_IXd_A,
        SET_4_IXd_B, SET_4_IXd_C, SET_4_IXd_D, SET_4_IXd_E, SET_4_IXd_H, SET_4_IXd_L, SET_4_IXd, SET_4_IXd_A,
        SET_5_IXd_B, SET_5_IXd_C, SET_5_IXd_D, SET_5_IXd_E, SET_5_IXd_H, SET_5_IXd_L, SET_5_IXd, SET_5_IXd_A,
        SET_6_IXd_B, SET_6_IXd_C, SET_6_IXd_D, SET_6_IXd_E, SET_6_IXd_H, SET_6_IXd_L, SET_6_IXd, SET_6_IXd_A,
        SET_7_IXd_B, SET_7_IXd_C, SET_7_IXd_D, SET_7_IXd_E, SET_7_IXd_H, SET_7_IXd_L, SET_7_IXd, SET_7_IXd_A,
};

case RLC_IXd_B: M_I_RLC(IX, B);break;
case RLC_IXd_C: M_I_RLC(IX, C);break;
case RLC_IXd_D: M_I_RLC(IX, D);break;
case RLC_IXd_E: M_I_RLC(IX, E);break;
case RLC_IXd_H: M_I_RLC(IX, H);break;
case RLC_IXd_L: M_I_RLC(IX, L);break;
case RLC_IXd_A: M_I_RLC(IX, A);break;

case RLC_IXd:
   M_I_RLC(IX, p.b.h);
   break;

case RRC_IXd_B: M_I_RRC(IX, B);break;
case RRC_IXd_C: M_I_RRC(IX, C);break;
case RRC_IXd_D: M_I_RRC(IX, D);break;
case RRC_IXd_E: M_I_RRC(IX, E);break;
case RRC_IXd_H: M_I_RRC(IX, H);break;
case RRC_IXd_L: M_I_RRC(IX, L);break;
case RRC_IXd_A: M_I_RRC(IX, A);break;

case RRC_IXd:
   M_I_RRC(IX, p.b.h);
   break;

case RL_IXd_B: M_I_RL(IX, B);break;
case RL_IXd_C: M_I_RL(IX, C);break;
case RL_IXd_D: M_I_RL(IX, D);break;
case RL_IXd_E: M_I_RL(IX, E);break;
case RL_IXd_H: M_I_RL(IX, H);break;
case RL_IXd_L: M_I_RL(IX, L);break;
case RL_IXd_A: M_I_RL(IX, A);break;

case RL_IXd:
   M_I_RL(IX, p.b.h);
   break;

case RR_IXd_B: M_I_RR(IX, B);break;
case RR_IXd_C: M_I_RR(IX, C);break;
case RR_IXd_D: M_I_RR(IX, D);break;
case RR_IXd_E: M_I_RR(IX, E);break;
case RR_IXd_H: M_I_RR(IX, H);break;
case RR_IXd_L: M_I_RR(IX, L);break;
case RR_IXd_A: M_I_RR(IX, A);break;

case RR_IXd:
   M_I_RR(IX, p.b.h);
   break;

case SLA_IXd_B: M_I_SLA(IX, B);break;
case SLA_IXd_C: M_I_SLA(IX, C);break;
case SLA_IXd_D: M_I_SLA(IX, D);break;
case SLA_IXd_E: M_I_SLA(IX, E);break;
case SLA_IXd_H: M_I_SLA(IX, H);break;
case SLA_IXd_L: M_I_SLA(IX, L);break;
case SLA_IXd_A: M_I_SLA(IX, A);break;

case SLA_IXd:
   M_I_SLA(IX, p.b.h);
   break;

case SRA_IXd_B: M_I_SRA(IX, B);break;
case SRA_IXd_C: M_I_SRA(IX, C);break;
case SRA_IXd_D: M_I_SRA(IX, D);break;
case SRA_IXd_E: M_I_SRA(IX, E);break;
case SRA_IXd_H: M_I_SRA(IX, H);break;
case SRA_IXd_L: M_I_SRA(IX, L);break;
case SRA_IXd_A: M_I_SRA(IX, A);break;

case SRA_IXd:
   M_I_SRA(IX, p.b.h);
   break;

case SLL_IXd_B: M_I_SLL(IX, B);break;
case SLL_IXd_C: M_I_SLL(IX, C);break;
case SLL_IXd_D: M_I_SLL(IX, D);break;
case SLL_IXd_E: M_I_SLL(IX, E);break;
case SLL_IXd_H: M_I_SLL(IX, H);break;
case SLL_IXd_L: M_I_SLL(IX, L);break;
case SLL_IXd_A: M_I_SLL(IX, A);break;

case SLL_IXd:
   M_I_SLL(IX, p.b.h);
   break;

case SRL_IXd_B: M_I_SRL(IX, B);break;
case SRL_IXd_C: M_I_SRL(IX, B);break;
case SRL_IXd_D: M_I_SRL(IX, B);break;
case SRL_IXd_E: M_I_SRL(IX, B);break;
case SRL_IXd_H: M_I_SRL(IX, B);break;
case SRL_IXd_L: M_I_SRL(IX, B);break;
case SRL_IXd_A: M_I_SRL(IX, B);break;

case SRL_IXd:
   M_I_SRL(IX, p.b.h);
   break;

case BIT_0_IXd0:
case BIT_0_IXd1:
case BIT_0_IXd2:
case BIT_0_IXd3:
case BIT_0_IXd4:
case BIT_0_IXd5:
case BIT_0_IXd6:

case BIT_0_IXd:
   M_I_BIT(IX, 0);
   break;


case BIT_1_IXd0:
case BIT_1_IXd1:
case BIT_1_IXd2:
case BIT_1_IXd3:
case BIT_1_IXd4:
case BIT_1_IXd5:
case BIT_1_IXd6:
case BIT_1_IXd:
   M_I_BIT(IX, 1);
   break;

case BIT_2_IXd0:
case BIT_2_IXd1:
case BIT_2_IXd2:
case BIT_2_IXd3:
case BIT_2_IXd4:
case BIT_2_IXd5:
case BIT_2_IXd6:
case BIT_2_IXd:
   M_I_BIT(IX, 2);
   break;

case BIT_3_IXd0:
case BIT_3_IXd1:
case BIT_3_IXd2:
case BIT_3_IXd3:
case BIT_3_IXd4:
case BIT_3_IXd5:
case BIT_3_IXd6:
case BIT_3_IXd:
   M_I_BIT(IX, 3);
   break;

case BIT_4_IXd0:
case BIT_4_IXd1:
case BIT_4_IXd2:
case BIT_4_IXd3:
case BIT_4_IXd4:
case BIT_4_IXd5:
case BIT_4_IXd6:
case BIT_4_IXd:
   M_I_BIT(IX, 4);
   break;

case BIT_5_IXd0:
case BIT_5_IXd1:
case BIT_5_IXd2:
case BIT_5_IXd3:
case BIT_5_IXd4:
case BIT_5_IXd5:
case BIT_5_IXd6:
case BIT_5_IXd:
   M_I_BIT(IX, 5);
   break;

case BIT_6_IXd0:
case BIT_6_IXd1:
case BIT_6_IXd2:
case BIT_6_IXd3:
case BIT_6_IXd4:
case BIT_6_IXd5:
case BIT_6_IXd6:
case BIT_6_IXd:
   M_I_BIT(IX, 6);
   break;

case BIT_7_IXd0:
case BIT_7_IXd1:
case BIT_7_IXd2:
case BIT_7_IXd3:
case BIT_7_IXd4:
case BIT_7_IXd5:
case BIT_7_IXd6:
case BIT_7_IXd:
   M_I_BIT(IX, 7);
   break;

case RES_0_IXd_B: M_I_RES(IX, B, 0);break;
case RES_0_IXd_C: M_I_RES(IX, C, 0);break;
case RES_0_IXd_D: M_I_RES(IX, D, 0);break;
case RES_0_IXd_E: M_I_RES(IX, E, 0);break;
case RES_0_IXd_H: M_I_RES(IX, H, 0);break;
case RES_0_IXd_L: M_I_RES(IX, L, 0);break;
case RES_0_IXd_A: M_I_RES(IX, A, 0);break;

case RES_0_IXd:
   M_I_RES(IX, p.b.h, 0);
   break;


case RES_1_IXd_B: M_I_RES(IX, B, 1);break;
case RES_1_IXd_C: M_I_RES(IX, C, 1);break;
case RES_1_IXd_D: M_I_RES(IX, D, 1);break;
case RES_1_IXd_E: M_I_RES(IX, E, 1);break;
case RES_1_IXd_H: M_I_RES(IX, H, 1);break;
case RES_1_IXd_L: M_I_RES(IX, L, 1);break;
case RES_1_IXd_A: M_I_RES(IX, A, 1);break;

case RES_1_IXd:
   M_I_RES(IX, p.b.h, 1);
   break;

case RES_2_IXd_B: M_I_RES(IX, B, 2);break;
case RES_2_IXd_C: M_I_RES(IX, C, 2);break;
case RES_2_IXd_D: M_I_RES(IX, D, 2);break;
case RES_2_IXd_E: M_I_RES(IX, E, 2);break;
case RES_2_IXd_H: M_I_RES(IX, H, 2);break;
case RES_2_IXd_L: M_I_RES(IX, L, 2);break;
case RES_2_IXd_A: M_I_RES(IX, A, 2);break;

case RES_2_IXd:
   M_I_RES(IX, p.b.h, 2);
   break;

case RES_3_IXd_B: M_I_RES(IX, B, 3);break;
case RES_3_IXd_C: M_I_RES(IX, C, 3);break;
case RES_3_IXd_D: M_I_RES(IX, D, 3);break;
case RES_3_IXd_E: M_I_RES(IX, E, 3);break;
case RES_3_IXd_H: M_I_RES(IX, H, 3);break;
case RES_3_IXd_L: M_I_RES(IX, L, 3);break;
case RES_3_IXd_A: M_I_RES(IX, A, 3);break;

case RES_3_IXd:
   M_I_RES(IX, p.b.h, 3);
   break;

case RES_4_IXd_B: M_I_RES(IX, B, 4);break;
case RES_4_IXd_C: M_I_RES(IX, C, 4);break;
case RES_4_IXd_D: M_I_RES(IX, D, 4);break;
case RES_4_IXd_E: M_I_RES(IX, E, 4);break;
case RES_4_IXd_H: M_I_RES(IX, H, 4);break;
case RES_4_IXd_L: M_I_RES(IX, L, 4);break;
case RES_4_IXd_A: M_I_RES(IX, A, 4);break;

case RES_4_IXd:
   M_I_RES(IX, p.b.h, 4);
   break;

case RES_5_IXd_B: M_I_RES(IX, B, 5);break;
case RES_5_IXd_C: M_I_RES(IX, C, 5);break;
case RES_5_IXd_D: M_I_RES(IX, D, 5);break;
case RES_5_IXd_E: M_I_RES(IX, E, 5);break;
case RES_5_IXd_H: M_I_RES(IX, H, 5);break;
case RES_5_IXd_L: M_I_RES(IX, L, 5);break;
case RES_5_IXd_A: M_I_RES(IX, A, 5);break;

case RES_5_IXd:
   M_I_RES(IX, p.b.h, 5);
   break;

case RES_6_IXd_B: M_I_RES(IX, B, 6);break;
case RES_6_IXd_C: M_I_RES(IX, C, 6);break;
case RES_6_IXd_D: M_I_RES(IX, D, 6);break;
case RES_6_IXd_E: M_I_RES(IX, E, 6);break;
case RES_6_IXd_H: M_I_RES(IX, H, 6);break;
case RES_6_IXd_L: M_I_RES(IX, L, 6);break;
case RES_6_IXd_A: M_I_RES(IX, A, 6);break;

case RES_6_IXd:
   M_I_RES(IX, p.b.h, 6);
   break;

case RES_7_IXd_B: M_I_RES(IX, B, 7);break;
case RES_7_IXd_C: M_I_RES(IX, C, 7);break;
case RES_7_IXd_D: M_I_RES(IX, D, 7);break;
case RES_7_IXd_E: M_I_RES(IX, E, 7);break;
case RES_7_IXd_H: M_I_RES(IX, H, 7);break;
case RES_7_IXd_L: M_I_RES(IX, L, 7);break;
case RES_7_IXd_A: M_I_RES(IX, A, 7);break;

case RES_7_IXd:
   M_I_RES(IX, p.b.h, 7);
   break;

case SET_0_IXd_B: M_I_SET(IX, B, 0);break;
case SET_0_IXd_C: M_I_SET(IX, C, 0);break;
case SET_0_IXd_D: M_I_SET(IX, D, 0);break;
case SET_0_IXd_E: M_I_SET(IX, E, 0);break;
case SET_0_IXd_H: M_I_SET(IX, H, 0);break;
case SET_0_IXd_L: M_I_SET(IX, L, 0);break;
case SET_0_IXd_A: M_I_SET(IX, A, 0);break;

case SET_0_IXd:
   M_I_SET(IX, p.b.h, 0);
   break;


case SET_1_IXd_B: M_I_SET(IX, B, 1);break;
case SET_1_IXd_C: M_I_SET(IX, C, 1);break;
case SET_1_IXd_D: M_I_SET(IX, D, 1);break;
case SET_1_IXd_E: M_I_SET(IX, E, 1);break;
case SET_1_IXd_H: M_I_SET(IX, H, 1);break;
case SET_1_IXd_L: M_I_SET(IX, L, 1);break;
case SET_1_IXd_A: M_I_SET(IX, A, 1);break;

case SET_1_IXd:
   M_I_SET(IX, p.b.h, 1);
   break;

case SET_2_IXd_B: M_I_SET(IX, B, 2);break;
case SET_2_IXd_C: M_I_SET(IX, C, 2);break;
case SET_2_IXd_D: M_I_SET(IX, D, 2);break;
case SET_2_IXd_E: M_I_SET(IX, E, 2);break;
case SET_2_IXd_H: M_I_SET(IX, H, 2);break;
case SET_2_IXd_L: M_I_SET(IX, L, 2);break;
case SET_2_IXd_A: M_I_SET(IX, A, 2);break;

case SET_2_IXd:
   M_I_SET(IX, p.b.h, 2);
   break;

case SET_3_IXd_B: M_I_SET(IX, B, 3);break;
case SET_3_IXd_C: M_I_SET(IX, C, 3);break;
case SET_3_IXd_D: M_I_SET(IX, D, 3);break;
case SET_3_IXd_E: M_I_SET(IX, E, 3);break;
case SET_3_IXd_H: M_I_SET(IX, H, 3);break;
case SET_3_IXd_L: M_I_SET(IX, L, 3);break;
case SET_3_IXd_A: M_I_SET(IX, A, 3);break;

case SET_3_IXd:
   M_I_SET(IX, p.b.h, 3);
   break;

case SET_4_IXd_B: M_I_SET(IX, B, 4);break;
case SET_4_IXd_C: M_I_SET(IX, C, 4);break;
case SET_4_IXd_D: M_I_SET(IX, D, 4);break;
case SET_4_IXd_E: M_I_SET(IX, E, 4);break;
case SET_4_IXd_H: M_I_SET(IX, H, 4);break;
case SET_4_IXd_L: M_I_SET(IX, L, 4);break;
case SET_4_IXd_A: M_I_SET(IX, A, 4);break;

case SET_4_IXd:
   M_I_SET(IX, p.b.h, 4);
   break;

case SET_5_IXd_B: M_I_SET(IX, B, 5);break;
case SET_5_IXd_C: M_I_SET(IX, C, 5);break;
case SET_5_IXd_D: M_I_SET(IX, D, 5);break;
case SET_5_IXd_E: M_I_SET(IX, E, 5);break;
case SET_5_IXd_H: M_I_SET(IX, H, 5);break;
case SET_5_IXd_L: M_I_SET(IX, L, 5);break;
case SET_5_IXd_A: M_I_SET(IX, A, 5);break;

case SET_5_IXd:
   M_I_SET(IX, p.b.h, 5);
   break;

case SET_6_IXd_B: M_I_SET(IX, B, 6);break;
case SET_6_IXd_C: M_I_SET(IX, C, 6);break;
case SET_6_IXd_D: M_I_SET(IX, D, 6);break;
case SET_6_IXd_E: M_I_SET(IX, E, 6);break;
case SET_6_IXd_H: M_I_SET(IX, H, 6);break;
case SET_6_IXd_L: M_I_SET(IX, L, 6);break;
case SET_6_IXd_A: M_I_SET(IX, A, 6);break;

case SET_6_IXd:
   M_I_SET(IX, p.b.h, 6);
   break;

case SET_7_IXd_B: M_I_SET(IX, B, 7);break;
case SET_7_IXd_C: M_I_SET(IX, C, 7);break;
case SET_7_IXd_D: M_I_SET(IX, D, 7);break;
case SET_7_IXd_E: M_I_SET(IX, E, 7);break;
case SET_7_IXd_H: M_I_SET(IX, H, 7);break;
case SET_7_IXd_L: M_I_SET(IX, L, 7);break;
case SET_7_IXd_A: M_I_SET(IX, A, 7);break;

case SET_7_IXd:
   M_I_SET(IX, p.b.h, 7);
   break;
