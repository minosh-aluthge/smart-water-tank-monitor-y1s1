# Mobile App Bluetooth Monitoring Guide

## Overview
This Smart Water Tank Monitor system is designed to work with Android/iOS Bluetooth terminal apps available on Google Play Store and App Store. No custom app development required!

## 📱 **Recommended Mobile Apps**

### **Android (Google Play Store):**
1. **Serial Bluetooth Terminal** (Most Popular)
   - Developer: Kai Morich
   - Free download
   - Easy to use interface

2. **Bluetooth Terminal HC-05**
   - Simple and reliable
   - Good for basic monitoring

3. **Arduino Bluetooth Controller**
   - More advanced features
   - Customizable interface

### **iOS (App Store):**
1. **Bluetooth Terminal**
2. **Serial Bluetooth Terminal**

## 🔧 **Setup Instructions**

### **Step 1: HC-05 Bluetooth Module Setup**
1. Power on your Arduino with HC-05 module
2. HC-05 should be discoverable (blinking LED)
3. Default settings:
   - **Name**: HC-05 or HC-06
   - **PIN**: 1234 or 0000
   - **Baud Rate**: 9600

### **Step 2: Pair with Mobile Device**
1. Open your phone's Bluetooth settings
2. Search for new devices
3. Select "HC-05" from the list
4. Enter PIN: **1234** (or 0000 if 1234 doesn't work)
5. Wait for "Connected" status

### **Step 3: Install Bluetooth Terminal App**
1. Go to Google Play Store (Android) or App Store (iOS)
2. Search for "Serial Bluetooth Terminal"
3. Install the app (usually free)
4. Grant Bluetooth permissions when prompted

### **Step 4: Connect App to Arduino**
1. Open the Bluetooth Terminal app
2. Look for "Connect" or "Devices" button
3. Select "HC-05" from paired devices list
4. Connection should show "Connected" status

## 📊 **Reading the Data**

### **Real-time Data Display:**
Your mobile app will show live data streams like:

```
pH Value: 7.2
Water conditions OK
Distance: 15.3
Flow Rate: 2.1
Tank is full
No leak detected
```

### **Data Interpretation:**

| **Message** | **Meaning** | **Action Needed** |
|-------------|-------------|-------------------|
| `pH Value: 7.2` | Water quality is good (6-8 range) | ✅ Normal operation |
| `pH Value: 5.1` | Water too acidic | ⚠️ Check water source |
| `pH Value: 9.3` | Water too alkaline | ⚠️ Check water source |
| `Distance: 5.2` | Water level high | ✅ Tank almost full |
| `Distance: 25.8` | Water level low | 💧 Tank needs filling |
| `Tank is full` | Maximum water level reached | ✅ System auto-stopped |
| `Flow Rate: 2.1` | Water flowing at 2.1 L/min | ✅ Normal flow |
| `Leak detected` | System found a leak | 🚨 **EMERGENCY - Check system** |
| `Water conditions OK` | pH is in safe range | ✅ Safe to use |

## 🚨 **Alert System**

### **Critical Alerts:**
- **"Leak detected"** - Immediate attention required
- **"Denger leck !"** - Emergency leak state
- **pH outside 6-8 range** - Water quality issue

### **Normal Status:**
- **"Water conditions OK"** - System operating normally
- **"No leak detected"** - All systems safe
- **"Tank is full"** - Automatic operation complete

## 📱 **Mobile App Screenshots Guide**

### **Connection Screen:**
1. Open app → "Devices" → Select "HC-05"
2. Status should show "Connected"

### **Terminal Screen:**
- Real-time data will scroll continuously
- Data updates every 1.5 seconds
- You can scroll up to see previous readings

### **Useful App Features:**
- **Save Log**: Most apps can save readings to file
- **Send Commands**: Some apps allow sending data back to Arduino
- **Timestamps**: Apps usually add time stamps to data
- **Share Data**: Export readings via email/messaging

## 🔄 **Troubleshooting**

### **Cannot Connect to HC-05:**
1. Check Arduino is powered on
2. Verify HC-05 LED is blinking (discoverable mode)
3. Try unpairing and re-pairing Bluetooth
4. Restart the mobile app
5. Check if PIN is 1234 or 0000

### **No Data Showing:**
1. Verify app is connected (not just paired)
2. Check baud rate in app settings (should be 9600)
3. Try different Bluetooth terminal app
4. Restart Arduino system

### **Inconsistent Data:**
1. Check distance between phone and Arduino (max 10 meters)
2. Avoid obstacles between devices
3. Check for interference from other Bluetooth devices

## 📋 **Data Logging Tips**

### **For Academic Reports:**
1. Use app's "Save Log" feature
2. Take screenshots of critical readings
3. Document system responses to different conditions
4. Record timestamps for analysis

### **For Demonstrations:**
1. Clear app screen before demo
2. Explain each reading as it appears
3. Show system response to manual tests
4. Demonstrate leak detection feature

## 🎯 **Academic Benefits**

### **SLIIT Project Advantages:**
- **Real-time Monitoring**: Professional IoT demonstration
- **Mobile Integration**: Shows practical application
- **Data Collection**: Easy for reports and analysis
- **Remote Access**: Wireless monitoring capability
- **User-Friendly**: No technical expertise required for operation

### **Presentation Tips:**
1. Show the pairing process
2. Demonstrate real-time readings
3. Explain each sensor's contribution
4. Show emergency responses (leak detection)
5. Discuss practical applications

---

## 📞 **Support**

For issues with:
- **Hardware**: Check Arduino connections and power
- **Bluetooth**: Verify HC-05 module and pairing
- **Mobile App**: Try different Bluetooth terminal apps
- **Data Accuracy**: Calibrate sensors as per installation guide

---
*This guide is specifically designed for SLIIT Y1S1 students using mobile apps for Arduino Bluetooth monitoring*
