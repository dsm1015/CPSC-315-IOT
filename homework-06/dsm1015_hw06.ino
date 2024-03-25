/*
    *  Homework 6 - Digital Thermometer
    *  Author: Douglas Maxwell
    *  Date: 2024-03-25
    * 
    *  Description: This program reads the temperature and humidity from a DHT11 sensor and displays it on an LCD screen.
*/

// include the library code:
#include <LiquidCrystal.h>
#include <DHTStable.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// create an instance of the DHTStable class
DHTStable dht;

// define the pin for the DHT11 sensor
const int DHT11_PIN = 3;

// define the custom character for the degree symbol
byte degree[] = {
    B01110,
    B01010,
    B01110,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000
};

void setup() {
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);

    // create a custom character for the degree symbol with integer value 1
    lcd.createChar(1, degree);

    lcd.clear();
}

// Function to convert temperature from Celsius to Fahrenheit
float celsiusToFahrenheit(float temp) {
    return ((temp * 9) / 5) + 32;
}

/*
* The loop function will read the temperature and humidity from the DHT11 sensor and display it on the LCD screen.
* It will use the DHTStable library to read the values from the sensor and convert the temperature from Celsius to Fahrenheit.
* The temperature and humidity values will be displayed on the LCD screen with a delay of 5 seconds between readings.
*/
void loop() {
    lcd.clear();

    int chk = dht.read11(DHT11_PIN);

    float temp = dht.getTemperature();
    int humidity = dht.getHumidity();
    temp = celsiusToFahrenheit(temp);
  
    String tempString = "Temp: " + String(temp) + (char)1 + "F";
    String humidityString = "Humidity: " + String(humidity) + "%";
  
    lcd.setCursor(0,0);
    lcd.print(tempString);
    lcd.setCursor(0,1);
    lcd.print(humidityString);
    
    delay(5000);
}
