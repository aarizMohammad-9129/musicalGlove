# Musical Glove
A wearable gesture controlled midi instrument controlled by an Arduino UNO, flex sensors, Hairless MIDI, loop MIDI and any music studio.

## Materials, Softwares, and Resources Used
As the micro-controller, I used an Arduino UNO. To play the notes, I used 4 flex sensors stitched to a glove. For the conversion of raw serial bytes (over USB) to actual MIDI notes, I used a free application called 'Hairless MIDI'. I also used loopMIDI, another free application which acts as a virtual cable between the Hairless MIDI and the music studio. As a blueprint, I followed Michael D'Argenio's youtube tutorial on this exact topic. The video is titled 'Serial MIDI Controller (Arduino Crash Course)' and the link is attached at the end of this page. As the music studio, I used the online free synthesizer 'Viktor NV-1' available on the browser (link also attached at the end of this page). 

## Working of the Setup
The flex sensors pick up the voltages and send it to the micro-controller. If the voltage drops below 30, then the micro-controller identifies which flex sensor(s) were triggered and based on the 'if', 'else if' statements, identifies which note to trigger, and sends that over to the Hairless MIDI in the form of serial bytes via USB. The Hairless then converts the raw serial bytes into standard MIDI packets which can be identified by the music studio. To actually transport this data to the MIDI packets to the studio, I used another application known as loopMIDI, which creates virtual input and output ports. The studio then reads these notes and finally plays them. I also employed a double-finger trigger logic which helped me include two extra notes other than the four from the single-finger trigger. The current version is designed to play the first few notes of Megalovania, but it is very versatile, and can be customized according to the user's requirements.

## Limitations and Possible Solutions
This version runs purely on USB serial communication, which means it isn't completely wireless. One fix to this would be to use Bluetooth communication instead of the USB. Although I have used error handling in this version, there is still the issue in which if the serial communication between the Hairless and the micro-controller is disrupted (USB plugged out), the code will still continue to be executed anyway. Then there is also the issue of floating (assuming we don't use a pull-down resistor between the input and the ground pin) occurring if any of the flex sensors' connections are disturbed, which plays random notes on the synthesizer. The easiest software fix to this would be to declare the flex sensors as 'INPUT_PULLUP' instead of 'INPUT', which utilizes the on-board internal resistors on the Arduino. 

## Links 
1. [Serial MIDI Controller tutorial by Michael D'Argenio](https://www.youtube.com/watch?v=vpwYyWo8PE4&list=PLkKwJr5uzjIicD8VxUVXDNAD8alCjPz6N&index=22)

2.[Viktor NV-1 Synthesizer](https://nicroto.github.io/viktor/)

3.[Hairless MIDI](https://projectgus.github.io/hairless-midiserial/)

4. [loopMIDI by Tobias Erichsen](https://www.tobias-erichsen.de/software/loopmidi.html)
