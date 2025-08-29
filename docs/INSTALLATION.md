# Installation Guide

## Hardware Setup

### Required Components
- Arduino Uno/Nano (1x)
- HC-SR04 Ultrasonic Sensor (1x)
- pH Sensor Module (1x)
- YF-S201 Water Flow Sensor (2x)
- HC-05 Bluetooth Module (1x)
- Solenoid Valves 12V (2x)
- Relay Module (2x) - for solenoid control
- Breadboard or PCB
- Jumper wires
- 12V Power Supply
- Resistors (10kΩ, 220Ω)

### Circuit Assembly

#### Power Connections
1. Connect Arduino VCC to 5V power source
2. Connect Arduino GND to common ground
3. Connect 12V supply for solenoid valves

#### Sensor Connections
1. **HC-SR04 Ultrasonic Sensor**
   - VCC → 5V
   - GND → GND
   - Trig → Pin 5
   - Echo → Pin 6

2. **pH Sensor**
   - VCC → 5V
   - GND → GND
   - Signal → A0

3. **YF-S201 Flow Sensors**
   - Red → 5V
   - Black → GND
   - Yellow (Signal) → Pin 2 (Sensor 1), Pin 3 (Sensor 2)

4. **HC-05 Bluetooth Module**
   - VCC → 5V
   - GND → GND
   - TX → Pin 8
   - RX → Pin 9

5. **Solenoid Valves (via Relay)**
   - Relay IN1 → Pin 11 (Inlet Solenoid)
   - Relay IN2 → Pin 12 (Outlet Solenoid)
   - Connect solenoids to relay outputs with 12V supply

### Software Installation

#### Arduino IDE Setup
1. Download and install Arduino IDE from [arduino.cc](https://www.arduino.cc/en/software)
2. Install required libraries:
   - SoftwareSerial (usually pre-installed)

#### Code Upload
1. Open `smart_water_tank_monitor.ino` in Arduino IDE
2. Select your Arduino board (Tools → Board)
3. Select correct COM port (Tools → Port)
4. Click Upload button

### Calibration

#### pH Sensor Calibration
1. Use pH 7 buffer solution for neutral calibration
2. Adjust `calibration_value` in code (currently 22.04)
3. Test with pH 4 and pH 10 solutions for accuracy

#### Flow Sensor Calibration
- YF-S201 sensors are calibrated for 7.5 pulses per liter
- If using different sensors, adjust the division factor in code

#### Distance Sensor Calibration
- Measure actual tank height
- Adjust tank full threshold (currently 10cm from sensor)

### Testing

#### Initial System Test
1. Power on the system
2. Open Serial Monitor (9600 baud)
3. Observe sensor readings
4. Test Bluetooth connectivity

#### Functionality Tests
1. **Water Level Test**: Place sensor above water container
2. **pH Test**: Test with different pH solutions
3. **Flow Test**: Run water through flow sensors
4. **Bluetooth Test**: Connect with smartphone/computer

### Troubleshooting

#### Common Issues
1. **No Serial Output**: Check baud rate (9600)
2. **Bluetooth Not Connecting**: Check pairing and baud rate
3. **Inconsistent pH Readings**: Check sensor calibration
4. **Flow Sensor Not Working**: Check interrupt pin connections
5. **Solenoids Not Operating**: Check relay connections and power supply

#### Debug Tips
- Use Serial Monitor for real-time debugging
- Check all connections with multimeter
- Verify sensor voltages
- Test components individually

### Safety Considerations
- Use proper electrical isolation for water sensors
- Ensure all connections are waterproof
- Use appropriate power ratings for solenoids
- Follow electrical safety guidelines

---
*For additional help, refer to the main README.md or open an issue on GitHub*
