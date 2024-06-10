#include <Adafruit_CircuitPlayground.h>
#include <AsyncDelay.h>
#include <Wire.h>
#include <SPI.h>
// // Add the CPX board, asyncDelay for a timer, and the two libraries needed for the spearker function.

AsyncDelay delay_1s;
const uint8_t spMOVING[] PROGMEM = {0x6A,0x91,0xB2,0x23,0xC5,0x93,0x98,0xD9,0x2A,0xED,0x14,0x4F,0x12,0xA6,0xA4,0xB8,0x8A,0xD5,0x59,0x99,0xB2,0xA2,0x09,0x66,0x27,0xA5,0x0B,0x26,0x33,0x84,0x9E,0xB4,0x36,0xF1,0x4A,0x77,0xF8,0x5C,0x9A,0x28,0x2B,0x5D,0xE1,0x75,0x69,0x82,0xCE,0x0C,0xA6,0xC5,0xA1,0x8F,0x2A,0xDC,0x55,0x63,0xBB,0xA1,0x33,0x57,0x71,0x8B,0x5D,0x9A,0xA4,0xCC,0xC2,0x2A,0xD5,0xAA,0x9B,0x13,0xB5,0xF0,0x59,0xAB,0xE9,0x41,0xD8,0x2A,0x26,0x8D,0xB6,0x6B,0xE1,0x5A,0xB1,0x5A,0xDA,0xAA,0xA8,0x53,0xC4,0x69,0x69,0xAB,0xA2,0x71,0x51,0x27,0xA9,0xAF,0x92,0xF5,0x13,0xE3,0xFD,0x3F};
const uint8_t spUP[] PROGMEM = {0x69,0x2C,0x6A,0x32,0xCC,0x97,0xAC,0xA1,0xC8,0x4D,0x37,0x5F,0xB3,0xFA,0xA2,0x36,0x42,0x63,0xC9,0x6A,0x93,0x9B,0x08,0xCD,0x25,0xAB,0xCD,0x76,0x32,0x25,0x96,0x94,0x21,0x96,0x4A,0x97,0xB9,0xE3,0xA6,0xD0,0x3D,0x2C,0xF6,0x0A,0x02,0xA7,0x28,0x55,0xA1,0x1A,0x00,0x00,0x04,0x70,0x2E,0x44,0x00,0x39,0xB9,0x23,0x20,0x35,0xD7,0xFF,0x07};
const uint8_t spDOWN[] PROGMEM = {0x02,0x28,0x30,0x6C,0x55,0x4D,0x25,0xAB,0xF9,0xEA,0x55,0x57,0x9B,0xA2,0x6E,0x6B,0x56,0x53,0x74,0xAA,0xB7,0xAF,0x5E,0x4D,0xD5,0x6D,0xD6,0xBA,0x78,0x75,0xC5,0xB6,0x79,0xEB,0xE2,0x35,0x64,0x3B,0xA6,0x63,0x4B,0xF6,0xB0,0x96,0xEC,0xD6,0xB4,0x6D,0xC9,0xDA,0x52,0x58,0xD3,0xB6,0xC5,0x6D,0x4B,0xFE,0x4C,0xDA,0x17,0x97,0x3D,0xB4,0xB6,0x48,0x9F,0x5C,0x8E,0x2C,0x2D,0x47,0xC2,0x76,0x3D,0xCB,0x59,0xB9,0xDA,0x68,0x4A,0x2D,0x57,0xB7,0xAC,0x25,0xE1,0xE4,0xFF,0x01};
const uint8_t spGREAT[] PROGMEM = {0x6E,0xF3,0x59,0xC2,0x46,0xD9,0xA9,0xCD,0x0C,0x95,0x0E,0x55,0x6E,0x36,0x3D,0x9D,0xAA,0x4C,0xAE,0xD9,0xF4,0x0C,0xCC,0x36,0x7B,0x6E,0xF5,0x8B,0xF4,0x4C,0xB2,0x95,0x29,0x76,0xCC,0xD2,0xF4,0xB6,0xA6,0x5C,0xC4,0xD3,0xAA,0xEF,0x9A,0xAA,0x2F,0x8C,0x8C,0x4D,0x6B,0x19,0x6E,0x48,0xD2,0x56,0xAD,0x7D,0xB8,0x42,0x4E,0x5F,0xDD,0xCE,0x6E,0x0C,0x7C,0x72,0x71,0x38,0x87,0x36,0xD0,0xCE,0xD9,0x6C,0x1B,0x5A,0xC9,0x22,0x12,0x23,0x70,0x8A,0x52,0x15,0xAA,0x01,0x00,0x0E,0x18,0xD2,0xCD,0x01,0x9B,0xAB,0x09,0xE0,0x98,0x2D,0x01,0x2C,0x15,0x86,0x80,0x1A,0x15,0xFE,0x1F};
const uint8_t spBREAKING[] PROGMEM = {0x04,0x50,0xD6,0x2C,0xB5,0xA1,0xB8,0x5A,0x9A,0xFB,0x35,0xE4,0x14,0x21,0x69,0xEA,0x57,0x97,0x8B,0x87,0x84,0xE5,0x5B,0x6D,0x33,0xC9,0xD6,0xB6,0x65,0xD5,0x23,0x14,0x72,0xD9,0xEA,0x52,0x8D,0x2B,0x24,0x92,0x4B,0x58,0xD3,0x85,0x92,0x86,0xB9,0x26,0xC0,0xB4,0xCA,0x0E,0x98,0x4C,0xA4,0x24,0x3B,0x36,0x2B,0xAB,0xD3,0x55,0x8E,0xC4,0xA4,0xD5,0xB3,0x47,0x3D,0x22,0x51,0x74,0x95,0x1E,0x75,0x0F,0x68,0x5D,0x66,0x76,0xD4,0xDD,0x60,0x64,0xA8,0x9A,0xD1,0x0C,0x8B,0x9E,0x69,0x4A,0x5B,0xDB,0x35,0x66,0xBA,0x39,0x69,0x43,0xD3,0x18,0xE3,0xAA,0x34,0xB5,0x4D,0xA3,0x6D,0x85,0x99,0xFF,0x07};
// // Used the Speech Demos Large to have the speaker talk to the player to show progression in the game.


bool leftB;
bool leftBP;
bool rightB;
bool rightBP;
bool switchB;
// // Bools for left, right, and switch buttons they are the button flags, the left and right BP are to set values for when left and right buttons are pressed.

int rounds = false;
int randColor;
int speed = 0;
int rightLight = 0;
int leftLight = 0;
int score = 0;
volatile int timer1 = 5;
int newTimer = 0;
// // Ints set for rounds, which is to stop the progression lights from repeating, randColor which chooses a random value and sets it at the neopixel, speed, which decreases how 
// // fast the speed of the lights display, right and left Light are to show when the neopixels turn on/off, score increments with each light and button press player gets right
// // timer1 is for how long the player has to choose the right button, and newTimer to decrease the length of timer1 as you progress through the stages.


void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);
  // // Start the circuitplayground and and serial monitor
  randomSeed(analogRead(0));
  attachInterrupt(digitalPinToInterrupt(4),leftBISR, RISING);
  attachInterrupt(digitalPinToInterrupt(5),rightBISR, RISING);
  attachInterrupt(digitalPinToInterrupt(7),switchISR, CHANGE);
  // // Create interrupts for left, right and switch
  delay_1s.start(1000, AsyncDelay::MILLIS);
  // // Start Async delay
}


void loop() {
  switchB = digitalRead(7);
  // // Set switch B to read the state of the switch
  
  lights();

  if(leftB) {
    highScore();
    leftB = 0;
    leftBP = 0;
    delay(50);
    // // If left button is pressed, then set it to false and set BP number to 0, delay for 50 and clear pixels
  }

  if(rightB) {
    highScore();
    rightB = 0;
    rightBP = 1;
    delay(50);
    // // If right button is pressed, then set it to false and set BP number to 1, delay for 50 and clear pixels
  }

  if(delay_1s.isExpired() && !switchB) {
    timer1 = timer1 -1;
    Serial.print("Timer: ");
    Serial.println(timer1);
    delay_1s.restart();
    if(timer1 <= 0 && !switchB) {
      Serial.println("You Lose");
      Serial.print("FINAL SCORE: ");
      Serial.println(score);
      score = 0;
      newTimer = 0;
      timer1 = 5 - newTimer;
      rightLight = 0;
      leftLight = 0;
      speed = 0;
      CircuitPlayground.speaker.say(spMOVING);
	    CircuitPlayground.speaker.say(spDOWN);
      reverse();
    }
  } 
  // // When the delay_1s expires and the switch is off, then display and count down timer1, if timer1 is <= 0 and switch is off, then player loses, and prints score and resets
  // // everything. Also states that player is moving down all the stages passed.
}

void lights() {
  if(!switchB && !leftB && !rightB && leftLight == 0 && rightLight == 0) {
    // // While the switch is Off and buttons aren't pushed and lights are off
    randColor = random(0,2);
    Serial.println(randColor); // // A player can use this to tell which light is on without looking at the board. 0 is left light, 1 is right light.
    // // Choose a random index
    if(randColor == 0) {
      CircuitPlayground.setPixelColor(1,255, 50,50);
      rightLight = 0;
      leftLight = 1;
      delay(1000-speed);
      highScore();
      // //  if randColor at index number equals 0, then turn on left light, set right and left Light ints to corresponding true/false and debounce then do highScore
    } else{
      CircuitPlayground.setPixelColor(8,255, 60,50);
      rightLight = 8;
      leftLight = 0;
      delay(1000-speed);
      highScore();
      // //  else, randColor at index number equals 1, then turn on right light, set right and left Light ints to corresponding true/false and debounce then do highScore
    }
  }
}

void highScore() {
  if(score == 40) {
    CircuitPlayground.speaker.say(spGREAT);
	  CircuitPlayground.speaker.say(spBREAKING);
    Serial.println("YOU WON!");
    Serial.println("Entering Infinity Mode...");
    rounds = true;
    for(int i = 0; i< 10 && rounds; i++) {
      timer1 = 5;
      CircuitPlayground.clearPixels();
      int randR = random(235);
      int randG = random(235);
      int randB = random(235);
      CircuitPlayground.setPixelColor(i,   randR,   randG,   randB);
      delay(20);
    }
    rounds = false;
    CircuitPlayground.clearPixels();
    // // When player reaches 40 the CPX congradulates them on breaking so many objects and states that they are entering Infinity Mode, to exit the mode, the player has to click
    // // the wrong button. Also has a specific light pattern to celebrate the player winning!
  }else if (score == 35 && leftLight == 0 && rightLight == 0) {
    speed = 900;
    newTimer = 3;
    forward();
  }else if(score == 25 && leftLight == 0 && rightLight == 0) {
    speed = 600;
    newTimer = 3;
    forward();
  } else if(score == 15 && leftLight == 0 && rightLight == 0) {
    speed = 400;
    newTimer = 2;
    forward();
  } else if(score == 5 && leftLight == 0 && rightLight == 0) {
    speed = 200;
    newTimer = 1;
    forward();
  }
  // // Sets new stage rules as the player reaches a certain score, plays forward() as player progresses.

  if(leftB && leftLight == 1 && !switchB) {
    score = score + 1;
    Serial.print("Score: ");
    Serial.println(score);
    delay(50);
    timer1 = 5 - newTimer;
    CircuitPlayground.setPixelColor(1,0,0,0);
    leftLight = 0;
    // // The Score increases when the player chooses the right button and respective light turns off along with reassigning leftLight to 0.
  } else if (rightB && rightLight == 8 && !switchB) {
    score = score + 1;
    Serial.print("Score: ");
    Serial.println(score);
    delay(50);
    timer1 = 5 - newTimer;
    CircuitPlayground.setPixelColor(8,0,0,0);
    rightLight = 0;
    // // The Score increases when the player chooses the right button and respective light turns off along with reassigning rightLight to 0.
  } else if(rightB && leftLight == 1 || leftB && rightLight == 8) {
    Serial.println("You Lose");
    Serial.print("FINAL SCORE: ");
    Serial.println(score);
    score = 0;
    newTimer = 0;
    timer1 = 5 - newTimer;
    rightLight = 0;
    leftLight = 0;
    speed = 0;
    reverse();
    // // If the player chooses wrong then player loses and it prints their final score and resets all functions, restarting the game.
  }
}

void forward() {
  rounds = true;
  CircuitPlayground.speaker.say(spMOVING);
	CircuitPlayground.speaker.say(spUP);
  for(int i = 0; i < 10 && rounds && leftLight == 0 && rightLight == 0; i++) {
    CircuitPlayground.setPixelColor(i, 0, 255, 0);
    CircuitPlayground.playTone(400, 10);
    delay(30);
  }
  CircuitPlayground.clearPixels();
  rounds = false;
}
// // Sets rounds to true and then has speaker state that the player is moving up in the stages and then turns all lights to green, plays a tone, and clears pixels and sets rounds to false.

void reverse() {
  CircuitPlayground.speaker.say(spMOVING);
	CircuitPlayground.speaker.say(spDOWN);
  for(int i = 10; i > -1 ; i--) {
    CircuitPlayground.setPixelColor(i, 255, 0, 0);
    CircuitPlayground.playTone(350, 10);
    delay(30);
  }
  CircuitPlayground.clearPixels();
}
// // Has the speaker state that the player is moving down in the stages and then turns all lights to red, plays a tone, and clears all pixels.



void leftBISR() {
  leftB = true;
  leftBP = 1;
}


void rightBISR() {
  rightB = true;
  rightBP = 0;
}

void switchISR() {
  switchB = true;
}

// // Call backs for left, right, and switch interrupts, sets flags to true and sets leftBP and rightBP to their respective "true" states. When switch is true it pauses the game.
