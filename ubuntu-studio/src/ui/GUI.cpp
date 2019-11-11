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
#include "GUI.h"

#include <iostream>

namespace Drumkit {
	namespace ui {
		GUI::GUI(int argc, char **argv) :
				gtkApp(Gtk::Application::create(argc, argv, "com.rafapgoncalves.drumkit")),
				builder(Gtk::Builder::create()) {
			openGlade();
			createControllers();
			initControllers();
		}
		GUI::~GUI() {
			delete setupCtrl;
			delete logCtrl;
		}

		void GUI::openGlade() {
			try {
				builder->add_from_file("glade/main.glade");
				builder->get_widget("pnlMain", window);
			}
			catch(const Glib::FileError& ex) {
				std::cerr << "FileError: " << ex.what() << std::endl;
				throw 1;
			}
			catch(const Gtk::BuilderError& ex) {
				std::cerr << "BuilderError: " << ex.what() << std::endl;
				throw 2;
			}
		}
		void GUI::createControllers() {
			setupCtrl = new SetupController(builder);
			logCtrl = new LogController(builder);
		}
		void GUI::initControllers() {
			setupCtrl->init();
			logCtrl->init();
		}

		void GUI::show() {
			gtkApp->run(*window);
		}
		void GUI::close() {
			if(window->is_visible()) {
				window->hide();
			}
		}

	} /* namespace ui */
} /* namespace Drumkit */
