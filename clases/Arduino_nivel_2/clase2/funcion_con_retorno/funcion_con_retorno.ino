int valor

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("La nota generada es: ", int valor=valorAleatorio());
  if(compararValor(valor)==true){
    Serial.println("Aprobo");
  }
  if (compararValor(valor)==false){
    Serial.println("Reprobado");
  }
}

int valorAleatorio(){
  int valor = random(100);
  return valor;
}

bool compararValor(int valor){
  return valor>=50;
}
