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
#include "LogController.h"

#include <iostream>
#include <glibmm/ustring.h>

#include "../bl/Define.h"
#include "../bl/logging/Logger.h"

namespace Drumkit {
	namespace ui {

		LogController::LogController(Glib::RefPtr<Gtk::Builder> builder) {
			glade(builder);
		}
		LogController::~LogController() {
		}

		void LogController::glade(Glib::RefPtr<Gtk::Builder> builder) {
			builder->get_widget("txtLog", txtLog);
			builder->get_widget("btnClear", btnClear);

			if(txtLog == 0 ||
					btnClear == 0) {
				std::cerr << "Bad Glade File" << std::endl;
				throw 3;
			}

			txtLogBuffer = txtLog->get_buffer();
			mrkLogBufferEnd = txtLogBuffer->create_mark(txtLogBuffer->end(), false);

		}
		void LogController::init() {
			connect();
		}
		void LogController::connect() {
			Drumkit::bl::logging::Logger::addListener(this);

			btnClear->signal_clicked().connect(sigc::mem_fun(*this, &LogController::btnClearOnClick));
		}
		void LogController::btnClearOnClick() {
			txtLogBuffer->move_mark(mrkLogBufferEnd, txtLogBuffer->begin());
			txtLog->scroll_to(mrkLogBufferEnd, 0);
			Glib::ustring clean = "";
			txtLogBuffer->set_text(clean);
		}

		void LogController::logged(unsigned char level, std::string source, std::string msg) {
			std::string tag;

			if(level == LOG_ERROR) {
				tag = "error";
			}
			else if(level == LOG_WARN) {
				tag = "warning";
			}
			else if(source.rfind("bl.parser.message.", 0) == 0) {
				tag = "secondary";
			}
			else if(source.rfind("bl.parser.midi.", 0) == 0) {
				tag = "primary";
			}
			else {
				tag = "default";
			}

			txtLogBuffer->insert_with_tag(txtLogBuffer->end(), msg + "\n", tag);
			txtLogBuffer->move_mark(mrkLogBufferEnd, txtLogBuffer->end());
			txtLog->scroll_to(mrkLogBufferEnd, 0);
		}

	} /* namespace ui */
} /* namespace Drumkit */
