/*
5.- Hacer el codigo de un semaforo, se deben usar tres pines del arduino, en D3 se conectara un led verde, 
en D4 led amarillo y en D5 un led rojo, el programa debe encender el led verde durante 5 segundos luego 
apagarlo y prender el amarillo por 2 seg y luego apagarlo y encender el rojo por 3 seg, para luego comenzar 
el ciclo nuevamente. Simular ese ejercicio en tinker cad y enviar el código fuente y capturas de pantalla de 
la simulacion.
*/


void setup()
{
    //pin led verde
    pinMode(3, OUTPUT);
    //pin led amarillo
    pinMode(4, OUTPUT);
    //pin led rojo
    pinMode(5, OUTPUT);
}

void loop()
{   
    //enciende led verde
    digitalWrite(3, HIGH);
    delay(5000);
    //se apaga led verde
    digitalWrite(3, LOW);
    delay(50);
    //enciende led amarillo
    digitalWrite(4, HIGH);
    delay(2000);
    //se apaga led amarillo
    digitalWrite(4, LOW);
    delay(50);
    //enciende led rojo
    digitalWrite(5, HIGH);
    delay(3000);
    //se apaga led rojo
    digitalWrite(5, LOW);
    delay(50);
    
}