const byte ledPin = 13;
const byte interrupt0 = 0;
volatile byte state = LOW;

void setup() {
pinMode(ledPin, OUTPUT);
pinMode(2, INPUT_PULLUP);
attachInterrupt(interrupt0, blink, FALLING);
}

void loop() {
  digitalWrite(ledPin, state);
}

void blink() {
  state = !state;
}
