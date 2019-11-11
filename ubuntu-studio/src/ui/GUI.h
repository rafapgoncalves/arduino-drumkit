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
#ifndef SRC_UI_GUI_H_
#define SRC_UI_GUI_H_

#include <gtkmm/application.h>
#include <gtkmm/builder.h>
#include <gtkmm/window.h>

#include "SetupController.h"
#include "LogController.h"

namespace Drumkit {
	namespace ui {
		class GUI {
			private:
				Glib::RefPtr<Gtk::Application> gtkApp;
				Glib::RefPtr<Gtk::Builder> builder;

				Gtk::Window* window = 0;
				SetupController* setupCtrl = 0;
				LogController* logCtrl = 0;

			public:
				GUI(int argc, char **argv);
				virtual ~GUI();

			public:
				void show();
				void close();

			private:
				void openGlade();
				void createControllers();
				void initControllers();
		};
	} /* namespace ui */
} /* namespace Drumkit */

#endif /* SRC_UI_GUI_H_ */
