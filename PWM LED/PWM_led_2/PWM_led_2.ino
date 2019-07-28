
const int led = 3; //led conectado al pin 3
const int pot = 0; //potenciometro conectado al pin 0

int brillo;

void setup() {
  pinMode(led, OUTPUT); //declaracion del LED como salida
}

void loop() {
  brilo = analogRead(pot / 4); //el analogRead nos devuelve entre 0 y 1023
  analogWrite(led, brillo); //por ello dividimos entre 4 ya que el analogWrite es entre 0 y 254.

  
  //seccion de PWM_led_1
  /*for(brillo = 0, brillo < 256, brillo ++){
    analogWrite(led, brillo);
    delay(10);
  }
  for(brillo = 255, brillo >= 0, brillo --){
    analogWrite(led, brillo);  
    delay(10);
  }*/
  

}
