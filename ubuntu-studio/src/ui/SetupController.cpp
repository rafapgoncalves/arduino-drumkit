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
#include "SetupController.h"

#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <glibmm/ustring.h>

#include "../bl/SerialPort.h"

namespace Drumkit {
	namespace ui {
		SetupController::SetupController(Glib::RefPtr<Gtk::Builder> builder) :
			app(Drumkit::bl::App::getInstance()){
			glade(builder);
		}
		SetupController::~SetupController() {
		}

		void SetupController::glade(Glib::RefPtr<Gtk::Builder> builder) {
			builder->get_widget("txtName", txtName);
			builder->get_widget("cboDevice", cboDevice);
			builder->get_widget("btnRefreshDevice", btnRefreshDevice);
			builder->get_widget("cboBaudRate", cboBaudRate);
			builder->get_widget("btnStartStop", btnStartStop);
			builder->get_widget("imgStart", imgStart);
			builder->get_widget("imgStop", imgStop);
			builder->get_widget("chkDebug", chkDebug);

			if(txtName == 0 ||
					cboDevice == 0 || btnRefreshDevice == 0 ||
					cboBaudRate == 0 ||
					btnStartStop == 0 || imgStart == 0 || imgStop == 0 ||
					chkDebug == 0) {
				std::cerr << "Bad Glade File" << std::endl;
				throw 3;
			}
		}
		void SetupController::init() {
			connect();
			populate();

			setupOnChange();
		}
		void SetupController::connect() {
			app->addStateListener(this);

			txtName->signal_changed().connect(sigc::mem_fun(*this, &SetupController::txtNameOnChange));
			cboDevice->signal_changed().connect(sigc::mem_fun(*this, &SetupController::cboDeviceOnChange));
			btnRefreshDevice->signal_clicked().connect(sigc::mem_fun(*this, &SetupController::btnRefreshDeviceOnClick));
			btnStartStop->signal_clicked().connect(sigc::mem_fun(*this, &SetupController::btnStartStopOnClick));
		}
		void SetupController::populate() {
			txtName->set_text("drumkit");

			refreshDevices();

			std::string baudRates [] = {"115200", "57600", "38400", "19200", "9600", "4800", "2400", "1200"};
			for(int i = 0; i < 8; i++) {
				cboBaudRate->append(baudRates[i]);
			}
			cboBaudRate->set_active(0);
		}
		void SetupController::refreshDevices() {
			std::vector<std::string> devices = Drumkit::bl::SerialPort::list();
			Glib::ustring selected = cboDevice->get_active_text();
			bool found = false;

			ignoreCboDeviceSignal = true;

			((Gtk::Entry*) cboDevice->get_children().front())->set_text("");
			cboDevice->remove_all();
			for(std::vector<std::string>::iterator i = devices.begin(); i != devices.end(); i++) {
				cboDevice->append(*i);

				if(*i == selected) {
					found = true;
					cboDevice->set_active(distance(devices.begin(), i));
				}
			}
			if(! found && devices.size() > 0) {
				cboDevice->set_active(0);
			}

			ignoreCboDeviceSignal = false;
		}

		void SetupController::txtNameOnChange() {
			if(! ignoreTxtNameSignal) {
				std::regex space(" ");
				std::regex invalid("[^A-Za-z0-9_-]");

				std::string input = txtName->get_text();

				std::string noSpace;
				std::regex_replace(std::back_inserter(noSpace), input.begin(), input.end(), space, "-");

				std::string noInvalid;
				std::regex_replace(std::back_inserter(noInvalid), noSpace.begin(), noSpace.end(), invalid, "");

				if(noInvalid != input) {
					int position = std::min(txtName->get_position(), (int) noInvalid.length());

					ignoreTxtNameSignal = true;
					txtName->set_text(noInvalid);
					txtName->set_position(position);
					ignoreTxtNameSignal = false;
				}

				setupOnChange();
			}
		}
		void SetupController::cboDeviceOnChange() {
			if(! ignoreCboDeviceSignal) {
				setupOnChange();
			}
		}
		void SetupController::btnRefreshDeviceOnClick() {
			refreshDevices();
			setupOnChange();
		}
		void SetupController::btnStartStopOnClick() {
			if(app->isRunning()) {
				app->stop();
			}
			else {
				app->start(txtName->get_text(), cboDevice->get_active_text(), std::stoul(cboBaudRate->get_active_text()), chkDebug->get_active());
			}
		}

		void SetupController::setupOnChange() {
			bool ready = false;

			if(
				txtName->get_text() != "" &&
				cboDevice->get_active_text() != ""
			) {
				ready = true;
			}

			btnStartStop->set_sensitive(ready);
		}

		void SetupController::appStateOnChange(bool running) {
			if(running) {
				txtName->set_sensitive(false);
				cboDevice->set_sensitive(false);
				btnRefreshDevice->set_sensitive(false);
				cboBaudRate->set_sensitive(false);
				btnStartStop->set_image(*imgStop);
				chkDebug->set_sensitive(false);
			}
			else {
				txtName->set_sensitive(true);
				cboDevice->set_sensitive(true);
				btnRefreshDevice->set_sensitive(true);
				cboBaudRate->set_sensitive(true);
				btnStartStop->set_image(*imgStart);
				chkDebug->set_sensitive(true);
			}
		}
	} /* namespace ui */
} /* namespace Drumkit */
