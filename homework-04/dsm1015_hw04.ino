/*
    *  Homework 4 - Potentiometer
    *  Author: Douglas Maxwell
    *  Date: 2024-03-04
    * 
    *  Description: This program reads the value from a potentiometer and uses it to control the brightness of an LED.
*/

// Constants for the pin numbers
#define POTENTIOMETER_PIN A1
#define LED_PIN 3

// Constant for the PWM step
// 255 is the max value for PWM, (1023/2) is the max value for analogRead with the 10k resistor. 
// The volatage of the potentiometer is about 2.5V.
const float PWM_STEP = 255.0 / (1023 / 2);

void setup() {
    // put your setup code here, to run once:
    pinMode(POTENTIOMETER_PIN, INPUT); // set the potentiometer pin as input
    pinMode(LED_PIN, OUTPUT); // set the LED pin as output
    Serial.begin(9600); // start the serial monitor
}

/* The loop function will read the value from the potentiometer and use it to control the brightness of the LED. 
* In order to convert the potentiometer value to the PWM value, I will use the PWM_STEP variable as a scaling factor.
* Finally, I will write the PWM value to the LED and print the potentiometer value and the PWM value to the serial monitor.
*/
void loop() {
    // put your main code here, to run repeatedly:
    int potValue = analogRead(POTENTIOMETER_PIN); // read the value from the potentiometer
    int ledValue = potValue * PWM_STEP; // scale the potentiometer value to the PWM value

    analogWrite(LED_PIN, ledValue); // write the PWM value to the LED

    // print the potentiometer value and the PWM value to the serial monitor
    Serial.print("Sensor Value: ");
    Serial.print(potValue);
    Serial.print(", PWM Value: ");
    Serial.println(ledValue);
    
    // add a short delay to the loop
    delay(100);
}