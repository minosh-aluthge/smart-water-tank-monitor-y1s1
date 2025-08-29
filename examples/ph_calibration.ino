/*
 * pH Sensor Calibration Example
 * 
 * This simplified Arduino sketch helps calibrate the pH sensor
 * for accurate readings in your specific water conditions.
 * 
 * Instructions:
 * 1. Upload this code to Arduino
 * 2. Use pH 7.0 buffer solution for calibration
 * 3. Note the voltage reading and adjust calibration_value
 * 4. Test with pH 4.0 and pH 10.0 solutions
 * 5. Update the main code with new calibration value
 */

#define SensorPin A0
float calibration_value = 22.04;  // Adjust this value for calibration
unsigned long int avgValue;
int buf[10], temp;

void setup() {
  Serial.begin(9600);
  Serial.println("pH Sensor Calibration");
  Serial.println("Place sensor in pH 7.0 buffer solution");
  delay(2000);
}

void loop() {
  // Read 10 samples
  for (int i = 0; i < 10; i++) {
    buf[i] = analogRead(SensorPin);
    delay(10);
  }
  
  // Sort samples
  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 10; j++) {
      if (buf[i] > buf[j]) {
        temp = buf[i];
        buf[i] = buf[j];
        buf[j] = temp;
      }
    }
  }
  
  // Average middle 6 readings
  avgValue = 0;
  for (int i = 2; i < 8; i++) {
    avgValue += buf[i];
  }
  
  float voltage = (float)avgValue * 5.0 / 1024 / 6;
  float phValue = -5.70 * voltage + calibration_value;
  
  // Display readings
  Serial.print("Raw ADC: ");
  Serial.print(avgValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 3);
  Serial.print("V | pH: ");
  Serial.println(phValue, 2);
  
  // Calibration guidance
  if (phValue < 6.8 || phValue > 7.2) {
    Serial.println("Adjust calibration_value:");
    if (phValue < 6.8) {
      Serial.println("Increase calibration_value");
    } else {
      Serial.println("Decrease calibration_value");
    }
  } else {
    Serial.println("✓ Calibration looks good!");
  }
  
  Serial.println("---");
  delay(2000);
}
