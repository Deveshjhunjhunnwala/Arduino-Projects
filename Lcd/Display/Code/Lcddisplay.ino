#include <LiquidCrystal.h>

// Initialize LCD pins
// RS=12, EN=11, D4=5, D5=4, D6=3, D7=2
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Potentiometer pin for brightness control
const int potPin = A0;

// LCD contrast pin
const int contrastPin = 6;

void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  
  // Set up the contrast pin as output
  pinMode(contrastPin, OUTPUT);
  
  // Print the message
  lcd.print("Hello, World!");
}

void loop() {
  // Read the potentiometer value (0-1023)
  int potValue = analogRead(potPin);
  
  // Map the potentiometer value to LCD brightness range (0-255)
  int brightness = map(potValue, 0, 1023, 0, 255);
  
  // Set the LCD brightness
  analogWrite(contrastPin, brightness);
  
  // Small delay to stabilize readings
  delay(100);
}