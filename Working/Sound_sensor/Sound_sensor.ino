// Sound Sensor - A0 Connection
// Detects sound and displays level on Serial Monitor

const int soundPin = A0;    // Sound sensor connected to A0
int soundValue = 0;         // Raw analog reading
int soundLevel = 0;         // Mapped sound level (0-100)
int threshold = 500;        // Adjust this value based on your environment

void setup() {
  Serial.begin(9600);       // Initialize Serial Monitor
  pinMode(soundPin, INPUT); // Set A0 as input
  
  Serial.println("=== SOUND SENSOR READY ===");
  Serial.println("Sound Level | Raw Value");
  Serial.println("-------------------------");
}

void loop() {
  // Read raw analog value from sound sensor (0-1023)
  soundValue = analogRead(soundPin);
  
  // Map to 0-100 scale for easier reading
  soundLevel = map(soundValue, 0, 1023, 0, 50);
  
  // Display results
  Serial.print(soundLevel);
  Serial.print("%     | ");
  Serial.println(soundValue);
  
  // Sound Detection Alert
  if (soundLevel < 13) {
    Serial.println("🔊 SOUND DETECTED!");
    delay(500); // Debounce
  }
  
  delay(100); // Read every 100ms
}