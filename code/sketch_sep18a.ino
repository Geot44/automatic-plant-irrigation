#include <ESP32Servo.h> // Include the ESP32 Servo library

// Define pins and constants
const int moisturePin = 36; // Using GPIO36 for analog input
const int servoPin = 12;    // Using GPIO12 for the servo signal

// Calibrated values for your specific sensor and soil
const int dryValue = 3000;  // Adjust based on your dry reading
const int wetValue = 1500;  // Adjust based on your wet reading

// Define the threshold for low moisture
const int lowMoistureThreshold = 20; // Trigger action at 20% or less

// Time to sleep in seconds
#define TIME_TO_SLEEP 30 // Sleep for 30 seconds

// Factor to convert seconds to microseconds for the timer
#define uS_TO_S_FACTOR 1000000ULL

// Create a servo object
Servo myServo;

void setup() {
  // Initialize the Serial Monitor
  Serial.begin(115200); 
  delay(1000); // Allow time for the serial connection to open

  // Attach the servo object to the servo pin
  myServo.attach(servoPin);

  Serial.println("Woke up from deep sleep. Taking a moisture reading...");

  // Read the raw analog value from the sensor
  int soilMoistureValue = analogRead(moisturePin);

  // Map the raw value to a percentage and constrain
  int moisturePercent = map(soilMoistureValue, dryValue, wetValue, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);

  // Print the raw value and percentage to the Serial Monitor
  Serial.print("Raw Value: ");
  Serial.print(soilMoistureValue);
  Serial.print(" | Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  // Check for low moisture and rotate the servo
  if (moisturePercent <= lowMoistureThreshold) {
    Serial.println("Warning: Low Moisture Detected! Rotating servo...");
    myServo.write(180); // Rotate the servo to 180 degrees
    delay(2000);        // Wait for 2 seconds
    myServo.write(0);   // Return the servo to 0 degrees
    delay(500);         // Wait for the servo to finish moving
  }

  // Print message and start the timer for the next deep sleep cycle
  Serial.println("Going into deep sleep now");
  
  // Configure the timer wake-up source
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  
  // Clear the serial buffer before sleeping
  Serial.flush();
  
  // Enter deep sleep mode
  esp_deep_sleep_start();
}

void loop() {
  // This section of code will never be reached or executed
}
