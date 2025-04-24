#include "LedControl.h"
#define DIN 10
#define CS  11
#define CLK 12
#define Mat 0
LedControl ledMat=LedControl(DIN, CLK, CS, Mat);
byte closed_face[8]={ 
B00000000,
B00000000,
B01000010,
B10100101,
B00011000,
B01011010,
B00111100,
B00000000,
};
byte open_face[8]={
B00000000,
B01000010,
B10100101,
B00000000,
B00011000,
B01011010,
B00111100,
B00000000,
};
byte bored_left[8]={
B00000000,
B00110011,
B00010001,
B00000000,
B01000010,
B00111100,
B01000010,
B00000000,
};
byte bored_right[8]={
B00000000,
B11001100,
B10001000,
B00000000,
B01000010,
B00111100,
B01000010,
B00000000,
};
byte excited_left[8]={
B00000000,
B01000100,
B10101010,
B00000000,
B00000000,
B00011000,
B10011001,
B01111110,
};
byte excited_right[8]={
B00000000,
B00100010,
B01010101,
B00000000,
B00000000,
B00011000,
B10011001,
B01111110,
};

void setup() {
  ledMat.shutdown(Mat,false);
  ledMat.setIntensity(Mat,7);
  ledMat.clearDisplay(Mat);
}
  
  //neutral face
  void neutral(){
  for(int i=0; i<8; i++) {
    ledMat.setRow(Mat,i,closed_face[i]);
  }
  delay(200);
    for(int i=0; i<8; i++) {
    ledMat.setRow(Mat,i,open_face[i]);
    }
  delay(1500);
  }
  
  void bored(){
      for (int i=0; i<2; i++){ 
  delay(2000);
    for(int i=0; i<8; i++) {
    ledMat.setRow(Mat,i,bored_left[i]);
  }
  delay(1500);
    for(int i=0; i<8; i++) {
    ledMat.setRow(Mat,i,bored_right[i]);
  }
  }
  }
  void excited(){
    for(int i=0; i<8; i++) {
    ledMat.setRow(Mat,i,excited_left[i]);
  }
  delay(800);
    for(int i=0; i<8; i++) {
    ledMat.setRow(Mat,i,excited_right[i]);
  }
  delay(800);
  }
  // nastavení intenzity na střední svit
void loop() {
  for (int i = 0; i<10; i++)
  neutral();
  int rand = random(3);
  if (rand = 1){
    for (int i = 0; i<0;i++){
  excited();
    }
  if (rand = 3){
    for (int i = 0; i<0;i++){
  bored();
    }
    }
  if (rand = 2){
    for (int i = 0; i<7;i++){
  neutral();
    }
  }
}

 }