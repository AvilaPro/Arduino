#include <EEPROM.h>


void setup() {
Serial.begin(9600);
float f = 0.00f;
int eeAddress = 0;

EEPROM.get(eeAddress, f);

Serial.println(f,3);
}

void loop() {
  // put your main code here, to run repeatedly:

}
