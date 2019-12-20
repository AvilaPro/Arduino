#include <DHT.h>
#include <DHT_U.h>

DHT dht(2, DHT22);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

}
