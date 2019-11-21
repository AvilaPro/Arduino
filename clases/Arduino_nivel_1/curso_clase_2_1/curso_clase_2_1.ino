//Se utilizo el Arduino Nano, ATMega328P
//Cambio en la intensidad de un LED

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 10 as an output.
  pinMode(10, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(10, 255);   //Se inicia el degradado de la intensidad del Led coectado al pin 10.
  delay(1500);
  digitalWrite(10, 200);   
  delay(1500); 
  digitalWrite(10, 150);   
  delay(1500); 
  digitalWrite(10, 100);   
  delay(1500); 
  digitalWrite(10, 50);   
  delay(1500); 
  digitalWrite(10, 0);  
  delay(1500); 
                   
}
