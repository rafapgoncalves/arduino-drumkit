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
#ifndef SRC_BL_MIDIPORT_H_
#define SRC_BL_MIDIPORT_H_

#include <string>
#include <alsa/asoundlib.h>

#include "parser/SerialParser.h"

namespace Drumkit {
	namespace bl {
		class MidiPort {
			private:
				snd_seq_t* seq = 0;
				int id = -1;

			public:
				virtual ~MidiPort();

			public:
				void open(std::string name);
				void close();
				void sendMidi(parser::SerialParser* parser);

			public:
				bool isOpen();
		};
	} /* namespace bl */
} /* namespace Drumkit */
#endif /* SRC_BL_MIDIPORT_H_ */