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
#ifndef SRC_UI_SETUPCONTROLLER_H_
#define SRC_UI_SETUPCONTROLLER_H_

#include <gtkmm/builder.h>
#include <gtkmm/entry.h>
#include <gtkmm/combobox.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/checkbutton.h>

#include "../bl/App.h"
#include "../bl/AppStateListener.h"

namespace Drumkit {
	namespace ui {
		class SetupController : public Drumkit::bl::AppStateListener {
			private:
				Drumkit::bl::App* app;

				bool ignoreTxtNameSignal = false;
				bool ignoreCboDeviceSignal = false;

				Gtk::Entry* txtName = 0;
				Gtk::ComboBoxText* cboDevice = 0;
				Gtk::Button* btnRefreshDevice = 0;
				Gtk::ComboBoxText* cboBaudRate = 0;
				Gtk::Button* btnStartStop = 0;
				Gtk::Image* imgStart = 0;
				Gtk::Image* imgStop = 0;
				Gtk::CheckButton* chkDebug = 0;

			public:
				SetupController(Glib::RefPtr<Gtk::Builder> builder);
				virtual ~SetupController();

			public:
				void init();

			private:
				void glade(Glib::RefPtr<Gtk::Builder> builder);

				void connect();
				void populate();
				void refreshDevices();

				void txtNameOnChange();
				void cboDeviceOnChange();
				void btnRefreshDeviceOnClick();
				void btnStartStopOnClick();

				void setupOnChange();

			public:
				virtual void appStateOnChange(bool running) override;

		};
	} /* namespace ui */
} /* namespace Drumkit */

#endif /* SRC_UI_SETUPCONTROLLER_H_ */
