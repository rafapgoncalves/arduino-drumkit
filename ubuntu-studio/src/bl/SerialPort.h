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
#ifndef SRC_BL_SERIALPORT_H_
#define SRC_BL_SERIALPORT_H_

#include <vector>
#include <string>
#include <termios.h>

namespace Drumkit {
	namespace bl {
		class SerialPort {
			private:
				termios* oldConfig = 0;
				int serial = -1;

			public:
				void open(std::string device, unsigned int baudRate);
				void close();
				int read(char * buffer, int bytes);

			public:
				bool isOpen();

			public:
				static std::vector<std::string> list();

			private:
				static int convertBaudRate(unsigned int baudRate);
		};
	} /* namespace bl */
} /* namespace Drumkit */

#endif /* SRC_BL_SERIALPORT_H_ */
