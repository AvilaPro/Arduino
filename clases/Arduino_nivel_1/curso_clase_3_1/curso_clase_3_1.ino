//Se utilizo el Arduino Nano, ATMega328P
//lectura analogica con un potenciometro

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 9;      // select the pin for the LED
int sensorValue = 10;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  sensorValue = sensorValue/4;
  digitalWrite(ledPin, sensorValue);
  Serial.println(sensorValue);
  // stop the program for <100> milliseconds:
  delay(100);

}
