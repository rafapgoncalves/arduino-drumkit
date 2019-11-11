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
#include "SerialPort.h"

#include <linux/serial.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#include <sys/select.h>

namespace Drumkit {
	namespace bl {

		void SerialPort::open(std::string device, unsigned int baudRate) {
			if(! isOpen()) {
				int returnValue = 0;

				returnValue = ::open(device.c_str(), O_RDWR | O_NOCTTY);

				if(returnValue >= 0) {
					this->serial = returnValue;
					oldConfig = new termios;
					returnValue = tcgetattr(this->serial, oldConfig);
				}

				if(returnValue == 0) {
					termios newConfig;
					memset(&newConfig, 0, sizeof(newConfig));
					newConfig.c_cflag = SerialPort::convertBaudRate(baudRate) | CS8 | CLOCAL | CREAD;
					newConfig.c_iflag = IGNPAR;
					newConfig.c_oflag = 0;
					newConfig.c_lflag &= ~ICANON;
					newConfig.c_cc[VTIME] = 10;
					newConfig.c_cc[VMIN] = 0;

					tcflush(this->serial, TCIFLUSH);
					returnValue = tcsetattr(this->serial, TCSANOW, &newConfig);
				}

				if(returnValue < 0) {
					close();
				}
			}
		}
		void SerialPort::close() {
			if(isOpen()) {
				if(oldConfig != 0) {
					tcsetattr(serial, TCSANOW, oldConfig);
					delete oldConfig;
					oldConfig = 0;
				}
				::close(serial);
				serial = -1;
			}
		}
		int SerialPort::read(char * buffer, int bytes) {
			if(isOpen()) {
				return ::read(serial, buffer, bytes);
			}
			else {
				return -1;
			}
		}
		bool SerialPort::isOpen() {
			return serial != -1;
		}

		std::vector<std::string> SerialPort::list() {
			std::vector<std::string> list;

			for(const fs::directory_entry & entry : fs::directory_iterator("/dev")) {
				fs::path path = entry.path();
				if(path.filename().string().rfind("ttyUSB", 0) == 0) {
					list.push_back(path.string());
				}
			}

			return list;
		}
		int SerialPort::convertBaudRate(unsigned int baudRate) {
			switch (baudRate) {
				case 1200: return B1200;
				case 2400: return B2400;
				case 4800: return B4800;
				case 9600: return B9600;
				case 19200: return B19200;
				case 38400: return B38400;
				case 57600: return B57600;
				case 115200: return B115200;
				default: return -1;
			}
		}
	} /* namespace bl */
} /* namespace Drumkit */
