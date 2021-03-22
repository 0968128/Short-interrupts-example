#include <Adafruit_CircuitPlayground.h>

volatile bool mailboxFlag;

void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
  attachInterrupt(digitalPinToInterrupt(9), ISR_button, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(mailboxFlag) {
    CircuitPlayground.setPixelColor(9, 0, 255, 128);

    // Set to false again, until the next change
    mailboxFlag = false;
  }
}

void ISR_button() {
  Serial.println(CircuitPlayground.temperature());
  mailboxFlag = true;
}
