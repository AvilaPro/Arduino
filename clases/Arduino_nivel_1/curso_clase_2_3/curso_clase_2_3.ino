//Se utilizo el Arduino Nano, ATMega328P
//Cambio en la intensidad de un LED
//Ahora utilizando al declaracion de una variable.
//Ahora declaramos varias variables y mostramos su manipulacion.

byte intensidad_led = 254;

byte var0 = 10;
int var1 = 500;
String palabra = "Hola";
double var2 = 40000;
float var3 = 1.25;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize digital pin 10 as an output.
  pinMode(10, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  Serial.println(var0);
  Serial.println(var1);
  Serial.println(palabra);
  Serial.println(var2);
  Serial.println(var3);

  delay(3000);
  Serial.println("");

  var0 = var1;
  Serial.println(var0);
  delay(1000);

  var1 = var2;
  Serial.println(var1);
  delay(1000);

  var2 = var3;
  Serial.println(var2);
  delay(3000);
  Serial.println("");

  var0 = 10;
  var1 = 500;
  var2 = 40000;
  
  /*
   * 
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
   * 
   */
                   
}
