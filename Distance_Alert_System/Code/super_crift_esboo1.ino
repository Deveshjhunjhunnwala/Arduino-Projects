#define TRIG 12
#define ECHO 11
#define Red 5
#define Yellow 6
#define Green 7

void setup() {
  Serial.begin(9600);  
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(Red, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Green, OUTPUT);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);
  
  float distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance > 25 && distance < 50) {
    digitalWrite(Green, HIGH);
    delay(500);
    digitalWrite(Green, LOW);
    digitalWrite(Red, LOW);
  } 
  if (distance > 10 && distance <= 25) {
    digitalWrite(Yellow, HIGH);
    delay(500);
    digitalWrite(Yellow, LOW);
    digitalWrite(Red, LOW);
  }
  if (distance <= 10) {
    digitalWrite(Red, HIGH);
  }

}
