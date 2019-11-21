/*
Una empresa tiene un calefactor que se le daño su modulo de 
control de temperatura, lo contactan a usted para que con un 
arduino pueda resolver el problema. Tienen un sensor de 
temperatura de -100 a 100 grados centigrados que arroja un 
voltaje entre 0 y 5v respectivamente (0V a -100 grados C y 5v a 
100 grados C). Y tiene una resistencia que genera calor y se 
enciende con una salida digital de 5v que pude ser conectada a 
cualquier pin digital del Arduino. Con todo esto se le pide que 
haga un controlador de temperatura que encienda la resistencia y 
mida la temperatura cuando la temperatura medida supere los 
51grados apague la resistencia y cuando este por debajo de 49 
grados la vuelva a encender para mantener la temperatura en 
promedio en 50 grados centigrados
*/

//Se trabajo en clases con un Arduino Nano (Old Bootloader).

const int sensorPin = A0; //Pin donde se conectara el sensor de temperatura descrito
const int resCal = 9; //Pin donde se conectara la resistencia de calor indicada en el enunciado


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(resCal, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(analogRead(sensorPin) > 767){
    digitalWrite (resCal, HIGH);
    }
  while(analogRead(sensorPin) <= 767){
    digitalWrite (resCal, LOW);
    }
 
}
