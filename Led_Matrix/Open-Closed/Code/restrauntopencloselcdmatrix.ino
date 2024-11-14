#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 10

MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
int buttonState = 0; // Variable to store the state of the switch

void setup() {
  pinMode(7, INPUT); // Set pin 7 as input for the switch
  myDisplay.begin();
  myDisplay.setIntensity(4);
  myDisplay.displayClear();
}

void loop() {
  buttonState = digitalRead(7); // Read the switch state

  if (buttonState == HIGH) { // If switch is ON (3.3V)
    myDisplay.displayClear();
    myDisplay.displayScroll("OPEN", PA_CENTER, PA_SCROLL_LEFT, 90);
    while (!myDisplay.displayAnimate()); // Loop to complete the scrolling effect
  } else { // If switch is OFF (0V or ground)
    myDisplay.displayClear();
    myDisplay.displayScroll("CLOSE", PA_CENTER, PA_SCROLL_LEFT, 90);
    while (!myDisplay.displayAnimate()); // Loop to complete the scrolling effect
  }
}
