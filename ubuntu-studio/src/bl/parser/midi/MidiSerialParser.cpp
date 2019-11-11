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
#include "MidiSerialParser.h"

#include "../../Define.h"
#include "OnOff.h"

namespace Drumkit {
	namespace bl {
		namespace parser {
			namespace midi {

				logging::Logger MidiSerialParser::logger ("bl.parser.midi.MidiSerialParser");

				unsigned char MidiSerialParser::nextSize() {
					return isDone() == true ? 0 : 1;
				}
				void MidiSerialParser::parseNext(char from[]) {
					unsigned char value = 0;
					SerialParser::setBits(&value, from, 1);
					parseNext(value);
				}
				void MidiSerialParser::parseNext(unsigned char from) {
					if(! isDone()) {
						error = ! tryParseNext(from);

						if(! error) {
							index++;
						}
					}
				}
				bool MidiSerialParser::isDone() {
					return index >= expectedSize() || error;
				}
				bool MidiSerialParser::hasMidiData() {
					return isDone() && ! error;
				}

				bool MidiSerialParser::hasError() {
					return error;
				}
				unsigned char MidiSerialParser::getIndex() {
					return index;
				}

				MidiSerialParser* MidiSerialParser::forType(unsigned char type) {
					if(type == NOTE_ON || type == NOTE_OFF) {
						MidiSerialParser* parser = new OnOff();
						parser->parseNext(type);
						return parser;
					}
					return 0;
				}
				logging::Logger MidiSerialParser::getLogger() {
					return logger;
				}

			} /* namespace midi */
		} /* namespace parser */
	} /* namespace bl */
} /* namespace Drumkit */
