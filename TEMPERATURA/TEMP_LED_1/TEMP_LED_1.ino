
const int sensor = 0;
const int ledRojo = 5;
const int ledAzul = 6;

long miliVolts;
long temperatura;

int brillo;

void setup() {
  //Serial.begin(9600); //iniciamos la comunicacion serial
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  
}

void loop() {
  miliVolts = (analogRead(sensor) * 5000L) / 1023; //calculamos los mV en la entrada
  temperatura = miliVolts / 10; //calculamos la temperatura

  brillo = map(temperatura, 10, 40, 0, 255);    //justamos la escala de temperatura para usar analogWrite
  brillo = constrain(brillo, 0, 255);   //limitar el rango de brillo entre 0 y 255

  analogWrite(ledRojo, brillo);
  analogWrite(ledAzul, 255 - brillo);
  
  /*Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" grados");
  delay(300);*/  //espera para no saturar el monitor serial

}
