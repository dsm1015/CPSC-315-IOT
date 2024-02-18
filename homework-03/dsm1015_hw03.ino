/*
    *  Homework 3 - Traffic Light
    *  Author: Douglas Maxwell
    *  Date: 2024-02-19
    * 
    *  Description: This program simulates a traffic light at an intersection.
*/

// Constants for the pin numbers for Apple Ave
const int APPLE_AVE_RED = 5;
const int APPLE_AVE_YELLOW = 6;
const int APPLE_AVE_GREEN = 7;

// Constants for the pin numbers for Peach St
const int PEACH_ST_RED = 8;
const int PEACH_ST_YELLOW = 9;
const int PEACH_ST_GREEN = 10;

// Constants for the timing of the lights
const int GREEN_AND_RED_LIGHT_TIME = 10000; // 10 seconds
const int YELLOW_LIGHT_TIME = 2000; // 2 seconds

// Here I will set the pin modes for the traffic lights to OUTPUT
void setup() {
  // put your setup code here, to run once:
  pinMode(APPLE_AVE_RED, OUTPUT);
  pinMode(APPLE_AVE_YELLOW, OUTPUT);
  pinMode(APPLE_AVE_GREEN, OUTPUT);

  pinMode(PEACH_ST_RED, OUTPUT);
  pinMode(PEACH_ST_YELLOW, OUTPUT);
  pinMode(PEACH_ST_GREEN, OUTPUT);
}

/*
* The loop function will control the traffic lights.
* The sequence is possible by using the delay function to control the timing of the lights.
* The traffic light on Apple Ave will be green for 10 seconds, then yellow for 2 seconds, then red for 10 seconds.
* Meanwhile, The traffic light on Peach St will be red for 10 seconds, then green for 10 seconds, then yellow for 2 seconds.
* This will repeat indefinitely.
*
*/
void loop() {
  // Step 1: Green on Apple Ave, Red on Peach St
  digitalWrite(APPLE_AVE_GREEN, HIGH);
  digitalWrite(APPLE_AVE_YELLOW, LOW);
  digitalWrite(APPLE_AVE_RED, LOW);
  digitalWrite(PEACH_ST_GREEN, LOW);
  digitalWrite(PEACH_ST_YELLOW, LOW);
  digitalWrite(PEACH_ST_RED, HIGH);
  delay(GREEN_AND_RED_LIGHT_TIME); // 10 seconds
  
  // Step 2: Yellow on Apple Ave, Red on Peach St
  digitalWrite(APPLE_AVE_GREEN, LOW);
  digitalWrite(APPLE_AVE_YELLOW, HIGH);
  delay(YELLOW_LIGHT_TIME); // 2 seconds
  
  // Step 3: Red on Apple Ave, Green on Peach St
  digitalWrite(APPLE_AVE_YELLOW, LOW);
  digitalWrite(APPLE_AVE_RED, HIGH);
  digitalWrite(PEACH_ST_RED, LOW);
  digitalWrite(PEACH_ST_GREEN, HIGH);
  delay(GREEN_AND_RED_LIGHT_TIME); // 10 seconds
  
  // Switch to Yellow on Peach St
  digitalWrite(PEACH_ST_GREEN, LOW);
  digitalWrite(PEACH_ST_YELLOW, HIGH);
  delay(YELLOW_LIGHT_TIME); // 2 seconds

  // Reset to the beginning
  digitalWrite(PEACH_ST_YELLOW, LOW);
  digitalWrite(PEACH_ST_RED, HIGH);

}
