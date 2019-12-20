// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  delay(200);
  int pir = digitalRead(2);
  if (pir == HIGH) {
  digitalWrite(3, pir);    // turn the LED off by making the voltage LOW
  delay(5000);               // wait for a second
  }
}
