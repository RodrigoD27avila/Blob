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

#ifndef _DEVICE_H_INCLUDED_
#define _DEVICE_H_INCLUDED_

class DEVICE {
public:
	virtual uint8_t Read8(uint32_t addr) {
		return 0;
	}

	virtual void Write8(uint32_t addr, uint8_t val){
	}

	virtual uint8_t Input (uint32_t port) {
		return 0;
	}

	virtual void Output(uint32_t port, uint8_t val) {
	}
};

#endif // _DEVICE_H_INCLUDED_
