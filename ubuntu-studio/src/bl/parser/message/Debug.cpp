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
#include "Debug.h"

#include <map>

#include "../../Define.h"

namespace Drumkit {
	namespace bl {
		namespace parser {
			namespace message {
				logging::Logger Debug::logger ("bl.parser.message.Debug");

				unsigned char Debug::nextSize() {
					if(isDone()) {
						return 0;
					}
					else if(index == 0) {
						return 1;
					}
					else {
						std::string type = format.fields[index - 1];

						if(type == DEBUG_TYPE_BOOL || type == DEBUG_TYPE_UCHAR) {
							return 1;
						}
						else if(type == DEBUG_TYPE_USINT) {
							return 2;
						}
						else {
							return 0;
						}
					}
				}
				void Debug::parseNext(char from[]) {
					if(! isDone()) {
						if(index == 0) {
							parseDefinition(from);
						}
						else {
							parseValue(from);
						}
					}
				}
				void Debug::parseDefinition(char from[]) {
					unsigned char id = 0;
					SerialParser::setBits(&id, from, 1);

					std::map<unsigned char, DebugFormat>::iterator iter = DebugFormat::all.find(id);

					if(iter != DebugFormat::all.end()) {
						format = iter->second;
						parsed = format.msg;
						index = 1;
					}
					else {
						error = true;
					}
				}
				void Debug::parseValue(char from[]) {
					std::string type = format.fields[index - 1];
					std::string value;

					if(type == DEBUG_TYPE_BOOL) {
						value = Debug::cBool(from);
					}
					else if(type == DEBUG_TYPE_UCHAR) {
						value = Debug::cUChar(from);
					}
					else if(type == DEBUG_TYPE_USINT) {
						value = Debug::cUSInt(from);
					}

					Debug::findAndReplaceAll(parsed, "{" + std::to_string(index - 1) + "}", value);
					index++;
				}
				bool Debug::isDone() {
					return (
						error ||
						(index > 0 && index > format.fields.size()));
				}
				void Debug::notify() {
					bool incomplete = (index > 0 && index <= format.fields.size() && ! error);

					std::string msg = "Debug: " +
						(index > 0 ?
							parsed : "") +
						(incomplete ?
							" > Incomplete." : "");

					if(! error && ! incomplete) {
						logger.info(msg);
					}
					else if(incomplete) {
						logger.warn(msg);
					}
					else {
						std::string inconsistency = "Unrecognized log message.";
						logger.error(msg + inconsistency);
					}
				}

				std::string Debug::cBool(char from[]) {
					bool value = false;
					SerialParser::setBits(&value, from, 1);
					return value ? "true" : "false";
				}
				std::string Debug::cUChar(char from[]) {
					unsigned char value = 0;
					SerialParser::setBits(&value, from, 1);
					return std::to_string((int) value);
				}
				std::string Debug::cUSInt(char from[]) {
					unsigned short int value = 0;
					SerialParser::setBits(&value, from, 2);
					return std::to_string(value);
				}
				// https://thispointer.com/find-and-replace-all-occurrences-of-a-sub-string-in-c/
				void Debug::findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr) {
					size_t pos = data.find(toSearch);

					while(pos != std::string::npos) {
						data.replace(pos, toSearch.size(), replaceStr);
						pos = data.find(toSearch, pos + replaceStr.size());
					}
				}

			} /* namespace message */
		} /* namespace parser */
	} /* namespace bl */
} /* namespace Drumkit */
