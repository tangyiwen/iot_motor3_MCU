//uno

#include <Wire.h>
#include <Servo.h>

#define MOTOR 3
Servo myservo;
int r = 0;

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  myservo.attach(3); 
  Serial.begin(115200);           // start serial for output
}

void loop() {
  delay(50);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
   r = Wire.read(); // receive byte as a character
   Serial.print(r);         // print the character
   myservo.write(r); 
   delay(100);
}

