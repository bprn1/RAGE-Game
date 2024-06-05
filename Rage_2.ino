#include <Adafruit_CircuitPlayground.h>
#include <AsyncDelay.h>

AsyncDelay delay_1s;

bool leftB;
bool leftBP;
bool rightB;
bool rightBP;
bool switchB;
// // Bools for left, right, and switch buttons they are the button flags, the left and right BP are to set values for when left and right buttons are pressed.
// float sound;
// int points;
// int lightOff;
// int indexGet[10];

void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);
  // // Start the circuitplayground and and serial monitor
  //randomSeed(analogRead(0));
  attachInterrupt(digitalPinToInterrupt(4),leftBISR, RISING);
  attachInterrupt(digitalPinToInterrupt(5),rightBISR, RISING);
  attachInterrupt(digitalPinToInterrupt(7),switchISR, CHANGE);
  // // Create interrupts for left, right and switch
  delay_1s.start(1000, AsyncDelay::MILLIS);
  // // Start Async delay
}


void loop() {
  long pattern1[5] = {1,1,0,0,1};
  long pattern2[10] = {0,1,1,0,0,0,1,0,0,1};
  long pattern3[15] = {1,0,1,0,0,0,1,0,1,1,1,0,0,1,1};
  long pArray1[5] = {};
  long pArray2[10] = {};
  long pArray3[15] = {};
  // // Create arrays for the 3 patterns and set aside space for player Arrays
  //int x = x++;
  switchB = digitalRead(7);
  // Set switch B to read the state of the switch

  for(int i =0; i < 4 && switchB; i++) {
    if(leftB) {
      leftBP = 0;
      leftB = 0;
      delay(50);
      CircuitPlayground.clearPixels();
      // // If left button is pressed, then set it to false and set BP number to 0, delay for 50 and clear pixels
    }

    if(rightB) {
      rightBP = 1;
      rightB = 0;
      delay(50);
      CircuitPlayground.clearPixels();
      // // If right button is pressed, then set it to false and set BP number to 1, delay for 50 and clear pixels
    }

    if(pattern1[i] == leftBP && leftB) {
      pArray1[i] = 0;
    } else if(pattern1[i] == rightBP && rightB) {
      pArray1[i] = 1;
    }

  }

  for(int i =0; i < 4 && !switchB; i++) {
    // // While the switch is Off
    if(pattern1[i] == 0) {
      CircuitPlayground.setPixelColor(1,255, 50,50);
      delay(900);
      CircuitPlayground.clearPixels();
      delay(500);
      // //  if pattern1 at index number equals 0, then turn on left light then turn off
    } else{
      CircuitPlayground.setPixelColor(8,255, 60,50);
      delay(900);
      CircuitPlayground.clearPixels();
      delay(500);
      // //  else, then turn on right light then turn off
    }
  }


  // for(int i =0; i < 4 && switchB; i++) {
  //   if(pattern1[i] == leftBP) {
  //     pArray1[i] = 0;
  //   } else{
  //     pArray1[i] = 1;
  //   }
  // }

  // if(leftB) {
  //   if(x < A1Max) {
  //     playerArray1[x++] = 0;
  //   }
  // Serial.print(pArray1[0]);
  // Serial.print(pArray1[1]);
  // Serial.print(pArray1[2]);
  // Serial.print(pArray1[3]);
  // Serial.print(pArray1[4]);
  // Serial.println(pArray1[5]);  

  // }
  // if(rightB) {
  //   if(x < A1Max) {
  //     playerArray1[x++] = 1;
  //   }
  //   //Serial.println(playerArray1[5]);
  // }
}

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

// // Call backs for left, right, and switch interrupts