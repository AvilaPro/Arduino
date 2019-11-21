/* T09_7 segmentos

  Este sketch realiza un contador del 0 al 9 
  usando un display de 7 segmentos y dos botones
  uno para incrementar y otro para decrementar.
  */

const int a = 2;  // segmentos del display
const int b = 3;
const int c = 4;
const int d = 5;
const int e = 6;
const int f = 7;
const int g = 8;
const int botonIncremento = 9;
const int botonDecremento = 10;

const int tiempoAntirebote = 10;
int cuenta = 0;
int estadoBotonIncremento;
int estadoBotonAnteriorIncremento;
int estadoBotonDecremento;
int estadoBotonAnteriorDecremento;

boolean antirebote(int pin) {
  int contador = 0;
  boolean estado;
  boolean estadoAnterior;
  
  do {
    estado = digitalRead(pin);
    if(estado != estadoAnterior) {
      contador = 0;
      estadoAnterior = estado;
    }
    else {
      contador = contador + 1;
    }
    delay(1);
  } while(contador < tiempoAntirebote);
  
  return estado;
}

void actualizarNumero() {
  switch(cuenta) {
    case 0:
    digitalWrite(a, HIGH);  // 0
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  break;
  
    case 1:
    digitalWrite(a, LOW);  // 1
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  break;
  
    case 2:
    digitalWrite(a, HIGH);  // 2
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
  break;
  
    case 3:
     digitalWrite(a, HIGH);  // 3
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
  break;
  
    case 4:
    digitalWrite(a, LOW);  // 4
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  break;
  
    case 5:
    digitalWrite(a, HIGH); // 5
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  break;
  
    case 6:
    digitalWrite(a, HIGH);  // 6
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  break;
  
    case 7:
    digitalWrite(a, HIGH);  // 7
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  break;
  
    case 8:
    digitalWrite(a, HIGH);  // 8
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  break;
  
    case 9:
    digitalWrite(a, HIGH);  // 9
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  break;
  
  }
}


void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(botonIncremento, INPUT);
  pinMode(botonDecremento, INPUT);
}

void loop() {
  estadoBotonIncremento = digitalRead(botonIncremento);
  if(estadoBotonIncremento !=estadoBotonAnteriorIncremento) {
    if(antirebote(botonIncremento)) {
      cuenta++;
      if(cuenta > 9) {
        cuenta = 9;
      }
    }
  }
  estadoBotonAnteriorIncremento = estadoBotonIncremento;
  
  estadoBotonDecremento = digitalRead(botonDecremento);
  if(estadoBotonDecremento !=estadoBotonAnteriorDecremento) {
    if(antirebote(botonDecremento)) {
      cuenta--;
      if(cuenta < 0) {
        cuenta = 0;
      }
    }
  }
  estadoBotonAnteriorDecremento = estadoBotonDecremento;
  
  actualizarNumero();
}
