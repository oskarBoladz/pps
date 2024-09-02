#include <Adafruit_GFX.h> 
#include <Max72xxPanel.h>

// const byte 
// m1 m2 m3 e1 e2 n1 n2



int boop = 2, mic = 5 ; // pin for boop and mic pin sensor
int bri = 2 ,minmic=200; // bri range from 1-15 // minmic imnimal mic vol 
bool blk = LOW; // blink true fals

int state = 1;
bool bs=false; // set to true for boot load section

Max72xxPanel matrix = Max72xxPanel(9, 1, 14); // matrix amount 14 or 16

 byte m1[32] = { 
    0b00000011,
    0b01000001,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b11000000,
    0b11000001,};

 byte m2[32] = {
    0b00000011,
    0b01000001,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b11000000,
    0b11000001,};
     byte e1[16] = {
    0b00000011,
    0b01000001,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b11000000,
    0b11000001,};
    byte e2[16] = {
    0b00000011,
    0b01000001,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b11000000,
    0b11000001,};
        byte n1[8] = {
    0b00000011,
    0b01000001,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b11000000,
    0b11000001,};
        byte n2[8] = {
    0b00000011,
    0b01000001,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b11000000,
    0b11000001,};


void setup(){
  pinMode(boop, INPUT);
  matrix.setIntensity(bri); 
  matrix.setRotation(1);
  Serial.begin(9600);
  
}

int xd=0;
bool pop=false;
void loop(){
//boot section
  if(bs){
    matrix.setRotation(3);
    for (int x = 48; x < 112; x++){
      matrix.fillScreen(LOW);
      matrix.setCursor(x-48,0);
      matrix.setTextColor(HIGH);
      matrix.setTextSize(1);
      matrix.print("PAWILION");
      matrix.fillRect(0,0,48,7,LOW);
      matrix.write();
      delay(100);
    }
    matrix.setRotation(1);
    matrix.fillScreen(LOW);
    for (int x = 0; x < 32; x++){
      matrix.drawLine(x,0,x,7,HIGH);
      matrix.drawLine((63-x),0,(63-x),7,HIGH);

      matrix.drawLine(x+64,0,x+64,7,HIGH);
      matrix.drawLine(111-x,0,111-x,7,HIGH);

      delay(100);
      matrix.write();
    }
    matrix.fillScreen(LOW);
    bs=false;
  }
// normal state
  // if(state==1){
  //   // matrix.setRotation(0,2);
  //   for (int y=0;y<8;y++){
  //     for (int x=0;x<32;x++){
  //       matrix.drawPixel(x, y, m1[x] & (1 << y));
  //       matrix.drawPixel(x+32, y, m2[x] & (1 << y));
  //     }
  //     for (int x=0;x<16;x++){
  //         matrix.drawPixel(x+64, y, e1[x] & (1 << y));
  //         matrix.drawPixel(x+96, y, e2[x] & (1 << y));
  //     }
  //     for (int x=0;x<8;x++){
  //         matrix.drawPixel(x+80, y, n1[x] & (1 << y));
  //         matrix.drawPixel(x+88, y, n2[x] & (1 << y));
  //     }
  //   }
  //   matrix.write();

  // }
  matrix.setRotation(3);
  if (digitalRead(2) && pop){
    matrix.fillScreen(LOW);
      matrix.setCursor(63,0);
      matrix.setTextColor(HIGH);
      matrix.setTextSize(1);
      xd++;
      matrix.print(xd);
      matrix.write();
      delay(400);
      pop=false;
        }
        if(!digitalRead(2)){
          pop=true;
        }

}

