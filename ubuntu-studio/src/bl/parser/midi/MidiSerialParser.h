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
#ifndef SRC_BL_PARSER_MIDI_MIDISERIALPARSER_H_
#define SRC_BL_PARSER_MIDI_MIDISERIALPARSER_H_

#include "../SerialParser.h"
#include "../../logging/Logger.h"

namespace Drumkit {
	namespace bl {
		namespace parser {
			namespace midi {

				class MidiSerialParser : public SerialParser {
					private:
						unsigned char index = 0;
						bool error = false;

						static logging::Logger logger;

					public:
						virtual unsigned char nextSize() override;
						virtual void parseNext(char from[]) override;
						virtual bool isDone() override;
						virtual bool hasMidiData() override;

					private:
						void parseNext(unsigned char from);

					protected:
						virtual unsigned char expectedSize() = 0;
						virtual bool tryParseNext(unsigned char value) = 0;

					protected:
						bool hasError();
						unsigned char getIndex();

					public:
						static MidiSerialParser* forType(unsigned char type);

					protected:
						static logging::Logger getLogger();
				};

			} /* namespace midi */
		} /* namespace parser */
	} /* namespace bl */
} /* namespace Drumkit */

#endif /* SRC_BL_PARSER_MIDI_MIDISERIALPARSER_H_ */
