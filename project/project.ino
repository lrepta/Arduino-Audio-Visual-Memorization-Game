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

const int shortLength = 500; // Length of the short flashes/buzzes in milliseconds
const int longLength = 1000; // Length of the long flashes/buzzes in milliseconds

const int soundFrequency = 2000; // Frequency of the buzzer in Hz

SoftwareSerial softSerial(softwareRXPin, softwareTXPin); // RX, TX

int level = 1;

void setup() {
    // Generate a random seed based on an unused analog pin

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

// Sequence array is of max length 15, initialized values to 0 as 1-4 is used for LED/Sound
int sequenceArray[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int sequenceLength = 0;

// Creates the random sequence that the user must repeat
// Follows the following scheme:
// 1 = short LED flash
// 2 = long LED flash
// 3 = short Sound buzz
// 4 = long Sound buzz
// 0 is the uninitialized value, and should never be used
void createSequenceArray() {
    randomSeed(analogRead(A5));
    for (int i = 0; i < sequenceLength; i++) {
        sequenceArray[i] = random(1,4);
    }
}

void generateSequence() {
    int randomLengthAdjuster = random(0, 3);
    sequenceLength = randomLengthAdjuster;
    switch (level) {
        case 1:
            // statements
            sequenceLength += 4;

            digitalWrite(shortLEDPin, HIGH);
            delay(700);
            digitalWrite(shortLEDPin, LOW);
            break;
        case 2:
            // statements
            sequenceLength += 6;

            digitalWrite(longLEDPin, HIGH);
            delay(1700);
            digitalWrite(longLEDPin, LOW);
            break;
        case 3:
            // statements
            sequenceLength += 8;

            analogWrite(soundPin, 255);
            delay(700);
            analogWrite(soundPin, 0);
            break;
        case 4:
            // statements
            sequenceLength += 10;

            analogWrite(soundPin, 255);
            delay(1700);
            analogWrite(soundPin, 0);
            break;
        case 5:
            // statements
            sequenceLength += 12;

            break;
        default:
            // This should not be needed, otherwise could use for error checking
            // statements
        break;
    }

    // After the switch statement to get the length of the sequence, generate the sequence
    createSequenceArray();
}

// Interprets the values in the sequenceArray and plays them back to the user
// Follows the following scheme:
// 1 = short LED flash
// 2 = long LED flash
// 3 = short Sound buzz
// 4 = long Sound buzz
void displaySequence() {
    for(int i = 0; i < sequenceLength; i++) {
        delay(200); // Brief pause in between displaying each element of the sequence
        switch (sequenceArray[i])
        {
            // short LED flash
            case 1:
                digitalWrite(shortLEDPin, HIGH);
                // Maybe shouldn't use delay if we still want to do things during this
                delay(shortLength)
                digitalWrite(shortLEDPin, LOW);
                break;
            case 2:
                digitalWrite(longLEDPin, HIGH);
                delay(longLength)
                digitalWrite(longLEDPin, LOW);
                break;
            case 3:
                tone(soundPin, soundFrequency, shortLength);
                // Might need a delay here? I think tone is a blocking call for its length?
                break;
            case 4:
                tone(soundPin, soundFrequency, longLength);
                // Might need a delay here? I think tone is a blocking call for its length?
                break;
            default:
                // This case should never happen, only happens if you read the
                // uninitalized 0's -> somethng is wrong!
                break;
        }
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
