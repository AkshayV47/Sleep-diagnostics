// #define BOT_TOKEN "8463522663:AAF5XLfpL0djxhSwHzX-22k0J8Ll-_LDsMM"
// String chat_id = "7139649414";

// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>
// #include <HX711.h>
// #include <ESP8266WiFi.h>
// #include <WiFiClientSecure.h>
// #include <UniversalTelegramBot.h>

// // WiFi credentials
// const char* ssid = "OPPOReno8T5G";
// const char* password = "OPPO8T5G";

// // const char* ssid = "Oppo";
// // const char* password = "sadhukutty";

// // Pins
// #define SDA_PIN D6   
// #define SCL_PIN D7
// #define DT_PIN D2
// #define SCK_PIN D3
// const int soundPin = A0;

// // Global variables
// int soundValue = 0;
// int soundLevel = 0;

// HX711 scale;
// WiFiClientSecure secured_client;
// UniversalTelegramBot bot(BOT_TOKEN, secured_client);

// bool isSleeping = false;
// unsigned long sleepStartTime = 0;
// float weightKg = 0;
// LiquidCrystal_I2C lcd(0x27, 16, 2);
// void setup() {
//   Serial.begin(9600);
//   pinMode(soundPin, INPUT);

//   // Connect WiFi
//   Serial.print("Connecting to WiFi");
//   WiFi.begin(ssid, password);
//   secured_client.setInsecure();  // Skip SSL verification
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("\n✅ WiFi connected");

//   // Initialize HX711
//   scale.begin(DT_PIN, SCK_PIN);
//   scale.set_scale();
//   scale.tare();
//   Wire.begin(SDA_PIN, SCL_PIN);  // Use custom I2C pins
//   lcd.init();                   // Initialize the LCD
//   lcd.backlight();   
//   Serial.println("=== SYSTEM READY ===");
// }

// void loop() {
//   // Read weight
//   float rawWeight = scale.get_units(5);
//   float mappedVal = map(rawWeight, -100, 645975, 0, 5000);
//   weightKg = mappedVal / 1000.0;  // in kg

//   // Read sound
//   soundValue = analogRead(soundPin);
//   soundLevel = map(soundValue, 0, 1023, 0, 100);

//   Serial.print("Weight: ");
//   Serial.print(weightKg);
//   Serial.print(" kg | Sound: ");
//   Serial.print(soundLevel);
//   Serial.print("% | Raw: ");
//   Serial.println(soundValue);

//   // Detect Sleep Start
//   if (weightKg >= 1.0 && !isSleeping) {
//     Serial.println("Detected weight ≥ 1kg. Checking sound for 3 seconds...");

//     bool soundDetected = false;
//     unsigned long startCheck = millis();
//     while (millis() - startCheck < 3000) {  
//       int tempSound = analogRead(soundPin);
//       int tempLevel = map(tempSound, 0, 1023, 0, 50);
//       if (tempLevel > 15) {
//         soundDetected = true;
//         break;
//       }
//       delay(100);
//     }

//     if (soundDetected) {
//       bot.sendMessage(chat_id, "😴 User is **Sleeping Partially** (sound detected during initial check).", "");
//       Serial.println("Sleeping Partially...");
//     } else {
//       bot.sendMessage(chat_id, "🛌 User has **Started Sleeping**.", "");
//       Serial.println("Sleeping...");
//     }

//     isSleeping = true;
//     sleepStartTime = millis();
//   }

//   // Detect Wake Up
//   if (weightKg < 1.0 && isSleeping) {
//     unsigned long sleepEndTime = millis();
//     unsigned long sleepDuration = sleepEndTime - sleepStartTime;

//     unsigned long seconds = (sleepDuration / 1000) % 60;
//     unsigned long minutes = (sleepDuration / (1000 * 60)) % 60;
//     unsigned long hours = (sleepDuration / (1000 * 60 * 60));

//     char msg[200];
//     sprintf(msg, "🌅 User has **Woken Up**.\n🕒 Slept for: %lu hr %lu min %lu sec.", hours, minutes, seconds);
//     bot.sendMessage(chat_id, msg, "");

//     Serial.println(msg);

//     isSleeping = false;
//   }

//   // ---------------- LCD DISPLAY ----------------
//   lcd.clear();
//   lcd.setCursor(0, 0);

//   if (soundValue < 290) {
//     lcd.print("Sound Detected");
//   } else {
//     lcd.print("No Sound Detected");
//   }

//   // Show sleep timer if user is sleeping
//   if (isSleeping) {
//     unsigned long elapsed = millis() - sleepStartTime;
//     unsigned long seconds = (elapsed / 1000) % 60;
//     unsigned long minutes = (elapsed / (1000 * 60)) % 60;
//     unsigned long hours = (elapsed / (1000 * 60 * 60));

//     lcd.setCursor(0, 1);
//     lcd.print("Sleep ");
//     lcd.print(hours);
//     lcd.print("h:");
//     if (minutes < 10) lcd.print("0");
//     lcd.print(minutes);
//     lcd.print("m:");
//     if (seconds < 10) lcd.print("0");
//     lcd.print(seconds);
//     lcd.print("s");
//   } else {
//     lcd.setCursor(0, 1);
//     lcd.print("Not Sleeping");
//   }

//   delay(500);
// }


// // #define BOT_TOKEN "8463522663:AAF5XLfpL0djxhSwHzX-22k0J8Ll-_LDsMM"
// // String chat_id = "7139649414";

// // #include <Wire.h>
// // #include <LiquidCrystal_I2C.h>
// // #include <HX711.h>
// // #include <ESP8266WiFi.h>
// // #include <WiFiClientSecure.h>
// // #include <UniversalTelegramBot.h>

// // // WiFi credentials
// // const char* ssid = "OPPOReno8T5G";
// // const char* password = "OPPO8T5G";

// // // const char* ssid = "Oppo";
// // // const char* password = "sadhukutty";

// // // Pins
// // #define SDA_PIN D6   
// // #define SCL_PIN D7
// // #define DT_PIN D2
// // #define SCK_PIN D3
// // const int soundPin = A0;

// // // Global variables
// // int soundValue = 0;
// // int soundLevel = 0;

// // HX711 scale;
// // WiFiClientSecure secured_client;
// // UniversalTelegramBot bot(BOT_TOKEN, secured_client);

// // bool isSleeping = false;
// // unsigned long sleepStartTime = 0;
// // float weightKg = 0;
// // LiquidCrystal_I2C lcd(0x27, 16, 2);
// // void setup() {
// //   Serial.begin(9600);
// //   pinMode(soundPin, INPUT);

// //   // Connect WiFi
// //   Serial.print("Connecting to WiFi");
// //   WiFi.begin(ssid, password);
// //   secured_client.setInsecure();  // Skip SSL verification
// //   while (WiFi.status() != WL_CONNECTED) {
// //     delay(500);
// //     Serial.print(".");
// //   }
// //   Serial.println("\n✅ WiFi connected");

// //   // Initialize HX711
// //   scale.begin(DT_PIN, SCK_PIN);
// //   scale.set_scale();
// //   scale.tare();
// //   Wire.begin(SDA_PIN, SCL_PIN);  // Use custom I2C pins
// //   lcd.init();                   // Initialize the LCD
// //   lcd.backlight();   
// //   Serial.println("=== SYSTEM READY ===");
// // }

// // void loop() {
// //   // Read weight
// //   float rawWeight = scale.get_units(5);
// //   float mappedVal = map(rawWeight, -100, 645975, 0, 5000);
// //   weightKg = mappedVal / 1000.0;  // in kg

// //   // Read sound
// //   soundValue = analogRead(soundPin);
// //   soundLevel = map(soundValue, 0, 1023, 0, 100);

// //   Serial.print("Weight: ");
// //   Serial.print(weightKg);
// //   Serial.print(" kg | Sound: ");
// //   Serial.print(soundLevel);
// //   Serial.print("% | Raw: ");
// //   Serial.println(soundValue);

// //   // Detect Sleep Start
// //   if (weightKg >= 1.0 && !isSleeping) {
// //     Serial.println("Detected weight ≥ 1kg. Checking sound for 3 seconds...");

// //     bool soundDetected = false;
// //     unsigned long startCheck = millis();
// //     while (millis() - startCheck < 3000) {  
// //       int tempSound = analogRead(soundPin);
// //       int tempLevel = map(tempSound, 0, 1023, 0, 50);
// //       if (tempLevel > 15) {
// //         soundDetected = true;
// //         break;
// //       }
// //       delay(100);
// //     }

// //     if (soundDetected) {
// //       bot.sendMessage(chat_id, "😴 User is **Sleeping Partially** (sound detected during initial check).", "");
// //       Serial.println("Sleeping Partially...");
// //     } else {
// //       bot.sendMessage(chat_id, "🛌 User has **Started Sleeping**.", "");
// //       Serial.println("Sleeping...");
// //     }

// //     isSleeping = true;
// //     sleepStartTime = millis();
// //   }

// //   // Detect Wake Up
// //   if (weightKg < 1.0 && isSleeping) {
// //     unsigned long sleepEndTime = millis();
// //     unsigned long sleepDuration = sleepEndTime - sleepStartTime;

// //     unsigned long seconds = (sleepDuration / 1000) % 60;
// //     unsigned long minutes = (sleepDuration / (1000 * 60)) % 60;
// //     unsigned long hours = (sleepDuration / (1000 * 60 * 60));

// //     char msg[200];
// //     sprintf(msg, "🌅 User has **Woken Up**.\n🕒 Slept for: %lu hr %lu min %lu sec.", hours, minutes, seconds);
// //     bot.sendMessage(chat_id, msg, "");

// //     Serial.println(msg);

// //     isSleeping = false;
// //   }

// //   // ---------------- LCD DISPLAY ----------------
// //   lcd.clear();
// //   lcd.setCursor(0, 0);

// //   if (isSleeping) {
// //     if (soundValue < 290) {
// //       lcd.print("Sound Detected");
// //     } else {
// //       lcd.print("No Sound Detected");
// //     }

// //     // Show sleep timer if user is sleeping
// //     unsigned long elapsed = millis() - sleepStartTime;
// //     unsigned long seconds = (elapsed / 1000) % 60;
// //     unsigned long minutes = (elapsed / (1000 * 60)) % 60;
// //     unsigned long hours = (elapsed / (1000 * 60 * 60));

// //     lcd.setCursor(0, 1);
// //     lcd.print("Sleep ");
// //     lcd.print(hours);
// //     lcd.print("h:");
// //     if (minutes < 10) lcd.print("0");
// //     lcd.print(minutes);
// //     lcd.print("m:");
// //     if (seconds < 10) lcd.print("0");
// //     lcd.print(seconds);
// //     lcd.print("s");
// //   } else {
// //     lcd.print("Weight: ");
// //     lcd.print(weightKg, 1);
// //     lcd.print(" kg");

// //     lcd.setCursor(0, 1);
// //     lcd.print("Not Sleeping");
// //   }

// //   delay(500);
// // }

#define BOT_TOKEN "8463522663:AAF5XLfpL0djxhSwHzX-22k0J8Ll-_LDsMM"
String chat_id = "7139649414";

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <HX711.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

// WiFi credentials
const char* ssid = "OPPOReno8T5G";
const char* password = "OPPO8T5G";

// const char* ssid = "Oppo";
// const char* password = "sadhukutty";

// Pins
#define SDA_PIN D6   
#define SCL_PIN D7
#define DT_PIN D2
#define SCK_PIN D3
const int soundPin = A0;

// Global variables
int soundValue = 0;
int soundLevel = 0;

HX711 scale;
WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);

bool isSleeping = false;
unsigned long sleepStartTime = 0;
float weightKg = 0;
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  Serial.begin(9600);
  pinMode(soundPin, INPUT);

  // Connect WiFi
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  secured_client.setInsecure();  // Skip SSL verification
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n✅ WiFi connected");

  // Initialize HX711
  scale.begin(DT_PIN, SCK_PIN);
  scale.set_scale();
  scale.tare();
  Wire.begin(SDA_PIN, SCL_PIN);  // Use custom I2C pins
  lcd.init();                   // Initialize the LCD
  lcd.backlight();   
  Serial.println("=== SYSTEM READY ===");
}

void loop() {
  // Read weight
  float rawWeight = scale.get_units(5);
  float mappedVal = map(rawWeight, -100, 645975, 0, 5000);
  weightKg = mappedVal / 1000.0;  // in kg

  // Read sound
  soundValue = analogRead(soundPin);
  soundLevel = map(soundValue, 0, 1023, 0, 100);

  Serial.print("Weight: ");
  Serial.print(weightKg);
  Serial.print(" kg | Sound: ");
  Serial.print(soundLevel);
  Serial.print("% | Raw: ");
  Serial.println(soundValue);

  // Detect Sleep Start
  if (weightKg >= 1.0 && !isSleeping) {
    Serial.println("Detected weight ≥ 1kg. Checking sound for 3 seconds...");

    bool soundDetected = false;
    unsigned long startCheck = millis();
    while (millis() - startCheck < 3000) {  
      int tempSound = analogRead(soundPin);
      int tempLevel = map(tempSound, 0, 1023, 0, 50);
      if (tempLevel > 15) {
        soundDetected = true;
        break;
      }
      delay(100);
    }

    if (soundDetected) {
      bot.sendMessage(chat_id, "😴 User is **Sleeping Partially** (sound detected during initial check).", "");
      Serial.println("Sleeping Partially...");
    } else {
      bot.sendMessage(chat_id, "🛌 User has **Started Sleeping**.", "");
      Serial.println("Sleeping...");
    }

    isSleeping = true;
    sleepStartTime = millis();
  }

  // Detect Wake Up
  if (weightKg < 1.0 && isSleeping) {
    unsigned long sleepEndTime = millis();
    unsigned long sleepDuration = sleepEndTime - sleepStartTime;

    unsigned long seconds = (sleepDuration / 1000) % 60;
    unsigned long minutes = (sleepDuration / (1000 * 60)) % 60;
    unsigned long hours = (sleepDuration / (1000 * 60 * 60));

    char msg[200];
    sprintf(msg, "🌅 User has **Woken Up**.\n🕒 Slept for: %lu hr %lu min %lu sec.", hours, minutes, seconds);
    bot.sendMessage(chat_id, msg, "");

    Serial.println(msg);

    isSleeping = false;
  }

  // ---------------- LCD DISPLAY ----------------
  lcd.clear();
  lcd.setCursor(0, 0);

  if (soundValue < 290) {
    lcd.print("Sound Detected");
  } else {
    lcd.print("No Sound Detected");
  }

  // Show sleep timer if user is sleeping
  if (isSleeping) {
    unsigned long elapsed = millis() - sleepStartTime;
    unsigned long seconds = (elapsed / 1000) % 60;
    unsigned long minutes = (elapsed / (1000 * 60)) % 60;
    unsigned long hours = (elapsed / (1000 * 60 * 60));

    lcd.setCursor(0, 1);
    lcd.print("Sleep ");
    lcd.print(hours);
    lcd.print("h:");
    if (minutes < 10) lcd.print("0");
    lcd.print(minutes);
    lcd.print("m:");
    if (seconds < 10) lcd.print("0");
    lcd.print(seconds);
    lcd.print("s");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Not Sleeping");
  }

  delay(500);
}