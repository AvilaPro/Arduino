int pinMatriz[2][2] =  {
  {11,10},
  {9,8}
}
int filas = 2, columnas = 2;
void setup(){
  for(int i, i < filas, i++){
    for(int j, j< columnas, j++){
      pinMode(pinMatriz[i][j], OUTPUT);
    }
  }
}

void loop(){
  digitalWrite(pinMatriz[0][0], HIGH);

  while(true);
}
