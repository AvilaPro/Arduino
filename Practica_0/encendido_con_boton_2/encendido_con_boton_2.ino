//Controlar el encendido de un led con un boton.

int estado = 0;
int salida = 0; //si la var = 0 significa led off

void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT);  //conf del boton en el puerto 8 como entrada
  pinMode(4, OUTPUT); //conf del puerto del led como salida
}

void loop() {
  // put your main code here, to run repeatedly:
  estado = digitalRead(8);

  if(estado == HIGH){
    salida = 1 - salida;
  }
  
  if(salida == 1){
    digitalWrite(4, HIGH);
  }
  else{
    digitalWrite(4, LOW);
  }
}
