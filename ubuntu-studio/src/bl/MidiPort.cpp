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
#include "MidiPort.h"

#include <iostream>

/*
 * aseqdump -l
 * */

namespace Drumkit {
	namespace bl {
		MidiPort::~MidiPort() {
			close();
		}

		void MidiPort::open(std::string name) {
			if(this->seq == 0) {
				int returnValue = 0;
				int portId = -1;

				returnValue = snd_seq_open(&seq, "default", SND_SEQ_OPEN_DUPLEX, 0);
				if(returnValue == 0) returnValue = snd_seq_set_client_name(seq, name.c_str());
				if(returnValue == 0) portId = snd_seq_create_simple_port(seq, "MIDI out",
							SND_SEQ_PORT_CAP_READ | SND_SEQ_PORT_CAP_SUBS_READ, SND_SEQ_PORT_TYPE_APPLICATION);

				if(portId < 0) {
					close();
				}
				else {
					this->id = portId;
				}
			}
		}
		void MidiPort::close() {
			if(this->seq != 0) {
				snd_seq_delete_simple_port(seq, id);
				snd_seq_close(seq);
			}
			this->id = -1;
			this->seq = 0;
		}
		void MidiPort::sendMidi(parser::SerialParser* parser) {
			if(isOpen()) {
				snd_seq_event_t event;

				snd_seq_ev_clear(&event);
				snd_seq_ev_set_direct(&event);
				snd_seq_ev_set_source(&event, id);
				snd_seq_ev_set_subs(&event);

				parser->setMidiEvent(&event);

				snd_seq_event_output_direct(seq, &event);
				snd_seq_drain_output(seq);
			}
		}

		bool MidiPort::isOpen() {
			return (this->seq != 0);
		}

	} /* namespace bl */
} /* namespace Drumkit */
