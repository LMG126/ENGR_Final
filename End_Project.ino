#include <Adafruit_CircuitPlayground.h>

const int A = 4;
const int B = 5;
volatile int count = 0;
volatile bool lbuttonState = 0;
volatile bool switchState=0;
volatile bool rbuttonState = 0;
volatile bool switchFlag =0;
volatile bool rbuttonFlag = 0;
volatile bool lbuttonFlag = 0;
volatile bool lbutton;
volatile bool rbutton;
int yop;
int x;
int y;
int z;
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

void one_green(){
CircuitPlayground.playTone(700, 100);
for(int i=0; i<10; i++){
delay(x/10);
CircuitPlayground.setPixelColor(i,0, 255, 0);}
x-=500;
}

void two_blue(){
CircuitPlayground.playTone(300, 100);
for(int i=0; i<10; i++){
delay(y/10);
 CircuitPlayground.setPixelColor(i,0, 0, 255);}
 y-=500;
}

void three_orange(){
 CircuitPlayground.playTone(500,100);
for(int i=0; i<10; i++){
  int temp;
  temp = CircuitPlayground.mic.soundPressureLevel(10);
  if (temp > value) {
    value = temp;
  }
  delay(z/10 - 10);
 CircuitPlayground.setPixelColor(i,255, 135, 12);}
 z-=500;
}

void setYop(int newYop) {
  yop = newYop;
  x = yop;
  y = yop;
  z = yop;
}

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  randomSeed(analogRead(0));
  attachInterrupt(digitalPinToInterrupt(A), lButton, RISING);
  attachInterrupt(digitalPinToInterrupt(B), rButton, RISING);
  attachInterrupt(digitalPinToInterrupt(7), slideSwitch, CHANGE);
  while(!Serial); // Pause program til serial opens
}

void loop() {
  lbutton = CircuitPlayground.leftButton();
  rbutton = CircuitPlayground.rightButton();
  value = CircuitPlayground.mic.soundPressureLevel(10);

  int score = 0;
  bool keepGoing = true;
  int currentCase = 0;
  Serial.println("Welcome");
  Serial.println("Easy or Hard");

  if(switchFlag){
    for(int i=0; i<10; i++){
      CircuitPlayground.setPixelColor(i,255, 0, 0);
    }
    for(int i=0; i<10; i++){
      delay(5000/10);
      CircuitPlayground.setPixelColor(i,0, 0, 0);
    }
    type=200;
    setYop(3000);
    Serial.println("HARD MODE");
    switchFlag=0;
  }
  else{
    for(int i=0; i<10; i++){
      CircuitPlayground.setPixelColor(i,255, 0, 0);}
    for(int i=0; i<10; i++){
      delay(5000/10);
      CircuitPlayground.setPixelColor(i,0, 0, 0);}
    type=900;
    setYop(5000);
    Serial.println("EASY MODE");
  }

  bool practiceDone = false;
  while (!practiceDone) {
    Serial.println("PRACTICE");
    one_green();
    if (lbuttonFlag){
      lbuttonFlag = 0;
    }
    else{
      CircuitPlayground.clearPixels();
      setYop(yop);
      Serial.println("TRY AGAIN");
      continue;
    }
    two_blue();
    if(rbuttonFlag){
      rbuttonFlag = 0;
    }
    else{
      CircuitPlayground.clearPixels();
      setYop(yop);
      Serial.println("TRY AGAIN");
      continue;
    }
    three_orange();
    Serial.println(value); // for testing
    if(value>70){ // write a interrupt
      practiceDone = true;
    }
    else{
      CircuitPlayground.clearPixels();
      setYop(yop);
      Serial.println("TRY AGAIN");
      continue;
    }
  }

  while (keepGoing && currentCase <= 24 && x>type && y>type && z>type) {
    int mode = random(0,3);
    switch(mode){
      case 0:
      one_green();
      currentCase+=1;
      if(lbuttonFlag){
        score+=10;
        Serial.println("Points:");
        Serial.println(score);
        break;
      }
      else{
        CircuitPlayground.clearPixels();
        setYop(yop);
        Serial.println("END GAME");
        Serial.println("Points:");
        Serial.println(score);
        keepGoing = false;
        break;
      }
      case 1:
      two_blue();
      currentCase+=1;
      if(rbuttonFlag){
        score += 10;
        Serial.println("Points:");
        Serial.println(score);
        break;
      }
      else{
        CircuitPlayground.clearPixels();
        setYop(yop);
        Serial.println("END GAME");
        Serial.println("Points:");
        Serial.println(score);
        keepGoing = false;
        break;
      }
      case 2:
      three_orange();
      currentCase+=1;
      if(value>70){ // write a interrupt
        score+=10;
        Serial.println("Points:");
        Serial.println(score);
        break;
      }
      else{
        CircuitPlayground.clearPixels();
        setYop(yop);
        Serial.println("END GAME");
        Serial.println("Points:");
        Serial.println(score);
        keepGoing = false;
        break;
      }
    }
  }
  if (currentCase > 24 || z <=type || x <=type || y <=type){
    Serial.println("YOU WIN!");
      Serial.println("Points:");
      Serial.println(score);
      CircuitPlayground.clearPixels();
      setYop(yop);
      delay(5000);
  }
}