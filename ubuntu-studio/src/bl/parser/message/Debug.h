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
#ifndef SRC_BL_PARSER_MESSAGE_DEBUG_H_
#define SRC_BL_PARSER_MESSAGE_DEBUG_H_

#include "MessageSerialParser.h"
#include "../../logging/Logger.h"
#include "DebugFormat.h"

namespace Drumkit {
	namespace bl {
		namespace parser {
			namespace message {

				class Debug : public MessageSerialParser {
					private:
						unsigned char index = 0;
						bool error = false;
						DebugFormat format;
						std::string parsed;

						static logging::Logger logger;

					public:
						virtual unsigned char nextSize() override;
						virtual void parseNext(char from[]) override;
						virtual bool isDone() override;
						virtual void notify() override;

					private:
						void parseDefinition(char from[]);
						void parseValue(char from[]);

						static std::string cBool(char from[]);
						static std::string cUChar(char from[]);
						static std::string cUSInt(char from[]);
						static void findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr);
				};

			} /* namespace message */
		} /* namespace parser */
	} /* namespace bl */
} /* namespace Drumkit */

#endif /* SRC_BL_PARSER_MESSAGE_DEBUG_H_ */
