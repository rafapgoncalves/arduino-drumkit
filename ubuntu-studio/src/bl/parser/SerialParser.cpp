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
#include "SerialParser.h"

#include <cstring>
#include <bitset>

namespace Drumkit {
	namespace bl {
		namespace parser {
			char SerialParser::bigEndian = -1;

			SerialParser::~SerialParser() {
			}

			void SerialParser::setBits(void* to, char* from, unsigned char bytes) {
				// arduino is little endian

				for(int i = 0; i < bytes; i++) {
					char offset = isBigEndian() ? (bytes - 1 - i) : i;
					memset(static_cast<char*>(to) + offset, from[i], sizeof(char));
				}
			}

			bool SerialParser::isBigEndian() {
				if(bigEndian == -1) {
					int i = 1;
					bigEndian = ((*(char*)&i) == 0) ? 1 : 0;
				}
				return bigEndian == 1;
			}
		} /* namespace parser */
	} /* namespace bl */
} /* namespace Drumkit */
