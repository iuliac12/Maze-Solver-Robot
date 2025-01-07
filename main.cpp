#include <Arduino.h>

// Define pins for motors
#define ENA 6   // Speed control for Motor A
#define IN1 8   // Direction control for Motor A
#define IN2 9   // Direction control for Motor A

#define ENB 5   // Speed control for Motor B
#define IN3 2   // Direction control for Motor B
#define IN4 4   // Direction control for Motor B

// Define pins for ultrasonic sensors
#define S1Trig A0 // Trig pin for left ultrasonic sensor
#define S1Echo A3 // Echo pin for left ultrasonic sensor
#define S2Trig A1 // Trig pin for front ultrasonic sensor
#define S2Echo A4 // Echo pin for front ultrasonic sensor
#define S3Trig A2 // Trig pin for right ultrasonic sensor
#define S3Echo A5 // Echo pin for right ultrasonic sensor

// Define pin for button
#define BUTTON_PIN 10 // Pin connected to the button

// Threshold for detecting obstacles
#define FRONT_OBSTACLE_DIST 12 // Threshold distance for front obstacle detection (in cm)

/* 
 * Function to measure distance using an ultrasonic sensor
 * Parameters:
 * - trigPin: Pin connected to the Trig pin of the sensor
 * - echoPin: Pin connected to the Echo pin of the sensor
 * Returns: Measured distance in centimeters
 */
int readUltrasonic(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);        // Ensure the Trig pin is LOW
  delayMicroseconds(2);              // Wait for 2 microseconds
  digitalWrite(trigPin, HIGH);       // Send a HIGH signal for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);        // Set the Trig pin back to LOW

  long duration = pulseIn(echoPin, HIGH); // Measure the pulse duration
  int distance = duration * 0.034 / 2;   // Convert the duration to distance in cm
  return distance;                       // Return the measured distance
}

/* 
 * Function to move the robot forward
 * Activates the motors to rotate the wheels in the forward direction
 */
void moveForward() {
  digitalWrite(IN1, LOW);  // Set Motor A to forward
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); // Set Motor B to forward
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255);   // Set speed for Motor A
  analogWrite(ENB, 255);   // Set speed for Motor B
}

/* 
 * Function to stop the motors
 * Disables all motor outputs to stop the robot
 */
void stopMotors() {
  digitalWrite(IN1, LOW);  // Disable Motor A
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);  // Disable Motor B
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);     // Set speed to 0 for Motor A
  analogWrite(ENB, 0);     // Set speed to 0 for Motor B
}

/* 
 * Function to turn the robot to the right
 * Activates the motors to rotate the robot in place to the right
 */
void turnRight() {
  digitalWrite(IN1, LOW);  // Set Motor A to forward
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);  // Set Motor B to backward
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 255);   // Set speed for Motor A
  analogWrite(ENB, 255);   // Set speed for Motor B
}

/* 
 * Function to turn the robot to the left
 * Activates the motors to rotate the robot in place to the left
 */
void turnLeft() {
  digitalWrite(IN1, HIGH); // Set Motor A to backward
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); // Set Motor B to forward
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255);   // Set speed for Motor A
  analogWrite(ENB, 255);   // Set speed for Motor B
}

/* 
 * Setup function
 * Configures pins for motors, sensors, and button
 * Initializes the serial communication for debugging
 */
void setup() {
  // Configure motor pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Configure ultrasonic sensor pins
  pinMode(S1Trig, OUTPUT);
  pinMode(S1Echo, INPUT);
  pinMode(S2Trig, OUTPUT);
  pinMode(S2Echo, INPUT);
  pinMode(S3Trig, OUTPUT);
  pinMode(S3Echo, INPUT);

  // Configure button pin
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Use internal pull-up resistor for button

  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("Robot ready. Press the button to start.");
}

/* 
 * Loop function
 * Continuously measures distances and navigates the robot only when the button is pressed
 */
void loop() {
  // Check if the button is pressed
  if (digitalRead(BUTTON_PIN) == LOW) { // LOW indicates the button is pressed
    // Measure distances from all three sensors
    int frontDistance = readUltrasonic(S2Trig, S2Echo);
    int leftDistance = readUltrasonic(S1Trig, S1Echo);
    int rightDistance = readUltrasonic(S3Trig, S3Echo);

    // Display measured distances in the Serial Monitor
    Serial.print("Distanta fata: ");
    Serial.print(frontDistance);
    Serial.print(" cm | Stanga: ");
    Serial.print(leftDistance);
    Serial.print(" cm | Dreapta: ");
    Serial.print(rightDistance);
    Serial.println(" cm");

    /* Navigation logic:
     * If there is no obstacle in front, move forward.
     * Otherwise, stop and decide whether to turn left or right based on the available space.
     */
    if (frontDistance > FRONT_OBSTACLE_DIST) {
      // No obstacle in front, move forward
      moveForward();
      Serial.println("Merg înainte...");
    } else {
      // Obstacle detected, stop and analyze the situation
      stopMotors();
      Serial.println("Obstacol detectat! Mă opresc.");

      delay(500); // Pause to stabilize sensor readings

      if (leftDistance > rightDistance) {
        // More space on the left, turn left
        Serial.println("Spațiu mai mare în stânga, virează stânga...");
        turnLeft();
        delay(1000); // Duration of the turn
      } else {
        // More space on the right, turn right
        Serial.println("Spațiu mai mare în dreapta, virează dreapta...");
        turnRight();
        delay(1000); // Duration of the turn
      }

      // Stop the motors after turning and pause
      stopMotors();
      delay(500);
    }
  } else {
    // Button not pressed, stop the robot
    stopMotors();
    Serial.println("Butonul nu este apăsat. Robotul este oprit.");
  }

  delay(100); // Pause before updating measurements
}
