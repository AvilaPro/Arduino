//Parpadeo del Led pin 13

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); //declarando el led del pin13 de la placa como salida

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH); //encendemos el led
  delay(1000);            //esperamos 1 segundo
  digitalWrite(13, LOW); //apagamos el led
  delay(1000);            //esperamos 1 segundo
}
