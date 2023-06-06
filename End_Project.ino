#include <Adafruit_CircuitPlayground.h>

float X, Y, Z;
// int green=0;
// int red=0;
// int blue=0;
const int A = 4;
const int B = 5;
volatile int count = 0;
volatile bool lbuttonState = 0;
volatile bool switchState=0;
volatile bool rbuttonState = 0;
volatile bool switchFlag =0;
volatile bool rbuttonFlag = 0;
volatile bool lbuttonFlag = 0;
volatile bool accelerState = 0;
volatile bool accelerFlag = 0;
volatile bool lbutton;
volatile bool rbutton;
bool acceler;
int x=5000;
int y=5000;
int z=5000;
int value;
int type;
int score;
bool keepGoing = true;

void slideSwitch(){
  switchFlag=!switchFlag;
}

void lButton(){
  lbuttonFlag=1;
}

void rButton(){
  rbuttonFlag=1;
}
// void acceler(){
//   accelerFlag = 0;
// }

void one_green(){
  if (x==type){
    Serial.println("YOU WIN!");
    Serial.println("Points:");
    Serial.println(score);
    CircuitPlayground.clearPixels();
    keepGoing=false;
  }
  else{
CircuitPlayground.playTone(700, 100);
for(int i=0; i<10; i++){
delay(x/10);
CircuitPlayground.setPixelColor(i,0, 255, 0);}
x-=500;
  }

// if(lbuttonFlag){
//   continue;
//   lbuttonFlag=0;
// }
// else{
//   // Serial.println("GAME OVER");
//   // CircuitPlayground.clearPixels();
//   // x=500;
//   // y=500;
//   // z=500;
//   break;
// }
}

void two_blue(){
if (y==type){
    Serial.println("YOU WIN!");
    Serial.println("Points:");
    Serial.println(score);
    CircuitPlayground.clearPixels();
    keepGoing=false;
  }
  else{
CircuitPlayground.playTone(300, 100);
for(int i=0; i<10; i++){
delay(y/10);
 CircuitPlayground.setPixelColor(i,0, 0, 255);}
 y-=500;
  }
}

void three_orange(){
if (z==type){
    Serial.println("YOU WIN!");
    Serial.println("Points:");
    Serial.println(score);
    CircuitPlayground.clearPixels();
    keepGoing=false;
  }
  else{
 CircuitPlayground.playTone(500,100);
for(int i=0; i<10; i++){
  delay(z/10);
 CircuitPlayground.setPixelColor(i,255, 135, 12);}
 z-=500;
}}

// void end_g(){
// if (accelerFlag){
//   Serial.println("GAME OVER");
//   CircuitPlayground.clearPixels();
// }
//}
// int getRand() { // returns 0, 1, or 2
//   random(0,3);
// }

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  randomSeed(analogRead(0));
  attachInterrupt(digitalPinToInterrupt(A), lButton, RISING);
  attachInterrupt(digitalPinToInterrupt(B), rButton, RISING);
  attachInterrupt(digitalPinToInterrupt(7), slideSwitch, CHANGE);
  while(!Serial); // Pause program till serial opens
  Serial.println("Welcome"); // Start 
}

void loop() {
  lbutton = CircuitPlayground.leftButton();
  rbutton = CircuitPlayground.rightButton();
  value = CircuitPlayground.mic.soundPressureLevel(10);
  X = CircuitPlayground.motionX();
  Y = CircuitPlayground.motionY();
  Z = CircuitPlayground.motionZ();
  int score = 0;
  bool keepGoing = true;
  // green = map(X, -10, 10, -255, 255);
  // red = map(Y, -10, 10, -255, 255);
  // blue = map(Z, -10, 10, -255, 255);
  for (int numCases = 3; numCases <= 12; numCases++) {
  float currentCase = 1;

  Serial.println("Easy or Hard");
  if(switchFlag){
    delay(5000);
    type=400;
    Serial.println("HARD MODE");
    switchFlag=0;
  }
  else{
    delay(5000);
    type=1000;
    Serial.println("EASY MODE");
  }

  Serial.println("PRACTICE");
  one_green();
  if(lbuttonFlag){
       lbuttonFlag = 0;
    }
    else{
      CircuitPlayground.clearPixels();
      x=5000;
      y=5000;
      z=5000;
      Serial.println("TRY AGAIN");
      keepGoing = false;
      break;
      }
  two_blue();
  if(rbuttonFlag){
       rbuttonFlag = 0;
    }
    else{
      CircuitPlayground.clearPixels();
      x=5000;
      y=5000;
      z=5000;
      Serial.println("TRY AGAIN");
      keepGoing = false;
      break;
    }
  three_orange();
  if(value>0){ // write a interrupt
      Serial.println(z);
    }
    else{
      CircuitPlayground.clearPixels();
      x=5000;
      y=5000;
      z=5000;
      Serial.println("TRY AGAIN");
      keepGoing = false;
      break;
    }

while (keepGoing  && currentCase <= numCases) {
  int mode = random(0,3);
  switch(mode){
    case 0:
    one_green();
    currentCase+=1/3;
    if(lbuttonFlag){
      score+=10;
      Serial.println("Points:");
      Serial.println(score);
      break;
    }
    else{
      CircuitPlayground.clearPixels();
      x=5000;
      y=5000;
      z=5000;
      Serial.println("END GAME");
      Serial.println("Points:");
      Serial.println(score);
      keepGoing = false;
      break;
    }
    case 1:
    two_blue();
    currentCase+=1/3;
    if(rbuttonFlag){
      score += 10;
      Serial.println("Points:");
      Serial.println(score);
      break;
    }
    else{
      CircuitPlayground.clearPixels();
      x=5000;
      y=5000;
      z=5000;
      Serial.println("END GAME");
      Serial.println("Points:");
      Serial.println(score);
      keepGoing = false;
      break;
    }
    case 2:
    three_orange();
    currentCase+=1/3;
    if(/*sound_timeFlag*/true){ // write a interrupt
      score+=10;
      Serial.println("Points:");
      Serial.println(score);
      break;
    }
    else{
      CircuitPlayground.clearPixels();
      x=5000;
      y=5000;
      z=5000;
      Serial.println("END GAME");
      Serial.println("Points:");
      Serial.println(score);
      keepGoing = false;
      break;
    }
  }
  }
  }

  // Serial.println("PRACTICE");
  // modeControl=0;
  // modeControl=1;
  // modeControl=2;
}