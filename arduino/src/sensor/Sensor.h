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
#ifndef SRC_SENSOR_SENSOR_H_
#define SRC_SENSOR_SENSOR_H_

#include <Arduino.h>

#include "SensorReading.h"

class Sensor {
	private:
		byte pin;
		unsigned short int throttlingMillis;
		unsigned long lastSentMillis = 0;

	public:
		Sensor(byte pin);
		Sensor(byte pin, unsigned short int throttlingMillis);
		virtual ~Sensor() = 0;

	public:
		virtual void setup();
		virtual SensorReading read() = 0;

	protected:
		virtual bool shouldThrottle(unsigned long currentTime);

	public:
		virtual byte getPin();
		virtual void setPin(byte pin);
		virtual unsigned short int getThrottlingMillis();
		virtual void setThrottlingMillis(unsigned short int throttlingMillis);

	protected:
		virtual unsigned long getLastSentMillis();
		virtual void setLastSentMillis(unsigned long lastSentMillis);

};

#endif /* SRC_SENSOR_SENSOR_H_ */
