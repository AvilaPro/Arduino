#include <SoftwareSerial.h>
$include <String.h>

SoftwareSerial mySerial(7,8);

void setup()
{
    mySerial.begin(19200);
    Serial.begin(19200);
    delay(1000);
}

void loop()
{
    if (Serial.available())
    {
        switch (Serial.read())
        {
            case 's':
                SendTextMessage();
                break;
            case 'n':
                SendTextMessage2();
                break;
            case 'c':
                DialVoiceCall();
                break;
        }
    }
    if (mySerial.available())
    {
        Serial.write(mySerial.read());
    }    
}

void SendTextMessage(){
    mySerial.print("AT+CMGF=1\r");
    delay(100);
    mySerial.println("AT + CMGS = \"+584245142978\"");
    delay(100);
    mySerial.println("La tesis esta cerca XD");
    delay(100);
    mySerial.println((char)26);
    delay(100);
    mySerial.println();
}

void SendTextMessage2(){
    mySerial.print("AT+CMGF=1\r");
    delay(100);
    mySerial.println("AT + CMGS = \"+584245142978\"");
    delay(100);
    mySerial.println("Caso 2 de la tesis");
    delay(100);
    mySerial.println((char)26);
    delay(100);
    mySerial.println();
}

void DialVoiceCall(){
    mySerial.println("ATD + +584245142978;");
    delay(100);
    mySerial.println();
}