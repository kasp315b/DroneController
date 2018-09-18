#include <Servo.h>
#include <SoftwareSerial.h>

uint8_t ESC_FRONT_LEFT  = 15;
uint8_t ESC_FRONT_RIGHT = 13;
uint8_t ESC_MID_LEFT    = 12;
uint8_t ESC_MID_RIGHT   = 14;
uint8_t ESC_BACK_LEFT   =  4;
uint8_t ESC_BACK_RIGHT  =  5;
uint8_t SSERIAL_TX      =  1;
uint8_t SSERIAL_RX      =  3; 

Servo escFrontLeft;
Servo escFrontRight;
Servo escMidLeft;
Servo escMidRight;
Servo escBackLeft;
Servo escBackRight;
SoftwareSerial rPiSerial(SSERIAL_RX, SSERIAL_TX);

void setup() {
  escFrontLeft.attach(ESC_FRONT_LEFT);
  escFrontRight.attach(ESC_FRONT_RIGHT);
  escMidLeft.attach(ESC_MID_LEFT);
  escMidRight.attach(ESC_MID_RIGHT);
  escBackLeft.attach(ESC_BACK_LEFT);
  escBackRight.attach(ESC_BACK_RIGHT);

  rPiSerial.begin(4800);
}

void loop() {
  
}

int mapSpeed(int input, int max, int min) {
  int output = map(input, max, min, 0, 179);
  if(output <   0) output =   0;
  if(output > 179) output = 179;
  return output;
}
