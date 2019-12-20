int pinArray[] = {8,9,10,11},count,timer = 100;
void setup() {
for(count=0;count<4;count++){
  pinMode(pinArray[count], OUTPUT);
}
}
void loop() {
 for (count=0;count<3;count++){
  difitalWrite(pinArray[count],HIGH);
  delay(timer);
  difitalWrite(pinArray[count+1],HIGH);
  delay(timer);
  difitalWrite(pinArray[count],LOW);
  delay(timer*2);
 }
for (count=3;count>0;count--){
  difitalWrite(pinArray[count],HIGH);
  delay(timer);
  difitalWrite(pinArray[count - 1],HIGH);
  delay(timer);
  difitalWrite(pinArray[count],LOW);
  delay(timer*2);
 }
}
