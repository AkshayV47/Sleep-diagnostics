
#include <HX711.h>
#include <ESP8266WiFi.h> 
#include <SoftwareSerial.h>

// Pin definitions for ESP8266
#define DT_PIN D2 // D2 (GPIO 4)
#define SCK_PIN D3  // D1 (GPIO 5)

HX711 scale; // Create HX711 object without parameters

void setup() {
  Serial.begin(9600); // Start serial communication
  Serial.println("HX711 Weight Scale");

  // Initialize HX711 with DT and SCK pins
  scale.begin(DT_PIN, SCK_PIN);
  // Optional: Reset scale to zero
  scale.set_scale();
  scale.tare(); // Zero the scale (remove any offset)
  Serial.println("Setup complete. Place a weight to read...");
}

void loop() {

  // Read raw data from HX711
  long reading = scale.read();
  Serial.print("Raw reading: ");
  Serial.println(reading);

  // Optional: Convert to weight (requires calibration)
  float weight = scale.get_units(10); // Average of 2 readings
  Serial.print("Weight: ");
  float val = map(weight, -100, 645975, 0, 5000);
  float cal = val / 1000;
  Serial.println(cal);
  Serial.println(cal, 2); // 2 decimal places

  delay(1000); // Delay for readable output
}