#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd(0);
float tempread=0;
float tempprint=0;
float voltage=0;
float temppin=A0;

void setup()
{

  Serial.begin(9600);
}
void loop()
{
  lcd.begin(16,2);

  tempread=analogRead(temppin);
  voltage=tempread*(0.0048875855);
  tempprint=(voltage-0.5)*100;
  Serial.println(tempprint);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("The Temp is:");
  lcd.setCursor(0,1);
  lcd.print(tempprint);
  delay(2000);
  lcd.setBacklight(0);
}