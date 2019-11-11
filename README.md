# arduino-drumkit

An Arduino Nano USB drumkit to play with, but not limited to, [Ubuntu Studio](https://ubuntustudio.org/) 18.04 and [Hydrogen](http://hydrogen-music.org/) 0.9.7.

## Getting Started

1. Download and install Eclipse C/C++. More on that [here](https://www.eclipse.org/community/eclipse_newsletter/2017/april/article4.php);
2. Clone the repository;
3. Open eclipse and create a new workspace;
4. Go to File -> Import -> General -> Existing projects into workspace;
    - Select arduino-drumkit folder and check "Search for nested projects";
    - Make sure all projects are selected and click Finish.

### Arduino

First thing to do is to adjust the code to your arduino's version. Open [arduino/src/drums/Drumkit.cpp](/arduino/src/drums/Drumkit.cpp). 
At the Drumkit constructor you will find the declaration of the sensors (`SwitchSensor` for pull-up switches and `PiezoSensor` for piezos) and keys ([instructions](/KEYS.md)) for each drum pad.

Since I'm using Arduino Nano, the project is set up with 2 switches (one for bass drum and the other for hi-hat pedal) and 8 piezos.

You can change most of the parameters in [arduino/src/Define.h](/arduino/src/Define.h).

#### General MIDI

A few adjustments may be necessary to use it as a GM-compatible instrument:

* Make sure DEBUG messages are disabled;
* Keys may vary as stated [before](/KEYS.md);
* Baud Rate may be different, probably 31250.

### Ubuntu Studio

In order to run ubuntu-studio project you are goint to need read permission on serial port. Run the program as sudo or add your user to dialout group or equivalent. Don't forget to log off and back in for the changes to take effect.

```sh
sudo usermod -a -G dialout username
```

If you want to build ubuntu-studio project yourself, you gonna need some libraries that are not installed by default.

```sh
sudo apt update
sudo apt install libgtk-3-dev libgtkmm-3.0-dev
```

### Hardware

![Schematic](/img/schematic.png?raw=true "Schematic")

The DIN socket is optional in case you plan to use USB. And if you don't want to use USB, don't forget to add a power supply to Arduino.  

Threre is also a [KiCad](http://kicad-pcb.org/) project that you can use. This is a little bit out of scale and I didn't manage to track down where the problem is (footprint, KiCad, img conversion, etc) so double check before creating your pcb (I resized the final image). Also, your DIN socket will be different than mine.

There are good tutorials on YouTube to make drum pads such as [this](https://www.youtube.com/watch?v=-4BPpfFGcIE) one from Spikenzie.

### Jack Control

Connect your arduino to the PC, open and start ubuntu-studio project.

![Ubuntu Studio Project](/img/ubuntu-studio-project.png?raw=true "Ubuntu Studio Project")

Open QjackCtl and Hydrogen.
On QjackCtl click the Connections button and go to ALSA tab. Connect arduino output port to hydrogen input port.

![Jack Connections](/img/jack-connections.png?raw=true "Jack Connections")

On Hydrogen, make sure input mode is set to Drumkit: Tools -> Input Mode -> Drumkit.

## License

This project is licensed under the GNU GENERAL PUBLIC LICENSE - see the [LICENSE](https://github.com/rafapgoncalves/arduino-drumkit/blob/master/LICENSE) file for details.

## Acknowledgments

* [evankale](https://github.com/evankale/ArduinoMidiDrums)
* [Dominique Vandenneucker](http://www.music-software-development.com/midi-tutorial.html)
* [amandaghassaei](https://www.instructables.com/id/Send-and-Receive-MIDI-with-Arduino/)
* [Thiago Teixeira & Jari Suominen](http://www.varal.org/ttymidi/)

## TODO

* Add MIDI Channel support
* Move debug messages to MIDI format
