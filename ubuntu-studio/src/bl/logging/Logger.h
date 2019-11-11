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
#ifndef SRC_BL_LOGGING_LOGGER_H_
#define SRC_BL_LOGGING_LOGGER_H_

#include <string>
#include <vector>
#include <mutex>
#include <queue>
#include <glibmm.h>

#include "LoggerListener.h"
#include "LogEntry.h"

namespace Drumkit {
	namespace bl {
		namespace logging {

			class Logger {
				private:
					static std::vector<LoggerListener*> listeners;
					static std::queue<LogEntry> queue;
					static std::mutex lock;

					std::string source;
					Glib::Dispatcher* dispatcher;

				public:
					Logger(std::string source);
					virtual ~Logger();

				public:
					void info(std::string msg);
					void warn(std::string msg);
					void error(std::string msg);

				private:
					void enqueue(unsigned char level, std::string msg);

				private:
					static void notify();

				public:
					static void addListener(LoggerListener* listener);

			};

		} /* namespace logging */
	} /* namespace bl */
} /* namespace Drumkit */

#endif /* SRC_BL_LOGGING_LOGGER_H_ */
