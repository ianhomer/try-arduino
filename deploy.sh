#!/bin/bash

package=${1:-"lcd"}
echo "Deploying $package"
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd $DIR/$1

arduino-cli compile --fqbn arduino:avr:mega
arduino-cli upload -p /dev/cu.usbmodem14301 --fqbn arduino:avr:mega

