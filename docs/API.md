# API Documentation

## Serial Communication Protocol

The Smart Water Tank Monitor communicates via Serial (USB) and Bluetooth using a simple text-based protocol.

### Baud Rate
- **Serial**: 9600 bps
- **Bluetooth**: 9600 bps

## Output Messages

### pH Readings
```
pH Value: [value]
```
- **Format**: Float with 2 decimal places
- **Range**: 0.0 - 14.0
- **Frequency**: Every 1.5 seconds

### Water Level Status
```
Distance: [value]
```
- **Format**: Float in centimeters
- **Range**: 2 - 400 cm (HC-SR04 range)

```
Tank is full
```
- Triggered when distance < 10cm

### Flow Rate Monitoring
```
Flow Rate: [value]
```
- **Format**: Float in liters per minute
- **Calculation**: Based on YF-S201 sensor (7.5 pulses/liter)

### Water Quality Status
```
Water conditions OK
```
- Triggered when pH is between 6.0 and 8.0

### System States

#### Normal Operation
```
Water conditions OK
Distance: [value]
Flow Rate: [value]
```

#### Tank Full State
```
Tank is full
```

#### Leak Detection
```
Leak detected
```
- Triggered when flow difference > 0.5 L/min or distance change > 0.5cm

```
No leak detected
```

#### Water Quality Issues
- System provides pH readings but no "Water conditions OK" message when pH < 6.0 or pH > 8.0

#### System Warnings
```
Wrning leck !
```
- Triggered when inlet-outlet flow difference > 0.5 L/min

```
no lecl
```
- Normal flow operation confirmed

```
Denger leck !
```
- Critical leak state, system in emergency mode

## Control Logic

### Solenoid Control States

#### Normal Filling (Tank not full)
- `solenoid_in`: LOW (Open inlet)
- `solenoid_out`: HIGH (Open outlet)

#### Tank Full
- `solenoid_in`: HIGH (Close inlet)
- `solenoid_out`: Current state maintained

#### Leak Detected
- `solenoid_in`: HIGH (Close inlet)
- `solenoid_out`: LOW (Close outlet)

### Sensor Reading Cycle
1. pH sensor readings (10 samples, averaged)
2. Distance measurement
3. Flow rate calculation
4. Leak detection logic
5. Solenoid control updates
6. 1.5-second delay

## Integration Examples

### Python Serial Reader
```python
import serial
import time

# Connect to Arduino
arduino = serial.Serial('COM3', 9600)  # Adjust COM port
time.sleep(2)

while True:
    if arduino.in_waiting > 0:
        data = arduino.readline().decode('utf-8').strip()
        print(f"Received: {data}")
        
        # Parse specific messages
        if "pH Value:" in data:
            ph_value = float(data.split(":")[1].strip())
            print(f"pH Level: {ph_value}")
        elif "Distance:" in data:
            distance = float(data.split(":")[1].strip())
            print(f"Water Level: {distance}cm")
```

### Bluetooth Connection (Android)
```java
// Example Android Bluetooth connection
BluetoothSocket socket = device.createRfcommSocketToServiceRecord(UUID);
socket.connect();

InputStream inputStream = socket.getInputStream();
// Read data from inputStream
```

## Error Handling

### No Sensor Response
- System continues operation with last known values
- Check physical connections

### Invalid Readings
- pH values outside 0-14 range indicate sensor issues
- Distance values > 400cm or < 2cm indicate HC-SR04 problems

### Communication Errors
- Bluetooth disconnection: System continues local operation
- Serial buffer overflow: Restart Arduino if persistent

## Data Logging Recommendations

### Recommended Logging Format
```
Timestamp,pH,Distance,FlowRate1,FlowRate2,SolenoidIn,SolenoidOut,LeakStatus
2024-07-15 10:30:00,7.2,15.3,2.1,2.0,HIGH,HIGH,OK
```

### Monitoring Intervals
- **Real-time**: 1.5 seconds (system default)
- **Data logging**: 30 seconds recommended
- **Alerts**: Immediate for leak detection

---
*This API documentation covers the current implementation. For modifications or extensions, refer to the source code comments.*
