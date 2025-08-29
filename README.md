# Smart Water Tank Monitor - SLIIT Y1S1 Project

## Project Overview
This Arduino-based Smart Water Tank Monitoring System was developed as part of the SLIIT Year 1 Semester 1 (July 2024) curriculum. The system provides automated water level control, pH monitoring, leak detection, and remote monitoring capabilities.

## Features
- **Water Level Monitoring**: Using HC-SR04 ultrasonic sensor
- **pH Level Monitoring**: Analog pH sensor for water quality assessment
- **Flow Rate Monitoring**: Dual YF-S201 flow sensors for inlet and outlet flow measurement
- **Leak Detection**: Automated leak detection system with solenoid valve control
- **Bluetooth Connectivity**: Remote monitoring via HC-05 Bluetooth module
- **Automated Water Control**: Solenoid valves for inlet and outlet water control

## Hardware Components
- Arduino Uno/Nano
- HC-SR04 Ultrasonic Distance Sensor
- pH Sensor (Analog)
- 2x YF-S201 Water Flow Sensors
- HC-05 Bluetooth Module
- 2x Solenoid Valves
- Jumper wires and breadboard

## Pin Configuration
| Component | Pin |
|-----------|-----|
| pH Sensor | A0 |
| HC-SR04 Trigger | 5 |
| HC-SR04 Echo | 6 |
| HC-05 RX | 8 |
| HC-05 TX | 9 |
| Solenoid In | 11 |
| Solenoid Out | 12 |
| Flow Sensor 1 | 2 |
| Flow Sensor 2 | 3 |

## How It Works
1. **Water Level Control**: The system monitors water level using ultrasonic sensor
2. **Quality Check**: pH sensor ensures water quality is within acceptable range (6-8 pH)
3. **Flow Monitoring**: Dual flow sensors track water inlet and outlet rates
4. **Leak Detection**: System compares flow rates and distance measurements to detect leaks
5. **Automated Response**: Solenoid valves automatically control water flow based on conditions
6. **Remote Monitoring**: Bluetooth module enables remote status monitoring via mobile apps

## Installation & Setup

### Prerequisites
- Arduino IDE
- SoftwareSerial library (usually included with Arduino IDE)
- Android/iOS Bluetooth Terminal app (from Google Play Store/App Store)

### Upload Instructions
1. Clone this repository
2. Open `smart_water_tank_monitor.ino` in Arduino IDE
3. Connect your Arduino board
4. Select appropriate board and port
5. Upload the code

### Circuit Assembly
1. Connect components according to the pin configuration table
2. Ensure proper power supply for solenoid valves
3. Calibrate pH sensor using the calibration_value parameter

### Mobile App Setup
1. Download "Serial Bluetooth Terminal" from Google Play Store
2. Pair your phone with HC-05 Bluetooth module (PIN: 1234)
3. Connect to HC-05 through the app
4. Start monitoring real-time sensor data

## Usage
1. Power on the system
2. Connect mobile app to HC-05 Bluetooth module
3. Monitor real-time data through Bluetooth terminal app
4. System will automatically:
   - Control water inlet based on tank level
   - Monitor water quality
   - Detect and respond to leaks

## System States
- **Normal Operation**: Tank filling/maintaining level with quality water
- **Tank Full**: Inlet valve closed, monitoring for leaks
- **Leak Detected**: Emergency shutdown, outlet valve closed
- **Poor Water Quality**: System alerts if pH outside 6-8 range

## Calibration
- **pH Sensor**: Adjust `calibration_value` (currently 22.04) based on your sensor
- **Flow Sensors**: Calibrated for YF-S201 (7.5 pulses per liter)
- **Distance Sensor**: Tank full threshold set at 10cm

## Project Structure
```
├── smart_water_tank_monitor.ino  # Main Arduino code
├── README.md                     # Project documentation
├── P8-13 Progress Report.docx    # Project progress report
├── Y1S1 fc.jpg                   # Project circuit diagram/photo
├── LICENSE                       # MIT License
├── CHANGELOG.md                  # Version history
├── CONTRIBUTING.md               # Contribution guidelines
├── .gitignore                    # Git ignore file
├── docs/                         # Documentation folder
│   ├── INSTALLATION.md          # Hardware setup guide
│   ├── API.md                   # Communication protocol
│   └── MOBILE_APP_GUIDE.md      # Mobile app setup guide
└── examples/                     # Example codes
    ├── MOBILE_MONITORING.md     # Mobile app quick guide
    ├── ph_calibration.ino      # pH sensor calibration
    └── sensor_tests.ino        # Individual sensor tests
```

## Mobile App Monitoring
This project is designed to work with **Android/iOS Bluetooth terminal apps**:
- **Recommended**: "Serial Bluetooth Terminal" from Google Play Store
- **Setup**: Pair with HC-05 → Open app → Connect → Monitor real-time data
- **Benefits**: Easy wireless monitoring, no programming required
- **Perfect for**: Academic demonstrations and practical IoT learning

For detailed mobile app setup instructions, see [docs/MOBILE_APP_GUIDE.md](docs/MOBILE_APP_GUIDE.md)

## Academic Information
- **Institution**: Sri Lanka Institute of Information Technology (SLIIT)
- **Academic Year**: Year 1, Semester 1
- **Period**: July 2024
- **Project Type**: Arduino-based IoT Water Management System

## Future Enhancements
- WiFi connectivity for remote web monitoring
- Mobile app integration
- Data logging and analytics
- Multiple tank support
- Advanced leak detection algorithms

## Contributing
This is an academic project. For educational purposes and improvements, feel free to fork and suggest enhancements.

## License
This project is created for educational purposes as part of SLIIT curriculum.

## Contact
For questions about this project, please contact through GitHub issues.

---
*This project was developed as part of the SLIIT Year 1 Semester 1 curriculum, demonstrating practical application of embedded systems, sensors, and IoT concepts.*