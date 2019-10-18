/*
Hacer un código donde se incrementen cada 50 ms una variable del tipo Byte, y hacer que esa variable 
controle cada 50ms el brillo de un led conectado a uno de los pines PWM del arduino. Imprimir el valor de 
esta variable cada 50ms en el monitor serial a una velocidad de 19200 Baudios. Enviar el codigo para su 
evalucion en archivo TXT
*/

byte intensidad = 0;

void setup() {
  // initialize digital pin 6 PWM as an output.
  pinMode(6, OUTPUT);
  //initialize Serial Port to 19200 Baudios
  Serial.begin(19200);
}

void loop() {
    
    digitalWrite(6, intensidad);   //Se inicia el incremento de la intensidad del Led coectado al pin 6 controlado por la variable intensidad.
    delay(50);
    Serial.println(intensidad);
    delay(50);
    intensidad += 50;
    delay(50); 
    digitalWrite(6, intensidad);   
    delay(50);
    Serial.println(intensidad);
    delay(50);
    intensidad += 50;
    delay(50); 
    digitalWrite(6, intensidad);   
    delay(50);
    Serial.println(intensidad);
    delay(50);
    intensidad += 50;
    delay(50); 
    digitalWrite(6, intensidad);   
    delay(50);
    Serial.println(intensidad);
    delay(50);
    intensidad += 50;
    delay(50); 
    digitalWrite(6, intensidad);   
    delay(50);
    Serial.println(intensidad);
    delay(50);
    intensidad += 50;
    delay(50); 
    digitalWrite(6, intensidad);  
    delay(50);
    Serial.println(intensidad);
    delay(50);

    //delay para reiniciar
    delay(1000);
    //restaurar valor de la variable
    intensidad = 0; 
                   
}