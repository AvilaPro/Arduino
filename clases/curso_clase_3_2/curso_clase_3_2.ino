//Se utilizo el Arduino Nano, ATMega328P
//lectura digital con pulsador

int ledPin = 9;
int inPin = 2;
int value = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(inPin, INPUT);
}

void loop() {
  value = digitalRead(inPin);
  digitalWrite(ledPin,value);
  delay(10);

}
