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
#include "PiezoSensor.h"

#include "../../Define.h"
#include "../debugger/Debugger.h"

PiezoSensor::PiezoSensor(byte pin, unsigned short int threshold) :
	Sensor(pin),
	threshold(threshold), higherThresholdMillis(PIEZO_HIGHER_THRESHOLD_MS), sampleMillis(PIEZO_SAMPLE_MS) {
}
PiezoSensor::PiezoSensor(byte pin, unsigned short int threshold,
	unsigned short int throttlingMillis, unsigned short int higherThresholdMillis, unsigned short int sampleMillis) :
	Sensor(pin, throttlingMillis),
	threshold(threshold), higherThresholdMillis(higherThresholdMillis), sampleMillis(sampleMillis) {
}
PiezoSensor::~PiezoSensor() {
}

SensorReading PiezoSensor::read() {
	unsigned short int finalVelocity = 0;
	unsigned long currentTime = millis();

	if(! shouldThrottle(currentTime)) {
		unsigned short int currentReading = analogRead(getPin());

		if(defeatsThreshold(currentReading, currentTime)) {
			acknowledgeReading(currentReading, currentTime);
		}
	}

	if(hasToSend(currentTime)) {
		finalVelocity = velocity;
		clear(currentTime);
	}

	return SensorReading(finalVelocity, threshold);
}
bool PiezoSensor::defeatsThreshold(unsigned short int currentReading, unsigned long currentTime) {
	bool inHigherThreshold = currentTime - getLastSentMillis() <= getThrottlingMillis() + higherThresholdMillis;
	unsigned short int finalThreshold = (inHigherThreshold ? (max(threshold, (lastSentVelocity / 3))) : threshold);

	if(currentReading > threshold) {
		byte pin = getPin();
		DEBUG4(LOG_THRESHOLD, pin, currentReading, inHigherThreshold, finalThreshold);
	}

	return (currentReading > finalThreshold);
}
void PiezoSensor::acknowledgeReading(unsigned short int currentReading, unsigned long currentTime) {
	bool newNote = false;
	if(!reading) {
		reading = true;
		readStartMillis = currentTime;
		newNote = true;
	}

	byte pin = getPin();
	DEBUG4(LOG_ACKNOWLEDGE, pin, currentReading, newNote, velocity);

	velocity = max(velocity, currentReading);
}
bool PiezoSensor::hasToSend(unsigned long currentTime) {
	return reading && currentTime - readStartMillis >= sampleMillis;
}
void PiezoSensor::clear(unsigned long currentTime) {
	setLastSentMillis(currentTime);
	lastSentVelocity = velocity;

	reading = false;
	velocity = 0;
}

unsigned short int PiezoSensor::getThreshold() {
	return threshold;
}
void PiezoSensor::setThreshold(unsigned short int threshold) {
	this->threshold = threshold;
}
