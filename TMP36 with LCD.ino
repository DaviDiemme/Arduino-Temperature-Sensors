// include the library code:
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//******TMP36**********
const int tmp36_pin = A1;

void setup() {
  // set up the number of columns and rows on the LCD
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.clear();
  }

void loop() {
  
  // TMP36
  int tmp36_read = analogRead(tmp36_pin);
  float tmp36_voltage = (tmp36_read / 1024.0) * 5.0;
  float tmp36_tempC = (tmp36_voltage - .5) * 100;

  Serial.print("TEMP36 sensor temperature C: ");
  Serial.println(tmp36_tempC);

  lcd.setCursor(0, 0);
  // print some text
  lcd.print("TEMPERATURE:");
  // move the cursor to the second line
  lcd.setCursor(0, 1);
  lcd.print(tmp36_tempC);
  lcd.write(B11011111); // degree symbol
  lcd.print("C ");

  delay(200);
}