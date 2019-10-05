#include <SoftwareSerial.h>
SoftwareSerial mySerial(18, 19); //Mega 2560 pin 18 RX al TX5 del sim900a mini y Mega 2560 pin 19 TX al RX5 del sim900a mini
char msg;
char call;

void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  Serial.println("GSM SIM900A BEGIN");
  Serial.println("Enter character for control option:");
  Serial.println("h : to disconnect a call");
  Serial.println("i : to receive a call");
  Serial.println("s : to send message");
  Serial.println("c : to make a call");  
  Serial.println("e : to redial");
  Serial.println();
  delay(100);
}

void loop()
{  
  if (Serial.available()>0)
   switch(Serial.read())
  {
    case 's':
      SendMessage();
      break;
    case 'c':
      MakeCall();
      break;
    case 'h':
      HangupCall();
      break;
    case 'e':
      RedialCall();
      break;
    case 'i':
      ReceiveCall();
      break;
  }
 if (mySerial.available()>0)
 Serial.write(mySerial.read());
}

void SendMessage()
{
  Serial.println("entro a enviar sms"); //para ver si entra al proceso.
  mySerial.println("AT+CMGF=1\r");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+584245142978\"\r"); // Aqui el numero de telefono
  delay(1000);
  mySerial.println("prueba 1 confirmado Yeah");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}

void ReceiveMessage()
{
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to recieve a live SMS
  delay(1000);
  if (mySerial.available()>0)
  {
    msg=mySerial.read();
    Serial.print(msg);
  }
}

void MakeCall()
{
  Serial.println("entro a Llamar"); //para ver si entra al proceso.
  mySerial.println("ATD+584245142978;"); // ATDxxxxxxxxxx; -- watch out here for semicolon at the end!!
  Serial.println("Calling  "); // print response over serial port
  delay(1000);
}


void HangupCall()
{
  mySerial.println("ATH");
  Serial.println("Hangup Call");
  delay(1000);
}

void ReceiveCall()
{
  mySerial.println("ATA");
  delay(1000);
  {
    call=mySerial.read();
    Serial.print(call);
  }
}

void RedialCall()
{
  mySerial.println("ATDL");
  Serial.println("Redialing");
  delay(1000);
}
