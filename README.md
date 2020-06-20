# Try Arduino

## tl;dr

    arduino-cli config init
    arduino-cli core update-index
    arduino-cli board list
    arduino-cli core install arduino:avr
    arduino-cli core list

Then compile

    arduino-cli compile --fqbn arduino:avr:mega rgb

And upload

    arduino-cli upload -p /dev/cu.usbmodem14301 --fqbn arduino:avr:mega

## Further Reading

<https://arduino.github.io/arduino-cli/getting-started/>
