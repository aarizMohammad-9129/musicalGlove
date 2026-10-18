//The following code is for a wearable midi instrument as part of my MIT Maker's Portfolio


#include <Wire.h> // Added for MPU-6050 I2C communication
#include "notes.h"

#define SIXTEENTH QUARTER/4
#define EIGHTH QUARTER/2
#define QUARTER 240  
#define DOT_QUARTER QUARTER * 1.5
#define HALF QUARTER*2
#define WHOLE QUARTER*4

void setup() {
 
}


void loop() {

}


void noteOn(int note, int velocity) {
  Serial.write(144); // 0x90 MIDI Command
  Serial.write(note);
  Serial.write(velocity);
}


void noteOff(int note) {
  Serial.write(144); // 0x90 MIDI Command
  Serial.write(note);
  Serial.write(0);
}
