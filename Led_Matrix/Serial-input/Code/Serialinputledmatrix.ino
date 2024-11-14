#include <MD_Parola.h>
#include <MD_MAX72XX.h>
#include <SPI.h>
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4  
#define CS_PIN 10  
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
void setup() {
  Serial.begin(9600);
  myDisplay.begin();
  myDisplay.setIntensity(5);
  myDisplay.displayClear();
  Serial.println("Enter text to display on the LED matrix:");
}
void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    myDisplay.displayClear();
    myDisplay.print(input.c_str());
    Serial.print("Displaying: ");
    Serial.println(input);
    delay(2000);
  }
  if (myDisplay.displayAnimate()) {
    myDisplay.displayReset();
    }
}