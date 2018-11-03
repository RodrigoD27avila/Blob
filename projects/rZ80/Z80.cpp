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

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>

#include "Z80.h"
#include "Z80Tables.h"
#include "Z80OpMacros.h"
#include "Z80Debug.h"
#include "DEVICE.h"

Z80::Z80(DEVICE *memory, DEVICE *io, DEVICE *ipc)
	: memory(memory), io(io), ipc(ipc)
{
	Reset();
	memset(debug_asm, 0, 64);
}

Z80::~Z80()
{
}

void Z80::Reset()
{
	AF=0;_AF=0;
	BC=0;_BC=0;
	DE=0;_DE=0;
	HL=0;_HL=0;
	IX=0;IY=0;
	SP=0;PC=0;
	I=0;R=0;
	IFF=0;

	quit=false;
	halt=false;
	icount = 0;
}

inline uint8_t Z80::RdMem8(uint32_t addr)
{
	return memory->Read8(addr);
}

inline void Z80::WrMem8(uint32_t addr, uint8_t val)
{
	memory->Write8(addr, val);
}

void Z80::Jump(uint32_t addr)
{
	int i;
	uint32_t tmp, curr = addr;

	for (i=0; i<256; i++) {
		tmp  = jump_table[i];
		jump_table[i] = curr;
		curr = tmp;
	}
}

inline uint8_t Z80::Input(uint32_t port)
{
	return io->Input(port);
}

inline void Z80::Output(uint32_t port, uint8_t val)
{
	io->Output(port, val);
}

void Z80::Run()
{
	while (!quit) {
		if (!halt) {
			uint8_t val = RdMem8(PC++);
			Op(val);
		} else {
			Op(0);
		}
	}
}

void Z80::Step(uint32_t steps)
{
	for (uint32_t i=0; i<steps; i++) {

		if (!halt) {
			uint8_t val = RdMem8(PC++);
			Op(val);
		} else {
			Op(0);
		}
	}

}

void Z80::Quit()
{ quit = true; }

void Z80::Halt()
{
#ifdef QUIT_ON_HALT
	quit = true;
#else
	halt = true;
#endif
}

void Z80::IllegalOperation(uint8_t val)
{
	(void)val;
	quit=true;
}

const char *Z80::Debug(uint32_t addr)
{
	uint8_t val = RdMem8(addr);
	switch (val) {
	case 0xcb:
		ParseDebugString(addr+1, TableOpCBDebug);
		break;
	case 0xde:
		ParseDebugString(addr+1, TableOpEDDebug);
		break;
	case 0xdd:
		ParseDebugString(addr+1, TableOpDDDebug);
		break;
	case 0xfd:
		ParseDebugString(addr+1, TableOpFDDebug);
		break;
	default:
		ParseDebugString(addr, TableOpDebug);
		break;

	}

	return debug_asm;
}

void Z80::ParseDebugString(uint32_t addr, const char **strings)
{
	uint8_t val        = RdMem8(addr);
	const char *string = strings[val];

	if (string == nullptr) {
		return;
	}

	if (string[0] == '0') {
		sprintf(debug_asm, string+1);
	}else {

		PAIR regs[2];
		regs[0].d = 0; regs[1].d = 0;

		const char *str = &string[1];
		for (int i=0; i<string[0]-'0'; i++) {
			if (str[i] == '2') {
				regs[i].b.l = RdMem8(addr+1);
			} else {
				regs[i].b.l = RdMem8(addr+1);
				regs[i].b.h = RdMem8(addr+2);
			}
		}

		if (string[0] == '1') {
			sprintf(debug_asm, string+2, regs[0].w.l);
		} else if (string[0] == 2) {
			sprintf(debug_asm, string+3, regs[0].w.l, regs[1].w.l);
		}
	}
}

void Z80::Op(uint8_t val)
{
	PAIR p;
	uint8_t v, b;

	icount-=CyclesOp[val];

	switch (val) {
	#include "Z80Op.h"
	default: IllegalOperation(val);
		break;
	}
}

void Z80::OpCB(uint8_t val)
{
	PAIR p;
	uint8_t v, b;

	icount-=CyclesOpCB[val];

	switch (val) {
	#include "Z80OpCB.h"
	default: IllegalOperation(val);
		break;
	}
}

void Z80::OpDD(uint8_t val)
{
	PAIR p;
	uint8_t v, b;

	icount-=CyclesOpI[val];

	switch (val) {
	#include "Z80OpDD.h"
	default: IllegalOperation(val);
		break;
	}
}

void Z80::OpDDCB(uint8_t val, uint8_t h)
{
	PAIR p;
	uint8_t v, b;

	icount-=CyclesOpCB[val];

	switch (val) {
	#include "Z80OpDDCB.h"
	default: IllegalOperation(val);
		break;
	}
}

void Z80::OpED(uint8_t val)
{
	PAIR p;
	uint8_t v, b;

	icount-=CyclesOpED[val];

	switch (val) {
	#include "Z80OpED.h"
	default: IllegalOperation(val);
		break;
	}
}

void Z80::OpFD(uint8_t val)
{
	PAIR p;
	uint8_t v, b;

	icount-=CyclesOpI[val];

	switch (val) {
	#include "Z80OpFD.h"
	default: IllegalOperation(val);
		break;
	}
}

void Z80::OpFDCB(uint8_t val, uint8_t h)
{
	PAIR p;
	uint8_t v, b;

	icount-=CyclesOpICB[val];

	switch (val) {
	#include "Z80OpFDCB.h"
	default: IllegalOperation(val);
		break;
	}
}

