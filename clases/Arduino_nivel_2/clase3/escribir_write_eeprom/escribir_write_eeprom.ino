#include <EEPROM.h>


void setup() {
  Serial.begin(9600);
  for (int i = 250; i < 253; i++){
    EEPROM.write(i, i);
  }
  val = EEPROM[251];
}

void loop() {
  Serial.print(val);
  delay(10000);
}
