//The following code is for a wearable MIDI instrument as part of my MIT Maker's Portfolio. Except for the setup, loop and playNoteRoutine functions, the rest of the code is NOT MINE.
//Credit to: Michael D'Argenio for the starter code, as found on his youtube tutorial's description titled 'Serial MIDI Controller (Arduino Crash Course 21)'
//For the list of softwares used, refer README.md

#include "notes.h"

#define SIXTEENTH QUARTER/4
#define EIGHTH QUARTER/2
#define QUARTER 240  
#define DOT_QUARTER QUARTER * 1.5
#define HALF QUARTER*2
#define WHOLE QUARTER*4

const int Index = A0;
const int middle = A1;
const int ring = A2;
const int pinky = A3;

const int limit = 30;

void setup() {
 Serial.begin(115200);
 pinMode(Index, INPUT);
 pinMode(middle, INPUT);
 pinMode(ring, INPUT);
 pinMode(pinky, INPUT);
 
}


void loop() {
 int v1 = analogRead(Index);
 int v2 = analogRead(middle);
 int v3 = analogRead(ring);
 int v4 = analogRead(pinky);

//Convert flex values to T/F statements

 bool I = (v1 < limit);  //Index
 bool M = (v2 < limit);  //Middle
 bool R = (v3 < limit);  //Ring
 bool P = (v4 < limit);  //Pinky

//Two Finger Combination Notes
 
 //Index + Middle
 if (I && M && !R && !P) {
  playNoteRoutine(NOTE_G4, QUARTER);
  delay(QUARTER);
 }
 
 //Middle + Ring
  else if (!I && M && R && !P) {
  playNoteRoutine(NOTE_F4, QUARTER);
  delay(QUARTER);
  }
 
//Single Finger Notes

 //Index
  else if (I && !M && !R && !P) {
  playNoteRoutine(NOTE_D4, EIGHTH);
  delay(EIGHTH);
 }

//Middle
   else if (!I && M && !R && !P) {
  playNoteRoutine(NOTE_D5, QUARTER);
  delay(QUARTER);
 }
    
//Ring
    else if (!I && !M && R && !P) {
  playNoteRoutine(NOTE_A4, DOT_QUARTER);
  delay(EIGHTH);
 }

//Pinky
      else if (!I && !M && !R && P) {
  playNoteRoutine(NOTE_GS4, EIGHTH);
  delay(EIGHTH);
 }

delay(50);       
       
}

//Helper function to handle midi control (added by me)

void playNoteRoutine(int note, int duration) {
 noteOn(note, 127);
 delay(duration);
 noteOff(note);
 delay(20);
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
