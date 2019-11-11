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
#include "SwitchSensor.h"

SwitchSensor::SwitchSensor(byte pin, bool triggerState) :
	Sensor(pin), triggerState(triggerState) {
}
SwitchSensor::SwitchSensor(byte pin, bool triggerState,
	unsigned short int throttlingMillis) :
	Sensor(pin, throttlingMillis),
	triggerState(triggerState) {
}
SwitchSensor::~SwitchSensor() {
}

void SwitchSensor::setup() {
	pinMode(getPin(), INPUT);
}
SensorReading SwitchSensor::read() {
	bool currentReading = digitalRead(getPin());
	unsigned long currentTime = millis();
	unsigned short int velocity = 0;

	if(! shouldThrottle(currentTime) &&
			currentReading == triggerState && currentReading != state) {
		setLastSentMillis(currentTime);
		velocity = 1;
	}

	state = currentReading;
	return SensorReading (velocity, 0);
}
bool SwitchSensor::inTriggerState() {
	return (state == triggerState);
}
