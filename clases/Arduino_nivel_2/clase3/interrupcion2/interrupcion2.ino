#include <EEPROM.h>

const byte ledPin = 13;
const byte interrupt0 = 0;
volatile byte state = LOW;
volatile int val = 0

void setup() {
  Serial.begin(9600);
pinMode(ledPin, OUTPUT);
pinMode(2, INPUT_PULLUP);
attachInterrupt(interrupt0, blink, FALLING);
}

void loop() {
  digitalWrite(ledPn, state);
  val = EEPROM[251];
  serial.print(val);
  
}

void blink() {
  state = !state;
  EEPROM[251] = EEPROM[251] + 1;
}
