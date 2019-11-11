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
#include "App.h"

#include <iostream>
#include <string>

#include "parser/ParserFactory.h"

namespace Drumkit {
	namespace bl {
		using namespace parser;

		App* App::instance = 0;
		logging::Logger App::logger("bl.App");

		App::App() :
			midiPort(new MidiPort()),
			serialPort(new SerialPort()) {
		}
		App::~App() {
			App::instance = 0;
		}

		void App::addStateListener(AppStateListener* listener) {
			stateListeners.push_back(listener);
		}
		void App::start(std::string name, std::string device, unsigned int baudRate, bool debugOnly) {
			if(! running) {
				running = true;
				bool ok;

				App::logger.info("Starting - Name: " + name + "; Device: " + device + "; Baud Rate: " + std::to_string(baudRate) +
						"; Debug: " + (debugOnly ? "true" : "false") + ";");

				serialPort->open(device, baudRate);
				ok = serialPort->isOpen();

				if(ok && ! debugOnly) {
					midiPort->open(name);
					ok = midiPort->isOpen();
				}

				if(ok) {
					thread = new std::thread(&App::run, this);
					notifyStateChange();
				}
				else {
					App::logger.error("Unexpected error.");
					stop();
				}
			}
		}
		void App::stop() {
			if(running) {
				running = false;

				App::logger.info("Stopping...");

				if(thread != 0) {
					thread->join();
					delete thread;
					thread = 0;
				}

				midiPort->close();
				serialPort->close();

				App::logger.info("Stopped.");
				notifyStateChange();
			}
		}
		void App::notifyStateChange() {
			for(std::vector<AppStateListener*>::iterator i = stateListeners.begin(); i != stateListeners.end(); i++) {
				(*i)->appStateOnChange(running);
			}
		}
		void App::run() {
			SerialParser* parser = 0;
			char buffer[12] = {};
			int bytesCarriedOver = 0;
			bool errorReadingParsing = false;

			while(running) {
				errorReadingParsing = false;

				try {
					int bytesToRead = ((parser == 0) ? 1 : parser->nextSize()) - bytesCarriedOver;
					int bytesRead = serialPort->read(&buffer[bytesCarriedOver], bytesToRead);

					if(bytesRead == bytesToRead) {
						if(parser == 0) {
							unsigned char parserType;
							SerialParser::setBits(&parserType, buffer, 1);
							parser = ParserFactory::forType(parserType);
						}
						else {
							parser->parseNext(buffer);
						}
						bytesCarriedOver = 0;
					}
					else if(bytesRead > 0) {
						bytesCarriedOver += bytesRead;
					}
				}
				catch(...) {
					App::logger.error("Unexpected error reading/parsing serial data.");
					errorReadingParsing = true;
				}

				if((parser != 0 && parser->isDone()) || errorReadingParsing) {
					try {
						if(parser->hasMidiData()) {
							midiPort->sendMidi(parser);
						}
					}
					catch(...) {
						App::logger.error("Unexpected error sending event to alsa.");
					}

					parser->notify();

					delete parser;
					parser = 0;
				}
			}

			if(parser != 0) {
				delete parser;
			}
		}

		bool App::isRunning() {
			return running;
		}

		void App::kill() {
			if(App::instance != 0) {
				delete App::instance;
			}
		}
		App* App::getInstance() {
			if(App::instance == 0) {
				App::instance = new App();
			}
			return App::instance;
		}


	} /* namespace bl */
} /* namespace Drumkit */
