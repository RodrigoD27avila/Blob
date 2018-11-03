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
	RLC_IYd_B, RLC_IYd_C, RLC_IYd_D, RLC_IYd_E, RLC_IYd_H, RLC_IYd_L, RLC_IYd, RLC_IYd_A,
	RRC_IYd_B, RRC_IYd_C, RRC_IYd_D, RRC_IYd_E, RRC_IYd_H, RRC_IYd_L, RRC_IYd, RRC_IYd_A,
	RL_IYd_B , RL_IYd_C , RL_IYd_D , RL_IYd_E , RL_IYd_H , RL_IYd_L , RL_IYd , RL_IYd_A ,
	RR_IYd_B , RR_IYd_C , RR_IYd_D , RR_IYd_E , RR_IYd_H , RR_IYd_L , RR_IYd , RR_IYd_A ,
	SLA_IYd_B, SLA_IYd_C, SLA_IYd_D, SLA_IYd_E, SLA_IYd_H, SLA_IYd_L, SLA_IYd, SLA_IYd_A,
	SRA_IYd_B, SRA_IYd_C, SRA_IYd_D, SRA_IYd_E, SRA_IYd_H, SRA_IYd_L, SRA_IYd, SRA_IYd_A,

	SLL_IYd_B, SLL_IYd_C, SLL_IYd_D, SLL_IYd_E, SLL_IYd_H, SLL_IYd_L, SLL_IYd, SLL_IYd_A,

	SRL_IYd_B, SRL_IYd_C, SRL_IYd_D, SRL_IYd_E, SRL_IYd_H, SRL_IYd_L, SRL_IYd, SRL_IYd_A,

	BIT_0_IYd0, BIT_0_IYd1, BIT_0_IYd2, BIT_0_IYd3, BIT_0_IYd4, BIT_0_IYd5, BIT_0_IYd, BIT_0_IYd6,
	BIT_1_IYd0, BIT_1_IYd1, BIT_1_IYd2, BIT_1_IYd3, BIT_1_IYd4, BIT_1_IYd5, BIT_1_IYd, BIT_1_IYd6,
	BIT_2_IYd0, BIT_2_IYd1, BIT_2_IYd2, BIT_2_IYd3, BIT_2_IYd4, BIT_2_IYd5, BIT_2_IYd, BIT_2_IYd6,
	BIT_3_IYd0, BIT_3_IYd1, BIT_3_IYd2, BIT_3_IYd3, BIT_3_IYd4, BIT_3_IYd5, BIT_3_IYd, BIT_3_IYd6,
	BIT_4_IYd0, BIT_4_IYd1, BIT_4_IYd2, BIT_4_IYd3, BIT_4_IYd4, BIT_4_IYd5, BIT_4_IYd, BIT_4_IYd6,
	BIT_5_IYd0, BIT_5_IYd1, BIT_5_IYd2, BIT_5_IYd3, BIT_5_IYd4, BIT_5_IYd5, BIT_5_IYd, BIT_5_IYd6,
	BIT_6_IYd0, BIT_6_IYd1, BIT_6_IYd2, BIT_6_IYd3, BIT_6_IYd4, BIT_6_IYd5, BIT_6_IYd, BIT_6_IYd6,
	BIT_7_IYd0, BIT_7_IYd1, BIT_7_IYd2, BIT_7_IYd3, BIT_7_IYd4, BIT_7_IYd5, BIT_7_IYd, BIT_7_IYd6,

        RES_0_IYd_B, RES_0_IYd_C, RES_0_IYd_D, RES_0_IYd_E, RES_0_IYd_H, RES_0_IYd_L, RES_0_IYd, RES_0_IYd_A,
        RES_1_IYd_B, RES_1_IYd_C, RES_1_IYd_D, RES_1_IYd_E, RES_1_IYd_H, RES_1_IYd_L, RES_1_IYd, RES_1_IYd_A,
        RES_2_IYd_B, RES_2_IYd_C, RES_2_IYd_D, RES_2_IYd_E, RES_2_IYd_H, RES_2_IYd_L, RES_2_IYd, RES_2_IYd_A,
        RES_3_IYd_B, RES_3_IYd_C, RES_3_IYd_D, RES_3_IYd_E, RES_3_IYd_H, RES_3_IYd_L, RES_3_IYd, RES_3_IYd_A,
        RES_4_IYd_B, RES_4_IYd_C, RES_4_IYd_D, RES_4_IYd_E, RES_4_IYd_H, RES_4_IYd_L, RES_4_IYd, RES_4_IYd_A,
        RES_5_IYd_B, RES_5_IYd_C, RES_5_IYd_D, RES_5_IYd_E, RES_5_IYd_H, RES_5_IYd_L, RES_5_IYd, RES_5_IYd_A,
        RES_6_IYd_B, RES_6_IYd_C, RES_6_IYd_D, RES_6_IYd_E, RES_6_IYd_H, RES_6_IYd_L, RES_6_IYd, RES_6_IYd_A,
        RES_7_IYd_B, RES_7_IYd_C, RES_7_IYd_D, RES_7_IYd_E, RES_7_IYd_H, RES_7_IYd_L, RES_7_IYd, RES_7_IYd_A,

	SET_0_IYd_B, SET_0_IYd_C, SET_0_IYd_D, SET_0_IYd_E, SET_0_IYd_H, SET_0_IYd_L, SET_0_IYd, SET_0_IYd_A,
        SET_1_IYd_B, SET_1_IYd_C, SET_1_IYd_D, SET_1_IYd_E, SET_1_IYd_H, SET_1_IYd_L, SET_1_IYd, SET_1_IYd_A,
        SET_2_IYd_B, SET_2_IYd_C, SET_2_IYd_D, SET_2_IYd_E, SET_2_IYd_H, SET_2_IYd_L, SET_2_IYd, SET_2_IYd_A,
        SET_3_IYd_B, SET_3_IYd_C, SET_3_IYd_D, SET_3_IYd_E, SET_3_IYd_H, SET_3_IYd_L, SET_3_IYd, SET_3_IYd_A,
        SET_4_IYd_B, SET_4_IYd_C, SET_4_IYd_D, SET_4_IYd_E, SET_4_IYd_H, SET_4_IYd_L, SET_4_IYd, SET_4_IYd_A,
        SET_5_IYd_B, SET_5_IYd_C, SET_5_IYd_D, SET_5_IYd_E, SET_5_IYd_H, SET_5_IYd_L, SET_5_IYd, SET_5_IYd_A,
        SET_6_IYd_B, SET_6_IYd_C, SET_6_IYd_D, SET_6_IYd_E, SET_6_IYd_H, SET_6_IYd_L, SET_6_IYd, SET_6_IYd_A,
        SET_7_IYd_B, SET_7_IYd_C, SET_7_IYd_D, SET_7_IYd_E, SET_7_IYd_H, SET_7_IYd_L, SET_7_IYd, SET_7_IYd_A,
};

case RLC_IYd_B: M_I_RLC(IY, B);break;
case RLC_IYd_C: M_I_RLC(IY, C);break;
case RLC_IYd_D: M_I_RLC(IY, D);break;
case RLC_IYd_E: M_I_RLC(IY, E);break;
case RLC_IYd_H: M_I_RLC(IY, H);break;
case RLC_IYd_L: M_I_RLC(IY, L);break;
case RLC_IYd_A: M_I_RLC(IY, A);break;

case RLC_IYd:
   M_I_RLC(IY, p.b.h);
   break;

case RRC_IYd_B: M_I_RRC(IY, B);break;
case RRC_IYd_C: M_I_RRC(IY, C);break;
case RRC_IYd_D: M_I_RRC(IY, D);break;
case RRC_IYd_E: M_I_RRC(IY, E);break;
case RRC_IYd_H: M_I_RRC(IY, H);break;
case RRC_IYd_L: M_I_RRC(IY, L);break;
case RRC_IYd_A: M_I_RRC(IY, A);break;

case RRC_IYd:
   M_I_RRC(IY, p.b.h);
   break;

case RL_IYd_B: M_I_RL(IY, B);break;
case RL_IYd_C: M_I_RL(IY, C);break;
case RL_IYd_D: M_I_RL(IY, D);break;
case RL_IYd_E: M_I_RL(IY, E);break;
case RL_IYd_H: M_I_RL(IY, H);break;
case RL_IYd_L: M_I_RL(IY, L);break;
case RL_IYd_A: M_I_RL(IY, A);break;

case RL_IYd:
   M_I_RL(IY, p.b.h);
   break;

case RR_IYd_B: M_I_RR(IY, B);break;
case RR_IYd_C: M_I_RR(IY, C);break;
case RR_IYd_D: M_I_RR(IY, D);break;
case RR_IYd_E: M_I_RR(IY, E);break;
case RR_IYd_H: M_I_RR(IY, H);break;
case RR_IYd_L: M_I_RR(IY, L);break;
case RR_IYd_A: M_I_RR(IY, A);break;

case RR_IYd:
   M_I_RR(IY, p.b.h);
   break;

case SLA_IYd_B: M_I_SLA(IY, B);break;
case SLA_IYd_C: M_I_SLA(IY, C);break;
case SLA_IYd_D: M_I_SLA(IY, D);break;
case SLA_IYd_E: M_I_SLA(IY, E);break;
case SLA_IYd_H: M_I_SLA(IY, H);break;
case SLA_IYd_L: M_I_SLA(IY, L);break;
case SLA_IYd_A: M_I_SLA(IY, A);break;

case SLA_IYd:
   M_I_SLA(IY, p.b.h);
   break;

case SRA_IYd_B: M_I_SRA(IY, B);break;
case SRA_IYd_C: M_I_SRA(IY, C);break;
case SRA_IYd_D: M_I_SRA(IY, D);break;
case SRA_IYd_E: M_I_SRA(IY, E);break;
case SRA_IYd_H: M_I_SRA(IY, H);break;
case SRA_IYd_L: M_I_SRA(IY, L);break;
case SRA_IYd_A: M_I_SRA(IY, A);break;

case SRA_IYd:
   M_I_SRA(IY, p.b.h);
   break;

case SLL_IYd_B: M_I_SLL(IY, B);break;
case SLL_IYd_C: M_I_SLL(IY, C);break;
case SLL_IYd_D: M_I_SLL(IY, D);break;
case SLL_IYd_E: M_I_SLL(IY, E);break;
case SLL_IYd_H: M_I_SLL(IY, H);break;
case SLL_IYd_L: M_I_SLL(IY, L);break;
case SLL_IYd_A: M_I_SLL(IY, A);break;

case SLL_IYd:
   M_I_SLL(IY, p.b.h);
   break;

case SRL_IYd_B: M_I_SRL(IY, B);break;
case SRL_IYd_C: M_I_SRL(IY, B);break;
case SRL_IYd_D: M_I_SRL(IY, B);break;
case SRL_IYd_E: M_I_SRL(IY, B);break;
case SRL_IYd_H: M_I_SRL(IY, B);break;
case SRL_IYd_L: M_I_SRL(IY, B);break;
case SRL_IYd_A: M_I_SRL(IY, B);break;

case SRL_IYd:
   M_I_SRL(IY, p.b.h);
   break;

case BIT_0_IYd0:
case BIT_0_IYd1:
case BIT_0_IYd2:
case BIT_0_IYd3:
case BIT_0_IYd4:
case BIT_0_IYd5:
case BIT_0_IYd6:

case BIT_0_IYd:
   M_I_BIT(IY, 0);
   break;


case BIT_1_IYd0:
case BIT_1_IYd1:
case BIT_1_IYd2:
case BIT_1_IYd3:
case BIT_1_IYd4:
case BIT_1_IYd5:
case BIT_1_IYd6:
case BIT_1_IYd:
   M_I_BIT(IY, 1);
   break;

case BIT_2_IYd0:
case BIT_2_IYd1:
case BIT_2_IYd2:
case BIT_2_IYd3:
case BIT_2_IYd4:
case BIT_2_IYd5:
case BIT_2_IYd6:
case BIT_2_IYd:
   M_I_BIT(IY, 2);
   break;

case BIT_3_IYd0:
case BIT_3_IYd1:
case BIT_3_IYd2:
case BIT_3_IYd3:
case BIT_3_IYd4:
case BIT_3_IYd5:
case BIT_3_IYd6:
case BIT_3_IYd:
   M_I_BIT(IY, 3);
   break;

case BIT_4_IYd0:
case BIT_4_IYd1:
case BIT_4_IYd2:
case BIT_4_IYd3:
case BIT_4_IYd4:
case BIT_4_IYd5:
case BIT_4_IYd6:
case BIT_4_IYd:
   M_I_BIT(IY, 4);
   break;

case BIT_5_IYd0:
case BIT_5_IYd1:
case BIT_5_IYd2:
case BIT_5_IYd3:
case BIT_5_IYd4:
case BIT_5_IYd5:
case BIT_5_IYd6:
case BIT_5_IYd:
   M_I_BIT(IY, 5);
   break;

case BIT_6_IYd0:
case BIT_6_IYd1:
case BIT_6_IYd2:
case BIT_6_IYd3:
case BIT_6_IYd4:
case BIT_6_IYd5:
case BIT_6_IYd6:
case BIT_6_IYd:
   M_I_BIT(IY, 6);
   break;

case BIT_7_IYd0:
case BIT_7_IYd1:
case BIT_7_IYd2:
case BIT_7_IYd3:
case BIT_7_IYd4:
case BIT_7_IYd5:
case BIT_7_IYd6:
case BIT_7_IYd:
   M_I_BIT(IY, 7);
   break;

case RES_0_IYd_B: M_I_RES(IY, B, 0);break;
case RES_0_IYd_C: M_I_RES(IY, C, 0);break;
case RES_0_IYd_D: M_I_RES(IY, D, 0);break;
case RES_0_IYd_E: M_I_RES(IY, E, 0);break;
case RES_0_IYd_H: M_I_RES(IY, H, 0);break;
case RES_0_IYd_L: M_I_RES(IY, L, 0);break;
case RES_0_IYd_A: M_I_RES(IY, A, 0);break;

case RES_0_IYd:
   M_I_RES(IY, p.b.h, 0);
   break;


case RES_1_IYd_B: M_I_RES(IY, B, 1);break;
case RES_1_IYd_C: M_I_RES(IY, C, 1);break;
case RES_1_IYd_D: M_I_RES(IY, D, 1);break;
case RES_1_IYd_E: M_I_RES(IY, E, 1);break;
case RES_1_IYd_H: M_I_RES(IY, H, 1);break;
case RES_1_IYd_L: M_I_RES(IY, L, 1);break;
case RES_1_IYd_A: M_I_RES(IY, A, 1);break;

case RES_1_IYd:
   M_I_RES(IY, p.b.h, 1);
   break;

case RES_2_IYd_B: M_I_RES(IY, B, 2);break;
case RES_2_IYd_C: M_I_RES(IY, C, 2);break;
case RES_2_IYd_D: M_I_RES(IY, D, 2);break;
case RES_2_IYd_E: M_I_RES(IY, E, 2);break;
case RES_2_IYd_H: M_I_RES(IY, H, 2);break;
case RES_2_IYd_L: M_I_RES(IY, L, 2);break;
case RES_2_IYd_A: M_I_RES(IY, A, 2);break;

case RES_2_IYd:
   M_I_RES(IY, p.b.h, 2);
   break;

case RES_3_IYd_B: M_I_RES(IY, B, 3);break;
case RES_3_IYd_C: M_I_RES(IY, C, 3);break;
case RES_3_IYd_D: M_I_RES(IY, D, 3);break;
case RES_3_IYd_E: M_I_RES(IY, E, 3);break;
case RES_3_IYd_H: M_I_RES(IY, H, 3);break;
case RES_3_IYd_L: M_I_RES(IY, L, 3);break;
case RES_3_IYd_A: M_I_RES(IY, A, 3);break;

case RES_3_IYd:
   M_I_RES(IY, p.b.h, 3);
   break;

case RES_4_IYd_B: M_I_RES(IY, B, 4);break;
case RES_4_IYd_C: M_I_RES(IY, C, 4);break;
case RES_4_IYd_D: M_I_RES(IY, D, 4);break;
case RES_4_IYd_E: M_I_RES(IY, E, 4);break;
case RES_4_IYd_H: M_I_RES(IY, H, 4);break;
case RES_4_IYd_L: M_I_RES(IY, L, 4);break;
case RES_4_IYd_A: M_I_RES(IY, A, 4);break;

case RES_4_IYd:
   M_I_RES(IY, p.b.h, 4);
   break;

case RES_5_IYd_B: M_I_RES(IY, B, 5);break;
case RES_5_IYd_C: M_I_RES(IY, C, 5);break;
case RES_5_IYd_D: M_I_RES(IY, D, 5);break;
case RES_5_IYd_E: M_I_RES(IY, E, 5);break;
case RES_5_IYd_H: M_I_RES(IY, H, 5);break;
case RES_5_IYd_L: M_I_RES(IY, L, 5);break;
case RES_5_IYd_A: M_I_RES(IY, A, 5);break;

case RES_5_IYd:
   M_I_RES(IY, p.b.h, 5);
   break;

case RES_6_IYd_B: M_I_RES(IY, B, 6);break;
case RES_6_IYd_C: M_I_RES(IY, C, 6);break;
case RES_6_IYd_D: M_I_RES(IY, D, 6);break;
case RES_6_IYd_E: M_I_RES(IY, E, 6);break;
case RES_6_IYd_H: M_I_RES(IY, H, 6);break;
case RES_6_IYd_L: M_I_RES(IY, L, 6);break;
case RES_6_IYd_A: M_I_RES(IY, A, 6);break;

case RES_6_IYd:
   M_I_RES(IY, p.b.h, 6);
   break;

case RES_7_IYd_B: M_I_RES(IY, B, 7);break;
case RES_7_IYd_C: M_I_RES(IY, C, 7);break;
case RES_7_IYd_D: M_I_RES(IY, D, 7);break;
case RES_7_IYd_E: M_I_RES(IY, E, 7);break;
case RES_7_IYd_H: M_I_RES(IY, H, 7);break;
case RES_7_IYd_L: M_I_RES(IY, L, 7);break;
case RES_7_IYd_A: M_I_RES(IY, A, 7);break;

case RES_7_IYd:
   M_I_RES(IY, p.b.h, 7);
   break;

case SET_0_IYd_B: M_I_SET(IY, B, 0);break;
case SET_0_IYd_C: M_I_SET(IY, C, 0);break;
case SET_0_IYd_D: M_I_SET(IY, D, 0);break;
case SET_0_IYd_E: M_I_SET(IY, E, 0);break;
case SET_0_IYd_H: M_I_SET(IY, H, 0);break;
case SET_0_IYd_L: M_I_SET(IY, L, 0);break;
case SET_0_IYd_A: M_I_SET(IY, A, 0);break;

case SET_0_IYd:
   M_I_SET(IY, p.b.h, 0);
   break;


case SET_1_IYd_B: M_I_SET(IY, B, 1);break;
case SET_1_IYd_C: M_I_SET(IY, C, 1);break;
case SET_1_IYd_D: M_I_SET(IY, D, 1);break;
case SET_1_IYd_E: M_I_SET(IY, E, 1);break;
case SET_1_IYd_H: M_I_SET(IY, H, 1);break;
case SET_1_IYd_L: M_I_SET(IY, L, 1);break;
case SET_1_IYd_A: M_I_SET(IY, A, 1);break;

case SET_1_IYd:
   M_I_SET(IY, p.b.h, 1);
   break;

case SET_2_IYd_B: M_I_SET(IY, B, 2);break;
case SET_2_IYd_C: M_I_SET(IY, C, 2);break;
case SET_2_IYd_D: M_I_SET(IY, D, 2);break;
case SET_2_IYd_E: M_I_SET(IY, E, 2);break;
case SET_2_IYd_H: M_I_SET(IY, H, 2);break;
case SET_2_IYd_L: M_I_SET(IY, L, 2);break;
case SET_2_IYd_A: M_I_SET(IY, A, 2);break;

case SET_2_IYd:
   M_I_SET(IY, p.b.h, 2);
   break;

case SET_3_IYd_B: M_I_SET(IY, B, 3);break;
case SET_3_IYd_C: M_I_SET(IY, C, 3);break;
case SET_3_IYd_D: M_I_SET(IY, D, 3);break;
case SET_3_IYd_E: M_I_SET(IY, E, 3);break;
case SET_3_IYd_H: M_I_SET(IY, H, 3);break;
case SET_3_IYd_L: M_I_SET(IY, L, 3);break;
case SET_3_IYd_A: M_I_SET(IY, A, 3);break;

case SET_3_IYd:
   M_I_SET(IY, p.b.h, 3);
   break;

case SET_4_IYd_B: M_I_SET(IY, B, 4);break;
case SET_4_IYd_C: M_I_SET(IY, C, 4);break;
case SET_4_IYd_D: M_I_SET(IY, D, 4);break;
case SET_4_IYd_E: M_I_SET(IY, E, 4);break;
case SET_4_IYd_H: M_I_SET(IY, H, 4);break;
case SET_4_IYd_L: M_I_SET(IY, L, 4);break;
case SET_4_IYd_A: M_I_SET(IY, A, 4);break;

case SET_4_IYd:
   M_I_SET(IY, p.b.h, 4);
   break;

case SET_5_IYd_B: M_I_SET(IY, B, 5);break;
case SET_5_IYd_C: M_I_SET(IY, C, 5);break;
case SET_5_IYd_D: M_I_SET(IY, D, 5);break;
case SET_5_IYd_E: M_I_SET(IY, E, 5);break;
case SET_5_IYd_H: M_I_SET(IY, H, 5);break;
case SET_5_IYd_L: M_I_SET(IY, L, 5);break;
case SET_5_IYd_A: M_I_SET(IY, A, 5);break;

case SET_5_IYd:
   M_I_SET(IY, p.b.h, 5);
   break;

case SET_6_IYd_B: M_I_SET(IY, B, 6);break;
case SET_6_IYd_C: M_I_SET(IY, C, 6);break;
case SET_6_IYd_D: M_I_SET(IY, D, 6);break;
case SET_6_IYd_E: M_I_SET(IY, E, 6);break;
case SET_6_IYd_H: M_I_SET(IY, H, 6);break;
case SET_6_IYd_L: M_I_SET(IY, L, 6);break;
case SET_6_IYd_A: M_I_SET(IY, A, 6);break;

case SET_6_IYd:
   M_I_SET(IY, p.b.h, 6);
   break;

case SET_7_IYd_B: M_I_SET(IY, B, 7);break;
case SET_7_IYd_C: M_I_SET(IY, C, 7);break;
case SET_7_IYd_D: M_I_SET(IY, D, 7);break;
case SET_7_IYd_E: M_I_SET(IY, E, 7);break;
case SET_7_IYd_H: M_I_SET(IY, H, 7);break;
case SET_7_IYd_L: M_I_SET(IY, L, 7);break;
case SET_7_IYd_A: M_I_SET(IY, A, 7);break;

case SET_7_IYd:
   M_I_SET(IY, p.b.h, 7);
   break;
