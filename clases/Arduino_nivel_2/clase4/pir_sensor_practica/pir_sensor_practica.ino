const int pirPin = 5;
const int ledPin = 13;
int val = 0;
bool motionState = false;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  val = digitalRead(pirPin);
  if(val == HIGH){
    digitalWrite(ledPin, HIGH);
    if (motionState == false){
      Serial.print("Movimiento Detectado");
      motionState = true;
    }
  }
  else{
    digitalWrite(ledPin, LOW);
    if (motioState == true){
      Serial.println("Movimiento Finalizado");
      motionState = false;
    }
  }
}
