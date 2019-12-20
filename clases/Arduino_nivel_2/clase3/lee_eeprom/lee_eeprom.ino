#include <EEPROM.h>
byte dato;

void setup() {
Serial.begin(9600);
for (int direccion=0;direccion<1024;direccion++){
  for(int columna=0;columna<10;columna++){
    dato = EEPROM.read(direccion);
    Serial.print(direccion);
    Serial.print(" =");
    Serial.print("\t");
    Serial.print(dato);
    Serial.print("\t");
    direccion++;
    if(direccion==1024) break;
  }
  Serial.println();
  direccion--;
}
}

void loop() {
  // put your main code here, to run repeatedly:

}
