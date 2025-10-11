// ---------------------------
// Fire Sensor System
// ---------------------------

// --- Pin Naming ---
#define THERMISTOR A0
#define PHOTORESISTOR A2
#define ALERT 12   // LED + buzzer pin

// --- Thresholds & Constants ---
const int TEMP_THRESHOLD = 50;      
const int BRIGHT_THRESHOLD = 220;    
const int BETA = 3950;               
const int RESISTANCE = 10;            

// --- Function Declarations ---
float readTemperature();
int readBrightness();
int digitalBrightness(int brightness);

void setup() {
  Serial.begin(9600);
  pinMode(ALERT, OUTPUT);
  Serial.println("=== FIRE SENSOR SYSTEM STARTING ===");
  delay(1000);
  Serial.println("------------------------------------------------------------");
  Serial.println("Temperature (°C)\tRaw Brightness\tDigital (1/0)\tStatus");
  Serial.println("------------------------------------------------------------");
}


// ---------------------------
// FUNCTIONS
// ---------------------------

// Function to read and convert thermistor value into Celsius
float readTemperature() {
  int analogValue = analogRead(THERMISTOR);

    float temperatureC= BETA / (log((1023.0 * RESISTANCE / analogValue - RESISTANCE) / RESISTANCE) + BETA / 298.0) - 273.0;

  
  return temperatureC;
}

// Function to read photoresistor brightness value (analog)
int readBrightness() {
  return analogRead(PHOTORESISTOR);
}

// Function to convert analog brightness to digital HIGH/LOW
int digitalBrightness(int brightness) {
  if (brightness >= BRIGHT_THRESHOLD) {
    return HIGH;  // bright → 1
  } else {
    return LOW;   // dark → 0
  }
}


void loop() {
  // --- Sensor Readings ---
  float temperature = readTemperature();
  int brightnessRaw = readBrightness();               // analog light reading (0–1023)
  int brightnessDigital = digitalBrightness(brightnessRaw);  // HIGH or LOW (1 or 0)

 
  // --- Display Readings ---
  Serial.print(temperature, 2);      // print temperature with 2 decimal places
  Serial.print("°C\t\t");
  Serial.print(brightnessRaw);       // print actual photoresistor value
  Serial.print("\t\t");
  Serial.print(brightnessDigital);   // print 1 or 0
  Serial.print("\t\t");

 // --- Fire Detection Logic ---

  if (temperature >= TEMP_THRESHOLD && brightnessDigital == HIGH) {
    Serial.println("FIRE DETECTED!");
    digitalWrite(ALERT, HIGH);
    delay(100);
    digitalWrite(ALERT, LOW);
    delay(100);
  } else {
    Serial.println("No Fire");
    digitalWrite(ALERT, LOW);
    delay(500);
  }
}
