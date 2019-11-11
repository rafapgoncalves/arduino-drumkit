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
#include "Sensor.h"

#include "../../Define.h"

Sensor::Sensor(byte pin) :
	Sensor(pin, THROTTLING_MS) {
}
Sensor::Sensor(byte pin, unsigned short int throttlingMillis) :
	pin(pin), throttlingMillis(throttlingMillis) {
}
Sensor::~Sensor() {
}

void Sensor::setup() {
}
bool Sensor::shouldThrottle(unsigned long currentTime) {
	return currentTime - lastSentMillis <= getThrottlingMillis();
}

byte Sensor::getPin() {
	return pin;
}
void Sensor::setPin(byte pin) {
	this->pin = pin;
}
unsigned short int Sensor::getThrottlingMillis() {
	return throttlingMillis;
}
void Sensor::setThrottlingMillis(unsigned short int throttlingMillis) {
	this->throttlingMillis = throttlingMillis;
}
unsigned long Sensor::getLastSentMillis() {
	return lastSentMillis;
}
void Sensor::setLastSentMillis(unsigned long lastSentMillis) {
	this->lastSentMillis = lastSentMillis;
}
