/*
SMS sender

created 25 Feb 2012
Originally written by Tom Igoe
But this is modified version
*/

//Si la targeta GSM tuviera PIN se usaria este programa con el uso del PIN de dicha tarjeta SIM.
//El proyecto 

// Include the GSM library
#include <GSM.h>
#include <SoftwareSerial.h> //incluido luego para ver si no me da error el Serial.
#define PINNUMBER "0000"

// initialize the library instance
GSM gsmAccess;
GSM_SMS sms;

void setup(){
// initialize serial communications and wait for port to open:
Serial.begin(9600);
while (!Serial){
; // wait for serial port to connect. Needed for Leonardo only
}
Serial.println("SMS Messages Sender");
// connection state
boolean notConnected = true;

// Start SIM900A GSM 

while (notConnected){
    Serial.println("Status 1: Please wait a while, If it taking lot of time, \nmeans you have wrong pin connections.");
    // If your SIM has PIN, pass it as a parameter of begin() in quotes
    if (gsmAccess.begin(PINNUMBER) == GSM_READY){
    Serial.println("Status 2: GSM is ready.");
    notConnected = false;
}else{
    Serial.println("Status 3: Not connected");
    delay(1000);
  }
}
    Serial.println("Status 4: GSM initialized. " );

    // calling function to send message
    sendMessage();
}

void loop(){
    // empty loop
}

// method to send message to specific number just once.
void sendMessage(){
    Serial.print("Message is sending...: ");
    // send the message
    sms.beginSMS("+584245142978"); // Replace XXXXXXX with your mobile number.
    sms.print("Envio SMS Exitoso"); // Message content, replace with your's.
    sms.endSMS();
    Serial.println("COMPLETE!\n");
    Serial.println("Message Sent...!\n");
}
