//Se utilizo el Arduino Nano, ATMega328P
//lectura digital con pulsador

int ledPin = 9;
int inPin = 2;
int in2Pin = 3;
int value = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(inPin, INPUT);
  pinMode(in2Pin, INPUT);
}

void loop() {
  if (digitalRead(inPin>0){
    value += 25;
    digitalWrite(ledPin,value);
    Serial.println(value);
    delay(10);
  }
  if (digitalRead(in2Pin>0){
    value -= 25;
    digitalWrite(ledPin,value);
    Serial.println(value);
    delay(10);
  }

}
