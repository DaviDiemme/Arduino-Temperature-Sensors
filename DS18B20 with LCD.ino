// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//******DS18B20********
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 7

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature ds18b20(&oneWire);
float ds_tempC = 0;


void setup() {
  // set up the number of columns and rows on the LCD
  lcd.begin(16, 2);
  ds18b20.begin();
  Serial.begin(9600);
  lcd.clear();
  }

void loop() {
  
  // DS18B20
  ds18b20.requestTemperatures(); 
  ds_tempC = ds18b20.getTempCByIndex(0);

  Serial.print("DS18B20 sensor temperature C: ");
  Serial.println(ds_tempC);

  lcd.setCursor(0, 0);
  // print some text
  lcd.print("TEMPERATURE:");
  // move the cursor to the second line
  lcd.setCursor(0, 1);
  lcd.print(ds_tempC);
  lcd.write(B11011111); // degree symbol
  lcd.print("C ");

  delay(200);
}