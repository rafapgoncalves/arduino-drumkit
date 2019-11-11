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
#ifndef SRC_DRUMS_DRUMKIT_H_
#define SRC_DRUMS_DRUMKIT_H_

#include "../midi/MidiGateway.h"
#include "DrumPad.h"

class DrumKit {
	private:
		MidiGateway* gateway;
		DrumPad* pads [10] = {};
		byte totalPads;

	public:
		DrumKit();
		virtual ~DrumKit();

	public:
		virtual void setup();
		virtual void loop();
};

#endif /* SRC_DRUMS_DRUMKIT_H_ */
