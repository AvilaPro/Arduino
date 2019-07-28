const int ledRojo = 3; 
const int ledVerde = 5;
const int ledAzul =6;
const int potRojo = 0;
const int potVerde = 1;
const int potAzul = 2;

int rojo;
int verde;
int azul;

void setup() {
  Serial.begin(9600); //con esto le decimos a arduino que usaremos la comunicacion serial
                      //9600 es la tasa de baudios o bps(bit por seg) para que nose pierda ningun bit en la comunicacion
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
}

void loop() {
  rojo = analogRead(potRojo) / 4;
  verde = analogRead(potVerde) / 4;
  azul = analogRead(potAzul) / 4;

  analogWrite(ledRojo, rojo);   //encendemos cada led segun la intensidad del potenciomentro correspondiente
  analogWrite(ledVerde, verde);
  analogWrite(ledAzul, azul);

  Serial.print("Rojo: ");
  Serial.print(rojo);
  Serial.print(", ");

  
  Serial.print("Verde: ");
  Serial.print(verde);
  Serial.print(", ");

  
  Serial.print("Azul: ");
  Serial.println(azul); //println para que haga el salto de linea

  delay(500); //para poder visualizar los cambios de valor ya que a 9600bps es muy rapido el cambio
}
