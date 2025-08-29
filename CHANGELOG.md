# Changelog

All notable changes to the Smart Water Tank Monitor project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.0.0] - 2024-07-15

### Added
- Initial release of Smart Water Tank Monitor system
- pH sensor monitoring with automatic water quality assessment
- HC-SR04 ultrasonic distance sensor for water level monitoring
- Dual YF-S201 flow sensors for inlet and outlet flow measurement
- HC-05 Bluetooth module for remote monitoring
- Automated solenoid valve control for water inlet/outlet
- Leak detection system with multiple detection methods
- Real-time serial and Bluetooth communication
- Emergency leak response system

### Features
- **Water Level Control**: Automatic tank filling based on ultrasonic sensor readings
- **Water Quality Monitoring**: pH sensor with 6.0-8.0 acceptable range
- **Flow Rate Monitoring**: Dual flow sensors with leak detection comparison
- **Bluetooth Connectivity**: Remote monitoring via HC-05 module
- **Automated Safety**: Emergency valve closure on leak detection
- **Real-time Feedback**: Serial and Bluetooth status updates

### Technical Specifications
- **Microcontroller**: Arduino Uno/Nano compatible
- **Sensors**: HC-SR04, pH sensor (analog), 2x YF-S201 flow sensors
- **Communication**: HC-05 Bluetooth, Serial (9600 baud)
- **Control**: 2x solenoid valves with relay control
- **Update Frequency**: 1.5 seconds

### Pin Configuration
- A0: pH Sensor (analog input)
- Pin 2: Flow Sensor 1 (interrupt)
- Pin 3: Flow Sensor 2 (interrupt)
- Pin 5: HC-SR04 Trigger
- Pin 6: HC-SR04 Echo
- Pin 8: HC-05 RX
- Pin 9: HC-05 TX
- Pin 11: Solenoid Inlet Control
- Pin 12: Solenoid Outlet Control

### Known Issues
- Minor spelling errors in warning messages ("Wrning leck", "Denger leck")
- Flow sensor calibration specific to YF-S201 sensors
- pH sensor calibration may need adjustment for different sensor models

### Academic Context
- Developed for SLIIT Year 1 Semester 1 (July 2024)
- Demonstrates embedded systems, sensor integration, and IoT concepts
- Part of practical Arduino programming curriculum

## [Unreleased]

### Planned Features
- WiFi connectivity for web-based monitoring
- Data logging to SD card
- Mobile app integration
- Advanced leak detection algorithms
- Multi-tank support
- Web dashboard for remote monitoring

### Potential Improvements
- Code optimization for memory usage
- Enhanced error handling
- Sensor calibration wizard
- Configuration via Bluetooth commands
- Alert system with email/SMS notifications

---

## Development Notes

### Version Numbering
- Major version: Significant architectural changes
- Minor version: New features or sensor additions
- Patch version: Bug fixes and minor improvements

### Release Process
1. Update version number in code comments
2. Update CHANGELOG.md
3. Test all functionality
4. Create GitHub release
5. Update documentation

### Contributing
See CONTRIBUTING.md for guidelines on submitting changes and improvements.

---
*This project is maintained as part of educational activities at SLIIT*
