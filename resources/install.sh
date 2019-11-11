#!/bin/bash

#-- Constants -----------------------------------------------------------------------------------------------------------------------------------------
BASE=$( cd "$(dirname "$0")" ; pwd -P )
GROUP_NAME="dialout"
#------------------------------------------------------------------------------------------------------------------------------------------------------

#-- Variables -----------------------------------------------------------------------------------------------------------------------------------------
groupAdded=0
#------------------------------------------------------------------------------------------------------------------------------------------------------

function main() {
	cd "$BASE"
	
	checkGroup
	checkH2Drumkit
	checkArduinoDrumkit
	checkMenuEntry
	
	checkLogoff
}

function checkGroup() {
	local inGroup=$(groups $(whoami) | grep "$GROUP_NAME" | wc -l)
	
	if [ $inGroup == 0 ]; then
		echo "Adding user to $GROUP_NAME..."
		sudo usermod -a -G $GROUP_NAME $(whoami)
		groupAdded=1
	fi
}
function checkH2Drumkit() {
	if [ -d "/usr/share/hydrogen/data/drumkits" ]; then
		if ! [ -d "/usr/share/hydrogen/data/drumkits/GMRockKit" ]; then
			echo "Coping GMRockKit drumkit..."
			sudo tar xzf GMRockKit.h2drumkit -C /usr/share/hydrogen/data/drumkits/
			sudo chown -R root:root /usr/share/hydrogen/data/drumkits/GMRockKit
			sudo chmod 755 -R /usr/share/hydrogen/data/drumkits/GMRockKit
		fi
	fi
}
function checkArduinoDrumkit() {
	if ! [ -d "/usr/local/arduino-drumkit" ]; then
		echo "Installing arduino-drumkit..."
		sudo mkdir /usr/local/arduino-drumkit
	else
		echo "Updating arduino-drumkit..."
	fi
	
	sudo yes | cp -f ./ubuntu-studio /usr/local/arduino-drumkit/ubuntu-studio
	sudo yes | cp -rf ./glade /usr/local/arduino-drumkit/glade
	sudo chown -R root:root /usr/local/arduino-drumkit
	sudo chmod 755 -R /usr/local/arduino-drumkit
}
function checkMenuEntry() {
	if ! [ -f "/usr/share/applications/arduino-drumkit.desktop" ]; then
		echo "Creating menu entry..."
		sudo bash -c "echo \"[Desktop Entry]
Name=Arduino-Drumkit
GenericName=Arduino-Drumkit
Exec=bash -c 'cd /usr/local/arduino-drumkit && /usr/local/arduino-drumkit/ubuntu-studio'
Icon=audio-x-generic
Categories=Audio;Midi;
Keywords=Audio;MIDI;
Terminal=false
Type=Application\" > /usr/share/applications/arduino-drumkit.desktop"
	fi
}
function checkLogoff() {
	if [ $groupAdded == 1 ]; then
		echo "You need to logoff and back in order for permissions changes to take effect."
	fi
}

main "$@"
