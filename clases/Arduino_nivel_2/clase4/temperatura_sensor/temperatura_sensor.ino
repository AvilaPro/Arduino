//Por Eduardo Mejias
#include <LiquidCrystal.h>

LiquidCrystal LCD(12,11,5,4,3,2);

int SensorTempPino=0;
int AlertaTempBaixa=8;
int AlertaTempAlta=13;
int TempBaixa=23;
int TempAlta=24;

void setup() {
  Serial.begin(9600);
     pinMode(AlertaTempBaixa, OUTPUT);
  pinMode(AlertaTempAlta, OUTPUT);
    LCD.clear();
    LCD.begin(16,2);
  LCD.print(" Eduardo Mejias");
    
}

void loop() { 
  
  int SensorTempTensao=analogRead(SensorTempPino);
  Serial.print(SensorTempTensao);
  float Tensao=SensorTempTensao*5;
  Tensao/=1024;
    float TemperaturaC=(Tensao-0.5)*100;   
    LCD.setCursor(0,1);
  LCD.print(TemperaturaC);  
    LCD.setCursor(7,1);   
  LCD.print("Celsius");   
    delay(1000);
    LCD.clear();
     
   if (TemperaturaC>TempAlta) { 
        LCD.setCursor(1,0);
        LCD.print("   ALERTA!");
        delay(1000);
        LCD.clear();
      digitalWrite(AlertaTempBaixa, LOW);
      digitalWrite(AlertaTempAlta, HIGH);
        LCD.setCursor(0,1);
        LCD.print(" ESTA CALIENTE!");      
        delay(1000);
        LCD.clear();
  
    }
    else if (TemperaturaC<TempBaixa){
        LCD.setCursor(1,0);
        LCD.print("   ALERTA!");
        delay(1000);
        LCD.clear();       
      digitalWrite(AlertaTempBaixa, HIGH);
      digitalWrite(AlertaTempAlta, LOW); 
        LCD.setCursor(0,1);
        LCD.print("   ESTA FRIO!");      
        delay(1000);
        LCD.clear();
    }
    else {
    
      digitalWrite(AlertaTempBaixa, LOW);
      digitalWrite(AlertaTempAlta, LOW);      
    
    }

    delay(1000);   
    
}
