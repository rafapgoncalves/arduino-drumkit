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
#ifndef SRC_SENSOR_PIEZOSENSOR_H_
#define SRC_SENSOR_PIEZOSENSOR_H_

#include "Sensor.h"

class PiezoSensor : public Sensor {
	private:
		static const byte LOG_SOURCE = 0x10;
		static const byte LOG_THRESHOLD = LOG_SOURCE + 0x01;
		static const byte LOG_ACKNOWLEDGE = LOG_SOURCE + 0x02;

		unsigned short int threshold;
		unsigned short int higherThresholdMillis;
		unsigned short int sampleMillis;
		bool reading = false;
		unsigned long readStartMillis = 0;
		unsigned short int velocity = 0;
		unsigned short int lastSentVelocity = 0;

	public:
		PiezoSensor(byte pin, unsigned short int threshold);
		PiezoSensor(byte pin, unsigned short int threshold,
				unsigned short int throttlingMillis, unsigned short int higherThresholdMillis, unsigned short int sampleMillis);
		virtual ~PiezoSensor();

	public:
		virtual SensorReading read();

	private:
		bool defeatsThreshold(unsigned short int currentReading, unsigned long currentTime);
		void acknowledgeReading(unsigned short int currentReading, unsigned long currentTime);
		bool hasToSend(unsigned long currentTime);
		void clear(unsigned long currentTime);

	public:
		virtual unsigned short int getThreshold();
		virtual void setThreshold(unsigned short int threshold);

};

#endif /* SRC_SENSOR_PIEZOSENSOR_H_ */
