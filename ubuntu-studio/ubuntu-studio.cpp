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
#include <csignal>

#include "src/bl/App.h"
#include "src/ui/GUI.h"

Drumkit::ui::GUI* gui = 0;

void terminate() {
	if(gui != 0) {
		gui->close();
		delete gui;
	}
	Drumkit::bl::App::kill();
}

int main(int argc, char *argv[]) {
	int returnValue = 0;

	try {
		sighandler_t signalHandler = [](int sig) {
			terminate();
		};
		signal(SIGINT, signalHandler);
		signal(SIGKILL, signalHandler);
		signal(SIGTERM, signalHandler);

		Drumkit::bl::App::getInstance();
		gui = new Drumkit::ui::GUI(argc, argv);
		gui->show();
	}
	catch(int error) {
		returnValue = error;
	}
	catch(...) {
		returnValue = -1;
	}

	terminate();
	return returnValue;
}
