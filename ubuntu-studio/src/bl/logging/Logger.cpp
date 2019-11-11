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
#include "Logger.h"

#include <iostream>

#include "../Define.h"

namespace Drumkit {
	namespace bl {
		namespace logging {

			std::vector<LoggerListener*> Logger::listeners;
			std::queue<LogEntry> Logger::queue;
			std::mutex Logger::lock;

			Logger::Logger(std::string source) :
			source(source),
			dispatcher(new Glib::Dispatcher) {
				dispatcher->connect(sigc::ptr_fun(&Logger::notify));
			}
			Logger::~Logger() {
			}

			void Logger::info(std::string msg) {
				enqueue(LOG_INFO, msg);
			}
			void Logger::warn(std::string msg) {
				enqueue(LOG_WARN, msg);
			}
			void Logger::error(std::string msg) {
				enqueue(LOG_ERROR, msg);
			}
			void Logger::enqueue(unsigned char level, std::string msg) {
				Logger::lock.lock();
				Logger::queue.push({level, source, msg});
				Logger::lock.unlock();

				dispatcher->emit();
			}

			void Logger::notify() {
				if(! Logger::queue.empty()) {
					Logger::lock.lock();
					LogEntry logEntry = Logger::queue.front();
					Logger::queue.pop();
					Logger::lock.unlock();

					for(std::vector<LoggerListener*>::iterator i = listeners.begin(); i != listeners.end(); i++) {
						(*i)->logged(logEntry.level, logEntry.source, logEntry.msg);
					}
				}
			}

			void Logger::addListener(LoggerListener* listener) {
				listeners.push_back(listener);
			}

		} /* namespace logging */
	} /* namespace bl */
} /* namespace Drumkit */
