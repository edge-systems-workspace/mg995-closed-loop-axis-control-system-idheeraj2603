/**
* @file main.cpp
 * @brief MG995 Closed-Loop Axis Control System
 * @author Dheeraj Yadav [idheeraj2603]
 * @date 19-02-2026
 *
 * @details
 * Implements PWM-based closed-loop control for MG995 servo motor.
 * Accepts angle input via Serial Monitor and validates range (0–180).
 */

#include <Arduino.h>
#include <Servo.h>

Servo myServo;

/**
 * @brief Arduino setup function.
 *
 * Initializes serial communication at 9600 baud, attaches the servo to pin 11,
 * and prints an initialization message over Serial.
 */
void setup() {
    Serial.begin(9600);

    myServo.attach(11);

    Serial.println("Servo initiate");
}

/**
 * @brief Arduino main loop.
 *
 * Sweeps the servo from 0 to 180 degrees in steps of 10 degrees, then back
 * from 180 to 0 degrees in steps of 10 degrees. At each step the current
 * angle is written to the servo and printed to the Serial monitor. Each step
 * pauses for 500 ms.
 */
void loop() {

    for (int i = 0; i <= 180; i += 10) {
        myServo.write(i);

        Serial.print("Servo Angle: ");
        Serial.println(i);

        delay(500);
    }

    for (int i = 180; i >= 0; i -= 10) {
        myServo.write(i);

        Serial.print("Servo Angle: ");
        Serial.println(i);

        delay(500);
    }

}