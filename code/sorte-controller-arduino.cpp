#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position
int const LEFT  = 45;
int const RIGHT = 120;
int vibrTable = 6;
String inString = "";

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  // send an intro:
  Serial.println("\n\nWaiting2command");
  Serial.println();
  pinMode(vibrTable, OUTPUT);
}

void loop() {
  while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char and add it to the string:
      inString += (char)inChar;
    }
    // if you get a newline, print the string, then the string's value:
    if (inChar == '\n') {
      // Serial.println(inString.toInt());

      switch(inString.toInt()){
        case 0:
            myservo.write(LEFT);
          break;
        case 1:
            myservo.write(RIGHT);
          break;
        case 2:
            digitalWrite(vibrTable, HIGH);
          break;
        case 3:
            digitalWrite(vibrTable, LOW);
          break;
      }

      // Serial.print("String: ");
      Serial.println(inString);
      // clear the string for new input:
      inString = "";
    }
  }
}
