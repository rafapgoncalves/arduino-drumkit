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
#ifndef SRC_UI_LOGCONTROLLER_H_
#define SRC_UI_LOGCONTROLLER_H_

#include <string>
#include <gtkmm/builder.h>
#include <gtkmm/button.h>
#include <gtkmm/textbuffer.h>
#include <gtkmm/textview.h>

#include "../bl/AppStateListener.h"
#include "../bl/logging/LoggerListener.h"

namespace Drumkit {
	namespace ui {
		using namespace Drumkit::bl;

		class LogController : public logging::LoggerListener {
			private:
				Gtk::TextView* txtLog = 0;
				Glib::RefPtr<Gtk::TextBuffer> txtLogBuffer;
				Glib::RefPtr<Gtk::TextBuffer::Mark> mrkLogBufferEnd;

				Gtk::Button* btnClear = 0;

			public:
				LogController(Glib::RefPtr<Gtk::Builder> builder);
				virtual ~LogController();

			public:
				void init();

			private:
				void glade(Glib::RefPtr<Gtk::Builder> builder);

				void connect();
				void btnClearOnClick();

			public:
				virtual void logged(unsigned char level, std::string source, std::string msg) override;
		};

	} /* namespace ui */
} /* namespace Drumkit */

#endif /* SRC_UI_LOGCONTROLLER_H_ */
