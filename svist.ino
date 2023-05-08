#define RX 10
#define TX 11

#include<SoftwareSerial.h>

SoftwareSerial mySerial(RX,TX);
long int a = 0;


void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  if (mySerial.available() > 0)
  {
    char packageMe[10];
    int packageMe_size = mySerial.readBytes(packageMe,10);
    packageMe[packageMe_size] = NULL;
    delay(50);
    Serial.print(packageMe);
  }
  
  if (Serial.available() > 0)
  {
    char packageS[10];
    int packageS_size = Serial.readBytes(packageS,10);
    packageS[packageS_size] = NULL;
    delay(50);
    //q = atoi(packageS);
    mySerial.print(packageS);
  }
}
