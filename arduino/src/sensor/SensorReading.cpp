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
#include "SensorReading.h"

SensorReading::SensorReading(unsigned short int velocity, unsigned short int threshold) :
	velocity(velocity), threshold(threshold) {
}
SensorReading::~SensorReading() {
}

unsigned short int SensorReading::getVelocity() const {
	return velocity;
}
unsigned short int SensorReading::getThreshold() const {
	return threshold;
}
bool SensorReading::hasReadings() const {
	return (getVelocity() > 0);
}
