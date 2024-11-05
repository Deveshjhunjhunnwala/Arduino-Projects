int buzzerstate=0;
int buzzer = 12;
void setup(){
  pinMode(8,INPUT);
  pinMode(buzzer,OUTPUT);
}
void loop(){
  buzzerstate = digitalRead(8);
  if (buzzerstate == HIGH){
    digitalWrite(buzzer,HIGH);}
  else{
    digitalWrite(buzzer,LOW);}
delay(10);
}