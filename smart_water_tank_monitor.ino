#include <SoftwareSerial.h>

// Solenoid pins
#define solenoid_in 11
#define solenoid_out 12  // Changed solenoid_out to pin 12 to avoid conflict

// YF-S201
#define FLOW_SENSOR_PIN 2
#define FLOW_SENSOR_2_PIN 3
volatile int flowCount = 0;
volatile int flowCount2 = 0;
float flowRate = 0;
float flowRate2 = 0;

int leakage = 0;

// pH Sensor
#define SensorPin A0  // pH meter analog output to Arduino analog input A0
float calibration_value = 22.04;  // Calibration value for pH sensor
unsigned long int avgValue;       // Store the average value of the sensor feedback
int buf[10], temp;

// HC-SR04
const int trigPin = 5;  // Sets the trigPin
const int echoPin = 6; // Sets the echoPin 
long duration;
int distance;

// HC-05
SoftwareSerial Bluetooth(8, 9);  // RX, TX pins for HC-05

// Flow sensor interrupt handlers
void countFlow() {
  flowCount++;
}

void countFlow2() {
  flowCount2++;
}

// Measure distance using HC-SR04
float measureDistance() {
  // Clear the trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigger high for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in cm
  float distance = duration * 0.0343 / 2;  // Sound speed = 343 m/s, duration divided by 2
  return distance;
}

void setup() {
  // Initialize serial and Bluetooth communication
  Serial.begin(9600);
  Bluetooth.begin(9600);

  // Initialize sensor pins
  pinMode(SensorPin, INPUT);
  
  // Set up HC-SR04 pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set up flow sensors
  pinMode(FLOW_SENSOR_PIN, INPUT);
  pinMode(FLOW_SENSOR_2_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(FLOW_SENSOR_PIN), countFlow, RISING);
  attachInterrupt(digitalPinToInterrupt(FLOW_SENSOR_2_PIN), countFlow2, RISING);

  // Set up solenoid control
  pinMode(solenoid_in, OUTPUT);
  pinMode(solenoid_out, OUTPUT);
}

void loop() {
  // Read pH sensor values and calculate average
  for (int i = 0; i < 10; i++) {
    buf[i] = analogRead(SensorPin);
    delay(10);
  }

  // Sort sensor readings for smoothing
  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 10; j++) {
      if (buf[i] > buf[j]) {
        temp = buf[i];
        buf[i] = buf[j];
        buf[j] = temp;
      }
    }
  }

  // Calculate average value of the center readings
  avgValue = 0;
  for (int i = 2; i < 8; i++) avgValue += buf[i];
  
  float phValue = (float)avgValue * 5.0 / 1024 / 6;  // Convert to millivolts
  phValue = -5.70 * phValue + calibration_value;     // Convert to pH value

  // Output pH value
  Serial.print("pH Value: ");
  Serial.println(phValue);
  Bluetooth.print("pH Value: ");
  Bluetooth.println(phValue);

  // If no leakage, check water conditions and ultrasonic sensor
  if (leakage == 0) {
    
    if (phValue >= 6 && phValue < 8) {
      Serial.println("Water conditions OK");
      Bluetooth.println("Water conditions OK");

      float distance1 = measureDistance();
      Serial.print("Distance: ");
      Serial.println(distance1);

      flowRate = (flowCount / 7.5);
      Serial.print("Flow Rate: ");
      Serial.println(flowRate);

      if (distance1 < 10) {
        Serial.println("Tank is full");
        Bluetooth.println("Tank is full");
        digitalWrite(solenoid_in, HIGH);  // Activate solenoid_in
          delay(1500);  // Wait to check for leaks
          float distance2 = measureDistance();
        if (flowRate == 0) {
9
          float distanceDiff = distance1 - distance2;
          if (distanceDiff > 0.5) {
            Serial.println("Leak detected");
            leakage = 1;
            digitalWrite(solenoid_out, LOW);  // Activate solenoid_out in case of leak
            digitalWrite(solenoid_in, HIGH);
            //delay(10000);
          } else {
            Serial.println("No leak detected");
          }
        }
      }
      else{
        digitalWrite(solenoid_in, LOW);
        digitalWrite(solenoid_out, HIGH);
        float flowRate2 = (flowCount2 / 7.5);
        
        float flowdff = flowRate-flowRate2;
        if(flowdff > 0.5){
         Serial.println("Wrning leck ! ");   
        }
        else{
           Serial.println("no lecl");
            
        }
      }
      
     }
  } 
  else {
    digitalWrite(solenoid_in, HIGH);
    digitalWrite(solenoid_out, LOW);
    Serial.println("Denger leck ! ");   // Keep solenoid_in active if there's a leak
  }
  flowCount =0;
  flowCount2 = 0;
  delay(1500);  // Delay before next loop
}
