//Se utilizo el Arduino Nano, ATMega328P
//Cambio en la intensidad de un LED
//Ahora utilizando al declaracion de una variable.

byte intensidad_led = 254;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 10 as an output.
  pinMode(10, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(10, intensidad_led);   //Se inicia el degradado de la intensidad del Led coectado al pin 10.
  delay(1000);
  intensidad_led = intensidad_led - 50;
  digitalWrite(10, intensidad_led);   
  delay(1000); 
  intensidad_led = intensidad_led - 50;
  digitalWrite(10, intensidad_led);   
  delay(1000); 
  intensidad_led = intensidad_led - 50;
  digitalWrite(10, intensidad_led);   
  delay(1000); 
  intensidad_led = intensidad_led - 50;
  digitalWrite(10, intensidad_led);   
  delay(1000); 
  intensidad_led = intensidad_led - 48;
  digitalWrite(10, intensidad_led);  
  delay(1000); 
  intensidad_led = 254;
                   
}
