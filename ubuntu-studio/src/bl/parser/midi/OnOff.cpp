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
#include "OnOff.h"

#include <string>

#include "../../Define.h"

namespace Drumkit {
	namespace bl {
		namespace parser {
			namespace midi {

				bool OnOff::tryParseNext(unsigned char value) {
					if(getIndex() == 0) {
						command = value;
						return command == NOTE_ON || command == NOTE_OFF;

					}
					else if(getIndex() == 1) {
						note = value;
						return note >= MIN_NOTE && note <= MAX_NOTE;

					}
					else if(getIndex() == 2) {
						velocity = value;

						if(command == NOTE_ON) {
							return velocity >= MIN_VELOCITY && velocity <= MAX_VELOCITY;
						}
						else {
							return velocity == 0;
						}
					}

					return false;
				}
				void OnOff::setMidiEvent(snd_seq_event_t* event) {
					if(isDone() && ! hasError()) {
						if(command == NOTE_OFF) {
							snd_seq_ev_set_noteoff(event, FIXED_MIDI_CHANNEL, note, velocity);
						}
						else if(command == NOTE_ON) {
							snd_seq_ev_set_noteon(event, FIXED_MIDI_CHANNEL, note, velocity);
						}
					}
				}
				void OnOff::notify() {
					bool incomplete = (getIndex() < 3 && ! hasError());

					std::string midi =
						(getIndex() > 0 ?
							(command == NOTE_ON ? "MIDI: ON" : "MIDI: OFF") : "") +
						(getIndex() > 1 || (getIndex() == 1 && hasError()) ?
							" > " + std::to_string(note) : "") +
						(getIndex() > 2 || (getIndex() == 2 && hasError()) ?
							" > " + std::to_string(velocity) : "") +
						(incomplete ?
							" > Incomplete" : "");

					if(! hasError() && ! incomplete) {
						getLogger().info(midi);
					}
					else if(incomplete) {
						getLogger().warn(midi);
					}
					else {
						std::string inconsistency = "\n" +
							(getIndex() == 0 ?
								"Unrecognized command (" + std::to_string(command) + ")." +
								" Should be " + std::to_string(NOTE_ON) + " (ON) or " + std::to_string(NOTE_OFF) + " (OFF)." : "") +
							(getIndex() == 1 ?
								"Unexpected note (" + std::to_string(note) + ")." +
								" Should be between " + std::to_string(MIN_NOTE) + " and " + std::to_string(MAX_NOTE) + "." : "") +
							(getIndex() == 2 ?
								"Unexpected velocity (" + std::to_string(velocity) + ")." +
								(command == NOTE_ON ?
									" Should be between " + std::to_string(MIN_VELOCITY) + " and " + std::to_string(MAX_VELOCITY) + ".":
									" Should be 0.") : "");

						getLogger().error(midi + inconsistency);
					}
				}

				unsigned char OnOff::expectedSize() {
					return 3;
				}

			} /* namespace midi */
		} /* namespace parser */
	} /* namespace bl */
} /* namespace Drumkit */
