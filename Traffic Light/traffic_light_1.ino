int greendelay =0;
int irnear =0;
int irfar=0;
int ledr = 12;
int ledy = 11;
int ledg = 10;
void setup()
{
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
}
void loop()
{
  irnear = digitalRead(4);
  irfar = digitalRead(5);
  if (irnear == HIGH && irfar == HIGH){
    greendelay=5000;}
  else if (irnear == HIGH && irfar == LOW){
    greendelay=2000;}
  else if (irnear == LOW && irfar == LOW){
    greendelay=1000;}
  digitalWrite(10,HIGH);    
  delay(greendelay);
  digitalWrite(10,LOW);
  delay(0); 
  digitalWrite(12,HIGH);
  delay(1000);
  digitalWrite(12,LOW);
  delay(0);
  digitalWrite(11,HIGH);
  delay(1000);
  digitalWrite(11,LOW);
  delay(0);
}