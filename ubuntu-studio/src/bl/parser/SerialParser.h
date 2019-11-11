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
#ifndef SRC_BL_PARSER_SERIALPARSER_H_
#define SRC_BL_PARSER_SERIALPARSER_H_

#include <alsa/asoundlib.h>

namespace Drumkit {
	namespace bl {
		namespace parser {

			class SerialParser {
				private:
					static char bigEndian;

				public:
					virtual ~SerialParser();
					virtual unsigned char nextSize() = 0;
					virtual void parseNext(char from[]) = 0;
					virtual bool isDone() = 0;
					virtual bool hasMidiData() = 0;
					virtual void setMidiEvent(snd_seq_event_t* event) = 0;
					virtual void notify() = 0;

				public:
					static void setBits(void* to, char* from, unsigned char bytes);

				private:
					static bool isBigEndian();
			};

		} /* namespace parser */
	} /* namespace bl */
} /* namespace Drumkit */

#endif /* SRC_BL_PARSER_SERIALPARSER_H_ */
