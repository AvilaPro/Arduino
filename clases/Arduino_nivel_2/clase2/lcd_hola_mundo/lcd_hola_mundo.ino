//Progama para LCD de una fila 16 columnas
#include <LiquidCrystal.h>
LiquidCrystal(12, 11, 5, 4, 3, 2);
void setup() {
  lcd.begin(8,2);
  lcd.print("Hola Mun");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0,1);
  lcd.print("do");
  // print the number of seconds since reset:
  lcd.setCursor(4,1);
  lcd.print(millis() / 1000);
}
