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
#ifndef SRC_BL_DEFINE_H_
#define SRC_BL_DEFINE_H_

#define NOTE_ON 144
#define NOTE_OFF 128
#define FIXED_MIDI_CHANNEL 9

#define MIN_NOTE 35
#define MAX_NOTE 81

#define MIN_VELOCITY 1
#define MAX_VELOCITY 127

#define DEBUG_COMMAND 112
#define DEBUG_TYPE_BOOL "Bool"
#define DEBUG_TYPE_UCHAR "UChar"
#define DEBUG_TYPE_USINT "USInt"

#define LOG_INFO 1
#define LOG_WARN 2
#define LOG_ERROR 3

#endif /* SRC_BL_DEFINE_H_ */
