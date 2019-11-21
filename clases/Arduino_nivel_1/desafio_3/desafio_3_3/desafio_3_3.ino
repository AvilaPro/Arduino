//Punto 3 Desafio 3 Arduino seccion 3033
/*
Haga un programa que envíe una pregunta (al estilo 
de quien quiere ser millonario) al usuario por puerto 
serial e emprima en 4 lineas distintas las 4 opciones 
enumeradas de las posibles respuestas (solo una debe ser 
verdadera), el usuario deberá enviar el numero de la 
opción que el crea sea verdadera y el arduino le 
responderá si acertó o no la respuesta.
*/


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Bienvenido al Cuestionario");
Serial.println("");
Serial.println("Pregunta Unica :P");
Serial.println("");
Serial.println("Quien es el presidente de Cadif1?");
Serial.println("Escriba la opcion que considere correcta");
Serial.println("");
Serial.println("1) Jesus Rojas");
Serial.println("2) Yoe Verde");
Serial.println("3) Jose Luis Rojas");
Serial.println("4) La Sra Yolitza");
Serial.println("");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0){
     switch(Serial.read())
  {
    case '1':
      Errado();
      break;
    case '2':
      Errado();
      break;
    case '3':
      Correcto();
      break;
    case '4':
      Errado();
      break;
  }
  }
  
}

void Correcto(){
  Serial.println("");
  Serial.println("Opcion Correcta");
}


void Errado(){
  Serial.println("");
  Serial.println("Opcion Incorrecta");
}
}
