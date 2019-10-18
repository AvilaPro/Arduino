/*
1.- Hacer el código en arduino para enviar el código SOS a través del parpadeo del led conectado al pin D8. 

Enviar el código para evaluarlo en archivo TXT. Para conocer mas detalles del codigo SOS ver este link. 

https://es.wikipedia.org/wiki/SOS
*/

void setup()
{
    pinMode(8, OUTPUT);
}

void loop()
{
    //primeros tres puntos
    digitalWrite(8, HIGH);
    delay(500);
    digitalWrite(8, LOW);
    delay(500);
    digitalWrite(8, HIGH);
    delay(500);
    digitalWrite(8, LOW);
    delay(500);
    digitalWrite(8, HIGH);
    delay(500);
    digitalWrite(8, LOW);
    delay(500);
    //siguientes tres guiones
    digitalWrite(8, HIGH);
    delay(1000);
    digitalWrite(8, LOW);
    delay(500);
    digitalWrite(8, HIGH);
    delay(1000);
    digitalWrite(8, LOW);
    delay(500);
    digitalWrite(8, HIGH);
    delay(1000);
    digitalWrite(8, LOW);
    delay(500);
    //ultimos tres puntos
    digitalWrite(8, HIGH);
    delay(500);
    digitalWrite(8, LOW);
    delay(500);
    digitalWrite(8, HIGH);
    delay(500);
    digitalWrite(8, LOW);
    delay(500);
    digitalWrite(8, HIGH);
    delay(500);
    digitalWrite(8, LOW);
    delay(500);
    //espera para reenviar mensaje luego de 10.000 mS 
    delay(10000);

}