
const int led = 3; //led conectado al pin 3

int brillo;

void setup() {
  pinMode(led, OUTPUT); //declaracion del LED como salida
}

void loop() {
  for(brillo = 0, brillo < 256, brillo ++){
    analogWrite(led, brillo);
    delay(10);
  }
  for(brillo = 255, brillo >= 0, brillo --){
    analogWrite(led, brillo);  
    delay(10);
  }

}
