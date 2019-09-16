const int boton=4;                 //boton conectado al pin 4
 const int tiempoAntirebote=10;

 int cuenta=0;                       //lleva la cuenta de las veces que presionamos el boton
 int estadoBoton;
 int estadoBotonAnterior;
 
 boolean antirebote(int pin){
    int contador=0;
    boolean estado;               //guarda el estado del boton
    boolean estadoAnterior;       //guarda el ultimo estado del boton

  do{
    estado=digitalRead(pin);
    if(estado != estadoAnterior){   //comparamos el estado actual con el anterior
      contador=0;                   //reiniciamos el contador
      estadoAnterior = estado;
    }
    else{
      contador=contador+1;          //aumentamos el contador en 1
    }
    delay(1);
  }while(contador<tiempoAntirebote);
  
  return estado;
 }
void setup() {
  Serial.begin(9600);               //iniciamos la comunicacion serial
  pinMode(boton, INPUT);            //declaramos el boton como entrada
}

void loop() {
  estadoBoton=digitalRead(boton);     //leemos el estado del boton

  if(estadoBoton != estadoBotonAnterior){   //si hay cambio con respecto al estado anterior
    if(antirebote(boton)){                  //checamos si esta presionado y si lo esta
      cuenta++;                             //aumentamos la cuenta
      Serial.println(cuenta);
    }
  }

  estadoBotonAnterior=estadoBoton;
}
