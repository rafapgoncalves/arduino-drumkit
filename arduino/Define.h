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
#include <Arduino.h>

#ifndef DEFINE_H_
#define DEFINE_H_

#define BAUD_RATE 115200

#define DISABLE_DEBUG
#define DEBUG_COMMAND 112

// How much time to refuse consecutive notes
#define THROTTLING_MS 200
// How much time to read before decide velocity
#define PIEZO_SAMPLE_MS 20
// How much time to keep a higher threshold
#define PIEZO_HIGHER_THRESHOLD_MS 50


#define NOTE_ON 144
#define NOTE_OFF 128
#define MIN_VELOCITY 1
#define MAX_VELOCITY 127

#define LINEAR_VELOCITY_STEP 7

#define BASS_DRUM_PIN 2
#define BASS_DRUM_KEY 36
#define BASS_DRUM_FIXED_VELOCITY 75

#define FLOOR_TOM_PIN A7
#define FLOOR_TOM_KEY 41
#define FLOOR_TOM_THRESHOLD 35

#define SNARE_PIN A3
#define SNARE_KEY 38
#define SNARE_THRESHOLD 35

#define RACK_TOM_2_PIN A4
#define RACK_TOM_2_KEY 43
#define RACK_TOM_2_THRESHOLD 35

#define RACK_TOM_1_PIN A1
#define RACK_TOM_1_KEY 45
#define RACK_TOM_1_THRESHOLD 35

#define HI_HAT_PEDAL_PIN 3
#define HI_HAT_PEDAL_KEY 44
#define HI_HAT_PEDAL_FIXED_VELOCITY 75

#define HI_HAT_CYMBAL_PIN A2
#define HI_HAT_CYMBAL_CLOSED_KEY 42
#define HI_HAT_CYMBAL_OPEN_KEY 46
#define HI_HAT_CYMBAL_THRESHOLD 35

#define RIDE_CYMBAL_PIN A5
#define RIDE_CYMBAL_KEY 48
#define RIDE_CYMBAL_THRESHOLD 35

#define CRASH_CYMBAL_PIN A0
#define CRASH_CYMBAL_KEY 49
#define CRASH_CYMBAL_THRESHOLD 35

#define SPLASH_CYMBAL_PIN A6
#define SPLASH_CYMBAL_KEY 51
#define SPLASH_CYMBAL_THRESHOLD 35

// Constants
const int PRESSED = LOW;
const int RELEASED = HIGH;

#endif /* DEFINE_H_ */
