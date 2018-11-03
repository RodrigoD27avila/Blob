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

#ifndef _Z80_H_INCLUDED_
#define _Z80_H_INCLUDED_

#include <cstdint>

class Device;

#define AFD af.d
#define AF  af.w.l
#define A   af.b.h
#define F   af.b.l

#define BCD bc.d
#define BC  bc.w.l
#define B   bc.b.h
#define C   bc.b.l

#define DED de.d
#define DE  de.w.l
#define D   de.b.h
#define E   de.b.l

#define HLD hl.d
#define HL  hl.w.l
#define H   hl.b.h
#define L   hl.b.l

#define SPD sp.d
#define SP  sp.w.l
#define SPH sp.b.h
#define SPL sp.b.l

#define PCD pc.d
#define PC  pc.w.l
#define PCH pc.b.h
#define PCL pc.b.l

#define IXD ix.d
#define IX  ix.w.l
#define IXH ix.b.h
#define IXL ix.b.l

#define IYD iy.d
#define IY  iy.w.l
#define IYH iy.b.h
#define IYL iy.b.l

#define _AF _af.w.l
#define _BC _bc.w.l
#define _DE _de.w.l
#define _HL _hl.w.l

#define CF 0x01 // Carry Flag
#define NF 0x02 // Subtract Flag
#define PF 0x04 // Parity Flag
#define VF PF   // Overflow Flag
#define XF 0x08
#define HF 0x10 // Half Carry Flag
#define YF 0x20
#define ZF 0x40 // Zero Flag
#define SF 0x80 // Sign Flag

#define IFF      this->iff
#define I        this->i
#define R        this->r

#define IFF_1    0x01 // IFF1
#define IFF_M1   0x02 // IM mode 1
#define IFF_M2   0x04 // IM mode 2
#define IFF_2    0x08 // IFF2
#define IFF_EI   0x20 // EI pending
#define IFF_HALT 0x80 // Halt

#define Z80_START_ADDRESS 0

class Z80 {

	// represent a register with 16 or 8 bits
	union PAIR {

		// bytes high and low
		struct {
			uint8_t l, h;
			uint16_t pad;
		} b;

		// words high and low
		struct {
			uint16_t l, h;
		} w;

		// signed bytes high and low
		struct {
			int8_t l, h;
			int16_t pad;
		} sb;

		// signed words high and low
		struct {
			int16_t l, h;
		} sw;

		// data 32 bit
		uint32_t d;

		// signed data 32 bit
		int32_t	sd;
	};

	// main register set
	PAIR  af,  bc,  de,  hl;

	// alternate register set
	PAIR _af, _bc, _de, _hl;

	// index registers
	PAIR ix, iy;

	// stack pointer register
	PAIR sp;

	// program counter register
	PAIR pc;

	// Interupt vector register / memory refresh register
	uint8_t i;
	uint8_t r;

	// Interrupt flip-flops
	uint8_t iff;

	// count cycles
	uint32_t icount;

	bool halt;

	bool quit;

	uint32_t jump_table[256];

	void Op  (uint8_t val);
	void OpCB(uint8_t val);
	void OpDD(uint8_t val);
	void OpED(uint8_t val);
	void OpFD(uint8_t val);
	void OpDDCB(uint8_t val, uint8_t h);
	void OpFDCB(uint8_t val, uint8_t h);

	void Jump(uint32_t addr);

	inline uint8_t  RdMem8(uint32_t addr);
	inline void     WrMem8(uint32_t addr, uint8_t val);

	inline uint8_t Input (uint32_t port);
	inline void    Output(uint32_t port, uint8_t val);

	void    IllegalOperation(uint8_t val);

	/* Devices */

	DEVICE *memory;
	DEVICE *io;
	DEVICE *ipc;

	char debug_asm[64];
	void ParseDebugString(uint32_t addr, const char **strings);

public:

	Z80(DEVICE *memory, DEVICE *io, DEVICE *ipc);
	~Z80();

	void Run();
	void Step(uint32_t steps);

	void Quit();

	const char *Debug(uint32_t addr);

	void Halt();
	void Reset();

	void SetProgramCounter(uint32_t addr) {
		PC = addr;
	}

	void SetStackPointer(uint32_t addr) {
		SP = addr;
	}

	DEVICE *MemoryDevice() {
		return memory;
	}

	void    MemoryDevice(DEVICE *memory) {
		this->memory = memory;
	}

	DEVICE *IODevice() {
		return io;
	}

	void    IODevice(DEVICE *io) {
		this->io = io;
	}

	DEVICE *IPCDevice() {
		return ipc;
	}

	void    IPCDevice(DEVICE *device) {
		this->ipc = ipc;
	}

	uint16_t GetPC() {
		return PC;
	}

	uint16_t GetSP() {
		return SP;
	}

	uint16_t GetAF() {
		return AF;
	}

	uint16_t GetBC() {
		return BC;
	}

	uint16_t GetDE() {
		return DE;
	}

	uint16_t GetHL() {
		return HL;
	}


	uint16_t Get_AF() {
		return _AF;
	}

	uint16_t Get_BC() {
		return _BC;
	}

	uint16_t Get_DE() {
		return _DE;
	}

	uint16_t Get_HL() {
		return _HL;
	}

	uint8_t GetFlags() {
		return F;
	}

	uint8_t GetI() {
		return I;
	}

	uint8_t GetR() {
		return R;
	}

	uint8_t GetIFF() {
		return IFF;
	}



};

#endif /* _Z80_H_INCLUDED_ */
