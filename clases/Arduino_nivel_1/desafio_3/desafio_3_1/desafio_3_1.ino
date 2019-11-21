//Desadio 3 Arduino Seccion 3033

int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 10;  // variable to store the value coming from the sensor
float voltaje = 0; //inicialiazamos la variable de control de voltaje
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600)
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  sensorValue = sensorValue/4;
  voltaje = ((sensorValue/255)*5)
  Serial.println(voltaje);
  delay(10);
}
