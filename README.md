#**Laboratory Activity #3: Working with Sensors**

## **Objectives**
### - Familiarize students with the basic sensor components that can be used in IoT
#### - Integrate these sensor components in an Arduino circuit
- Create a simple implementation of a fire sensor

## **Instructions:**
### 1. Create a simple implementation of a fire sensor using thermistor and photoresistor
### 2. Specifics
### Use A0 for thermistor and A2 for photoresistor
### Use Celsius for the temperature, digital signal for the photoresistor
### Threshold Limit: 50 Celsius for the temperature AND 220 for the brightness
### If the threshold limit is reached, use a fast blinking Red LED to notify about the fire. LED should me mapped in digital pin 12.
### (NICE TO HAVE) Together with the LED, add a buzzer/speaker that uses the same pin.
### 3. Passing criteria
### Working circuit and code
### Separate the temperature reading and brightness reading into different functions
### Use the `#define` to handle the pin numbers
### Use `const` to handle the threshold values
### 4. Turn in a Github link containing the following:
### - The sketch file (fire_sensor_simulation.ino)
### - Breadboard diagram. You can create via TinkerCad (https://www.tinkercad.com/) or Fritzing
### - Individual grades of the members 



