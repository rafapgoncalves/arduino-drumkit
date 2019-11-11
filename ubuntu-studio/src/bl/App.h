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
#ifndef SRC_BL_APP_H_
#define SRC_BL_APP_H_

#include <string>
#include <vector>
#include <thread>

#include "AppStateListener.h"
#include "MidiPort.h"
#include "SerialPort.h"
#include "parser/SerialParser.h"
#include "logging/Logger.h"

namespace Drumkit {
	namespace bl {
		class App {
			private:
				static App* instance;
				static logging::Logger logger;

				bool running = false;
				std::vector<AppStateListener*> stateListeners;
				MidiPort* midiPort;
				SerialPort* serialPort;
				std::thread* thread = 0;

			private:
				App();
				virtual ~App();

			public:
				void addStateListener(AppStateListener* listener);
				void start(std::string name, std::string device, unsigned int baudRate, bool debugOnly);
				void stop();

			private:
				void notifyStateChange();
				void run();

			public:
				bool isRunning();

			public:
				static void kill();
				static App* getInstance();

		};
	} /* namespace bl */
} /* namespace Drumkit */
#endif /* SRC_BL_APP_H_ */
