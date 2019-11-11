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
#ifndef SRC_DEBUGGING_DEBUGGER_H_
#define SRC_DEBUGGING_DEBUGGER_H_

#include <Arduino.h>

#define DEBUG(source, a1) Debugger::debug(source, (byte*) &a1, sizeof(a1))
#define DEBUG2(source, a1, a2) Debugger::debug(source, (byte*) &a1, sizeof(a1), (byte*) &a2, sizeof(a2))
#define DEBUG3(source, a1, a2, a3) Debugger::debug(source, (byte*) &a1, sizeof(a1), (byte*) &a2, sizeof(a2), (byte*) &a3, sizeof(a3))
#define DEBUG4(source, a1, a2, a3, a4) Debugger::debug(source, (byte*) &a1, sizeof(a1), (byte*) &a2, sizeof(a2), (byte*) &a3, sizeof(a3), (byte*) &a4, sizeof(a4))

class Debugger {
	public:
		static void debug(byte source, byte* value, unsigned int size);
		static void debug(byte source, byte* value1, unsigned int size1, byte* value2, unsigned int size2);
		static void debug(byte source, byte* value1, unsigned int size1, byte* value2, unsigned int size2, byte* value3, unsigned int size3);
		static void debug(byte source, byte* value1, unsigned int size1, byte* value2, unsigned int size2, byte* value3, unsigned int size3,
				byte* value4, unsigned int size4);
};

#endif /* SRC_DEBUGGING_DEBUGGER_H_ */
