/*
Haga el mismo ejemplo 1 pero ahora pidale al usuario por 
puerto serial cual sera la temperatura en que debe funcionar y 
mantener el sistema funcionando. Y haga que cada 1 seg improma 
en puerto serial la temperatura medida

*/

//Se trabajo en clases con un Arduino Nano (Old Bootloader).

const int sensorPin = A0; //Pin donde se conectara el sensor de temperatura descrito
const int resCal = 9; //Pin donde se conectara la resistencia de calor indicada en el enunciado
int par = 50; //par sera el parametro que el usuario ingresara por el puerto serial.
int temp = 767; //temp es el valor calculado para ser usado para regular el resistor.
int tempmed = 0; //tempmed es la temperatura que tiene el sensor.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(resCal, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(analogRead(sensorPin) > temp){
    digitalWrite (resCal, HIGH);
    }
  while(analogRead(sensorPin) <= temp){
    digitalWrite (resCal, LOW);
    }
  if(Serial.available()){
    par = Serial.read();
    par = par + 100;
    temp = (par * 1023)/200;
  }
  tempmed = ((sensorPin * 200)/1023)-100;
  Serial.print(tempmed);
  delay(1000);
}
