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
#include "DrumKit.h"

#include <Arduino.h>
#include "../../Define.h"

#include "DrumPad.h"
#include "HiHatPedalDrumPad.h"
#include "HiHatDrumPad.h"

#include "../sensor/PiezoSensor.h"
#include "../sensor/SwitchSensor.h"

#include "../midi/FixedVelocity.h"
#include "../midi/LinearVelocity.h"

DrumKit::DrumKit() {
	gateway = new MidiGateway ();
	totalPads = sizeof(pads) / sizeof(pads[0]);
	byte index = 0;

	pads[index++] = new DrumPad (BASS_DRUM_KEY,
									new SwitchSensor (BASS_DRUM_PIN, PRESSED),
									new FixedVelocity (BASS_DRUM_FIXED_VELOCITY));

	pads[index++] = new DrumPad (FLOOR_TOM_KEY,
									new PiezoSensor (FLOOR_TOM_PIN, FLOOR_TOM_THRESHOLD),
									new LinearVelocity ());

	pads[index++] = new DrumPad (SNARE_KEY,
									new PiezoSensor (SNARE_PIN, SNARE_THRESHOLD),
									new LinearVelocity ());

	pads[index++] = new DrumPad (RACK_TOM_2_KEY,
									new PiezoSensor (RACK_TOM_2_PIN, RACK_TOM_2_THRESHOLD),
									new LinearVelocity ());

	pads[index++] = new DrumPad (RACK_TOM_1_KEY,
									new PiezoSensor (RACK_TOM_1_PIN, RACK_TOM_1_THRESHOLD),
									new LinearVelocity ());

	HiHatPedalDrumPad* hiHatPedal = new HiHatPedalDrumPad (HI_HAT_PEDAL_KEY,
									new SwitchSensor (HI_HAT_PEDAL_PIN, RELEASED),
									new FixedVelocity (HI_HAT_PEDAL_FIXED_VELOCITY));
	pads[index++] = hiHatPedal;

	pads[index++] = new HiHatDrumPad (HI_HAT_CYMBAL_CLOSED_KEY, HI_HAT_CYMBAL_OPEN_KEY,
									new PiezoSensor (HI_HAT_CYMBAL_PIN, HI_HAT_CYMBAL_THRESHOLD),
									hiHatPedal,
									new LinearVelocity ());

	pads[index++] = new DrumPad (RIDE_CYMBAL_KEY,
									new PiezoSensor (RIDE_CYMBAL_PIN, RIDE_CYMBAL_THRESHOLD),
									new LinearVelocity ());

	pads[index++] = new DrumPad (CRASH_CYMBAL_KEY,
									new PiezoSensor (CRASH_CYMBAL_PIN, CRASH_CYMBAL_THRESHOLD),
									new LinearVelocity ());

	pads[index++] = new DrumPad (SPLASH_CYMBAL_KEY,
									new PiezoSensor (SPLASH_CYMBAL_PIN, SPLASH_CYMBAL_THRESHOLD),
									new LinearVelocity ());

	for(byte i = index; i < totalPads; i++) {
		pads[i] = 0;
	}
}
DrumKit::~DrumKit() {
	delete gateway;
	for(byte i = 0; i < totalPads; i++) {
		if(pads[i] != 0) {
			delete pads[i];
		}
	}
}

void DrumKit::setup() {
	for(byte i = 0; i < totalPads; i++) {
		if(pads[i] != 0) {
			pads[i]->setup();
		}
	}
}
void DrumKit::loop() {
	for(byte i = 0; i < totalPads; i++) {
		if(pads[i] != 0) {
			pads[i]->loop(gateway);
		}
	}
}
