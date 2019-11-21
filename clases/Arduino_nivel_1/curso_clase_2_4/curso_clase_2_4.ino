//Se utilizo el Arduino Nano, ATMega328P
//Se usa una constante y como manipularla

const byte constante = 5;

int num = 5;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  Serial.println(constante);
  Serial.println("");
}

// the loop function runs over and over again forever
void loop() {
  num *= constante;
  Serial.println(num);
  delay(500);

                   
}
