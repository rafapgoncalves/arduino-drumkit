/*
Copyright (c) 2019 rafapgoncalves.

This file is part of arduino-drumkit
(see https://github.com/rafapgoncalves/arduino-drumkit).

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
#include "Debugger.h"

#include "../../Define.h"
#include "../io/SerialPort.h"

static void Debugger::debug(byte source, byte* value, unsigned int size) {
	Debugger::debug(source, value, size, 0, 0, 0, 0, 0, 0);
}
static void Debugger::debug(byte source, byte* value1, unsigned int size1, byte* value2, unsigned int size2) {
	Debugger::debug(source, value1, size1, value2, size2, 0, 0, 0, 0);
}
static void Debugger::debug(byte source, byte* value1, unsigned int size1, byte* value2, unsigned int size2, byte* value3, unsigned int size3) {
	Debugger::debug(source, value1, size1, value2, size2, value3, size3, 0, 0);
}
static void Debugger::debug(byte source, byte* value1, unsigned int size1, byte* value2, unsigned int size2, byte* value3, unsigned int size3,
		byte* value4, unsigned int size4) {

	#ifndef DISABLE_DEBUG
		byte* values [] = {value1, value2, value3, value4};
		unsigned int sizes [] = {size1, size2, size3, size4};

		byte command [2] = {DEBUG_COMMAND, source};
		SerialPort::send(command, 2);

		for(byte iv = 0; iv < 4; iv++) {
			if(values[iv] != 0 && sizes[iv] > 0) {
				byte buffer [sizes[iv]] = {};
				for(byte is = 0; is < sizes[iv]; is++) {
					buffer[is] = values[iv][is];
				}
				SerialPort::send(buffer, sizes[iv]);
			}
		}
	#endif
}
