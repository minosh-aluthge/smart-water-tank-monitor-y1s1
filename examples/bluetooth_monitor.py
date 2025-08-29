/*
 * Bluetooth Monitor Example
 * 
 * This example shows how to connect to the Smart Water Tank Monitor
 * via Bluetooth and read sensor data on a computer.
 * 
 * Requirements:
 * - HC-05 Bluetooth module paired with computer
 * - Python with pySerial library installed
 * 
 * Usage:
 * 1. Pair HC-05 with your computer (default PIN: 1234 or 0000)
 * 2. Note the COM port assigned to HC-05
 * 3. Run this Python script to monitor data
 */

# Mobile App Connection Guide for Smart Water Tank Monitor

"""
This file provides guidance for connecting mobile apps to the Smart Water Tank Monitor
via HC-05 Bluetooth module. Since this project uses mobile apps from Google Play Store,
no Python installation is required.

RECOMMENDED MOBILE APPS:
======================

Android (Google Play Store):
1. "Serial Bluetooth Terminal" by Kai Morich (Most Popular)
2. "Bluetooth Terminal HC-05" 
3. "Arduino Bluetooth Controller"

iOS (App Store):
1. "Bluetooth Terminal"
2. "Serial Bluetooth Terminal"

CONNECTION STEPS:
================

1. PAIR DEVICE:
   - Go to phone Bluetooth settings
   - Search for "HC-05"
   - Enter PIN: 1234 (or 0000)

2. OPEN APP:
   - Install "Serial Bluetooth Terminal" from store
   - Open app and grant Bluetooth permissions

3. CONNECT:
   - In app, tap "Devices" or "Connect"
   - Select "HC-05" from paired devices
   - Status should show "Connected"

4. MONITOR DATA:
   - Real-time sensor data will appear
   - Data updates every 1.5 seconds

EXPECTED DATA OUTPUT:
====================

pH Value: 7.2
Water conditions OK
Distance: 15.3
Flow Rate: 2.1
Tank is full
No leak detected

ALERT MESSAGES:
===============

⚠️  "Leak detected" - EMERGENCY: Check system immediately
⚠️  "Denger leck !" - CRITICAL: System in emergency mode  
⚠️  pH outside 6-8 range - Water quality issue

TROUBLESHOOTING:
===============

Cannot connect:
- Check Arduino is powered on
- Verify HC-05 LED is blinking
- Try PIN 0000 if 1234 doesn't work

No data showing:
- Ensure app is connected (not just paired)
- Check baud rate is 9600 in app settings
- Try restarting the app

Poor connection:
- Stay within 10 meters of Arduino
- Avoid obstacles between devices
- Check for Bluetooth interference

FOR ACADEMIC PRESENTATIONS:
==========================

1. Show the pairing process live
2. Demonstrate real-time sensor readings
3. Explain each message as it appears
4. Show system response to different conditions
5. Use app's screenshot feature for documentation

This approach is perfect for SLIIT projects as it demonstrates:
- Real IoT monitoring capabilities
- Professional mobile integration
- Easy user interface
- Practical application demonstration
"""

# Note: This project uses mobile apps, so no Python code is needed.
# See docs/MOBILE_APP_GUIDE.md for detailed mobile app setup instructions.
