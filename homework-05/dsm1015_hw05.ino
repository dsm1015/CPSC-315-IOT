/*
    *  Homework 5 - Digital Dice
    *  Author: Douglas Maxwell
    *  Date: 2024-03-12
    * 
    *  Description: This program simulates a digital dice using a 7-segment display and a push button.
*/

// Button pin for reading
#define BUTTON_PIN 10

// Pins for the 7-segment display
int pins[] = {2,3,4,5,6,7,8};

// Array for the digits, each digit is represented by a 7-bit number
int digits[][7] = {
    //a, b, c, d, e, f, g
    {0, 1, 1, 0, 0, 0, 0}, //digit 1
    {1, 1, 0, 1, 1, 0, 1}, //digit 2
    {1, 1, 1, 1, 0, 0, 1}, //digit 3
    {0, 1, 1, 0, 0, 1, 1}, //digit 4
    {1, 0, 1, 1, 0, 1, 1}, //digit 5
    {1, 0, 1, 1, 1, 1, 1}, //digit 6
};

// Function to clear the 7-segment display
void clear() {
  for (int i=0; i<7; i++) {
      digitalWrite(pins[i], LOW);
    }
}

// Function to show a random digit on the 7-segment display. Loop through the elements of the digit array and set the corresponding pin to the value of the digit array.
void showRandom(int r) {
  for (int i=0; i<7; i++) {
    digitalWrite(pins[i], digits[r-1][i]);
  }
}

void setup() {
    // put your setup code here, to run once:
    for (int i=0; i<7; i++) {
      pinMode(pins[i], OUTPUT);
      clear();
    }
    pinMode(BUTTON_PIN, INPUT);
    randomSeed(analogRead(0));
}

// Variable to store the random number
int d = 0;

/*
* The loop function will read the value from the push button. If it is pushed, it will generate a random number between 1 and 6 and show it on the 7-segment display.
* If the button is not pushed, it will keep showing the last generated number.
*/
void loop() {
    // put your main code here, to run repeatedly:
    if (digitalRead(BUTTON_PIN) == HIGH) {
        d = random(1, 7);
        showRandom(d);
    }
    else {
      showRandom(d);
    }
    delay(200);
}