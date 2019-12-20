int led=9;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  encenderLed(led);
  apagarLed(led);
}

void encenderLed(int led){
  Serial.print("Encendiendo LED...");
  digitalWrite(led, HIGH);
}

void apagarLed(int led){
  Serial.print("Apagando LED...");
  digitalWrite(led, LOW);
}
