/*
 * Individual Sensor Test Examples
 * 
 * Test each sensor component individually to verify proper operation
 * before integrating into the main system.
 */

// HC-SR04 Ultrasonic Sensor Test
/*
const int trigPin = 5;
const int echoPin = 6;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.println("HC-SR04 Test Started");
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.0343 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(1000);
}
*/

// YF-S201 Flow Sensor Test
/*
#define FLOW_SENSOR_PIN 2
volatile int flowCount = 0;

void countFlow() {
  flowCount++;
}

void setup() {
  Serial.begin(9600);
  pinMode(FLOW_SENSOR_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(FLOW_SENSOR_PIN), countFlow, RISING);
  Serial.println("Flow Sensor Test Started");
}

void loop() {
  flowCount = 0;
  delay(1000);  // Count for 1 second
  
  float flowRate = (flowCount / 7.5);  // Convert to L/min
  
  Serial.print("Pulses: ");
  Serial.print(flowCount);
  Serial.print(" | Flow Rate: ");
  Serial.print(flowRate);
  Serial.println(" L/min");
}
*/

// HC-05 Bluetooth Test
/*
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(8, 9);  // RX, TX

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  Serial.println("Bluetooth Test Started");
  Serial.println("Send messages via Bluetooth");
}

void loop() {
  // Send test message every 5 seconds
  static unsigned long lastSend = 0;
  if (millis() - lastSend > 5000) {
    bluetooth.println("Hello from Arduino!");
    Serial.println("Message sent via Bluetooth");
    lastSend = millis();
  }
  
  // Echo received messages
  if (bluetooth.available()) {
    String message = bluetooth.readString();
    Serial.print("Received: ");
    Serial.println(message);
    bluetooth.print("Echo: ");
    bluetooth.println(message);
  }
}
*/

// Solenoid Valve Test
/*
#define SOLENOID_IN 11
#define SOLENOID_OUT 12

void setup() {
  Serial.begin(9600);
  pinMode(SOLENOID_IN, OUTPUT);
  pinMode(SOLENOID_OUT, OUTPUT);
  Serial.println("Solenoid Test Started");
}

void loop() {
  Serial.println("Opening inlet valve...");
  digitalWrite(SOLENOID_IN, LOW);   // Open inlet
  digitalWrite(SOLENOID_OUT, HIGH); // Close outlet
  delay(3000);
  
  Serial.println("Closing inlet valve...");
  digitalWrite(SOLENOID_IN, HIGH);  // Close inlet
  digitalWrite(SOLENOID_OUT, HIGH); // Keep outlet closed
  delay(3000);
  
  Serial.println("Opening outlet valve...");
  digitalWrite(SOLENOID_IN, HIGH);  // Keep inlet closed
  digitalWrite(SOLENOID_OUT, LOW);  // Open outlet
  delay(3000);
  
  Serial.println("Closing all valves...");
  digitalWrite(SOLENOID_IN, HIGH);  // Close inlet
  digitalWrite(SOLENOID_OUT, HIGH); // Close outlet
  delay(3000);
}
*/
