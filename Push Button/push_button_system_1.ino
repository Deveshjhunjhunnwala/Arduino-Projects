int buttonstate=0;
int led = 13;
void setup(){
  pinMode(4,INPUT);
  pinMode(led,OUTPUT);
}
void loop(){
  buttonstate = digitalRead(4);
  if (buttonstate == HIGH){
    digitalWrite(led,HIGH);}
  else{
    digitalWrite(led,LOW);}
delay(10);
}