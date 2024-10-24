// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//******KY-013*********
int ky_pin = A0;
float ky_R1 = 10000; // value of R1 on board
float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741; //steinhart-hart coeficients for thermistor


void setup() {
  // set up the number of columns and rows on the LCD
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.clear();
  }

void loop() {
  
  // KY-013
  float ky_read = analogRead(ky_pin);
  float ky_R2 = ky_R1 * (1023.0 / (float)ky_read - 1.0); //calculate resistance on thermistor
  ky_R2 = ky_R2/10;
  float ky_logR2 = log(ky_R2);
  float ky_tempC = (1.0 / (c1 + c2*ky_logR2 + c3*ky_logR2*ky_logR2*ky_logR2)); // temperature in Kelvin
  ky_tempC = ky_tempC - 273.15; //convert Kelvin to Celcius

  Serial.print("KY-013 sensor temperature C: ");
  Serial.println(ky_tempC);

  lcd.setCursor(0, 0);
  // print some text
  lcd.print("TEMPERATURE:");
  // move the cursor to the second line
  lcd.setCursor(0, 1);
  lcd.print(ky_tempC);
  lcd.write(B11011111); // degree symbol
  lcd.print("C ");

  delay(200);
}