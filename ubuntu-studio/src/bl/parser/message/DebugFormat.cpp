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
#include "DebugFormat.h"

#include "../../Define.h"

namespace Drumkit {
	namespace bl {
		namespace parser {
			namespace message {

				std::map<unsigned char, DebugFormat> DebugFormat::all = {
					{0x11, {"Piezo Sensor: Pin {0} is testing {1} against {3} (higher threshold {2})",
						{DEBUG_TYPE_UCHAR, DEBUG_TYPE_USINT, DEBUG_TYPE_BOOL, DEBUG_TYPE_USINT}}},

					{0x12, {"Piezo Sensor: Pin {0} recognizes sample {1} x {3} (new note {2})",
						{DEBUG_TYPE_UCHAR, DEBUG_TYPE_USINT, DEBUG_TYPE_BOOL, DEBUG_TYPE_USINT}}}
				};

			} /* namespace message */
		} /* namespace parser */
	} /* namespace bl */
} /* namespace Drumkit */
