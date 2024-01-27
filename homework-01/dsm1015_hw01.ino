
/*
    *  Homework 1 SOS
    *  Author: Douglas Maxwell
    *  Date: 2024-01-27
    * 
    *  Description: This program will blink the LED on the Arduino board in the pattern of SOS.
    *  The LED will blink 3 short blinks, 3 long blinks, and 3 short blinks. The LED will then
    *  pause for 1 second and repeat the pattern.
    * 
*/

/*
  These constants are used to define the delay times for the short and long blinks.
*/
const int SHORT_DELAY = 250;
const int LONG_DELAY = 750;
const int PAUSE_DELAY = 250; // This is the delay between blinks

/*
  In my setup function I set the pin mode to output for the LED. I then set the LED to LOW to
  ensure that the LED is off when the program starts.
*/
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

/* 
  In my loop function I set the LED to HIGH for 250 milliseconds and then LOW for 250 milliseconds
  to create the short blink. I repeat the short blink 3 times. I then set the LED to HIGH for 750 milliseconds and then LOW for 250
  milliseconds to create the long blink. I repeat the long blink 3 times. After the long blinks, 
  I repeat the short blinks 3 times. There is a 250 millisecond delay between each blink.
  I then set the LED to LOW for 1000 milliseconds to create the pause. I then repeat the pattern.
*/
void loop() {

  // SHORT BLINK
  digitalWrite(LED_BUILTIN, HIGH);
  delay(SHORT_DELAY);
  digitalWrite(LED_BUILTIN, LOW);

  delay(PAUSE_DELAY);

  // SHORT BLINK
  digitalWrite(LED_BUILTIN, HIGH);
  delay(SHORT_DELAY);
  digitalWrite(LED_BUILTIN, LOW);

  delay(PAUSE_DELAY);

  // SHORT BLINK
  digitalWrite(LED_BUILTIN, HIGH);
  delay(SHORT_DELAY);
  digitalWrite(LED_BUILTIN, LOW);

  delay(PAUSE_DELAY);

  // LONG BLINK
  digitalWrite(LED_BUILTIN, HIGH);
  delay(LONG_DELAY);
  digitalWrite(LED_BUILTIN, LOW);

  delay(PAUSE_DELAY);

  // LONG BLINK
  digitalWrite(LED_BUILTIN, HIGH);
  delay(LONG_DELAY);
  digitalWrite(LED_BUILTIN, LOW);

  delay(PAUSE_DELAY);

  // LONG BLINK
  digitalWrite(LED_BUILTIN, HIGH);
  delay(LONG_DELAY);
  digitalWrite(LED_BUILTIN, LOW);

  delay(PAUSE_DELAY);

  // SHORT BLINK
  digitalWrite(LED_BUILTIN, HIGH);
  delay(SHORT_DELAY);
  digitalWrite(LED_BUILTIN, LOW);

  delay(PAUSE_DELAY);

  // SHORT BLINK
  digitalWrite(LED_BUILTIN, HIGH);
  delay(SHORT_DELAY);
  digitalWrite(LED_BUILTIN, LOW);

  delay(PAUSE_DELAY);

  // SHORT BLINK
  digitalWrite(LED_BUILTIN, HIGH);
  delay(SHORT_DELAY);
  digitalWrite(LED_BUILTIN, LOW);

  // RESET
  delay(1000);
}