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
#include "LinearVelocity.h"

#include "../../Define.h"

LinearVelocity::LinearVelocity() :
	LinearVelocity(LINEAR_VELOCITY_STEP) {
}
LinearVelocity::LinearVelocity(byte step) :
	step(step) {
}
LinearVelocity::~LinearVelocity() {
}

byte LinearVelocity::doConvert(SensorReading reading) {
	return (reading.getVelocity() - reading.getThreshold()) / step;
}
