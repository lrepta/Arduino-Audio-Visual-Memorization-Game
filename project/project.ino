// Names:
// Luke Repta
// Timothy Jang
// Aleksandar Kartelyan
// 
// Title - 
// Description: 
// References: 
//   - 
// Assumptions:

#include <SoftwareSerial.h>
// Need pins 0 and 1 to be reserved for communication from hardware serial to the softwareSerial object we create

// Change these if we want
const int shortLEDPin = 3;
const int longLEDPin = 4;

const int shortLEDBtn = 5;
const int longLEDBtn = 6;

const int shortSoundBtn = 7;
const int longSoundBtn = 8;

const int soundPin = 9;

const int softwareRXPin = 11;
const int softwareTXPin = 12;

SoftwareSerial softSerial(softwareRXPin, softwareTXPin); // RX, TX

int level = 1;

void setup() {
    pinMode(shortLEDPin, OUTPUT);
    pinMode(longLEDPin, OUTPUT);

    pinMode(soundPin, OUTPUT);

    pinMode(shortLEDBtn, INPUT);
    pinMode(longLEDBtn, INPUT);
    pinMode(shortSoundBtn, INPUT);
    pinMode(longSoundBtn, INPUT);
  
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  softSerial.begin(9600);
}

// someDataStructure correctSequence;
// someDataStructure userSequence;

int recordInput() {
    // record input on the buttons until the user enters an incorrect input?
    // Otherwise we will need another button or something for the user to indicate when
    // they are done entering what they think the sequence is
    while() {
        // record user input, with proper debouncing etc
        if (input sequence is still correct) {
            continue;
        } else {
            // Incorrect input
            return 0;
        }
    }
}

void generateSequence() {
    switch (level) {
        case 1:
            // statements
            digitalWrite(shortLEDPin, HIGH);
            delay(700);
            digitalWrite(shortLEDPin, LOW);
            break;
        case 2:
            // statements
            digitalWrite(longLEDPin, HIGH);
            delay(1700);
            digitalWrite(longLEDPin, LOW);
            break;
        case 3:
            // statements
            analogWrite(soundPin, 255);
            delay(700);
            analogWrite(soundPin, 0);
            break;
        case 4:
            // statements
            analogWrite(soundPin, 255);
            delay(1700);
            analogWrite(soundPin, 0);
            break;
        case 5:
            // statements
            break;
        default:
            // This should not be needed, otherwise could use for error checking
            // statements
        break;
    }
}

void loop() {
    // Lots of repeated code, could be made prettier
  if (level == 1) {
    if (recordInput() == 1) {
        level++;
        generateSequence();
    } else {
        // reset the level with a new sequence
        generateSequence();
    }
  }
  else if (level == 2) {
      if (recordInput() == 1) {
        level++;
        generateSequence();
    } else {
        level = 1;
        generateSequence();
    }
  }
  else if (level == 3) {
      if (recordInput() == 1) {
        level++;
        generateSequence();
    } else {
        level = 1;
        generateSequence();
    }
  }
  else if (level == 4) {
      if (recordInput() == 1) {
        level++;
        generateSequence();
    } else {
        level = 1;
        generateSequence();
    }
  }
  else if (level == 5) {
      if (recordInput() == 1) {
        level++;
        generateSequence();
    } else {
        level = 1;
        generateSequence();
    }
  }
}
