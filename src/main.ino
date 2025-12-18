// ESP8266 Automatic Plant Watering System
const int moisturePin = A0;     // Moisture sensor
const int relayPin = 5;         // Relay control (GPIO5 = D1 on NodeMCU)

// Calibrated values (adjust after testing)
const int dryValue = 790;  
const int wetValue = 360;  

// Moisture threshold (%)
const int lowMoistureThreshold = 20;

// Pump control settings
const int pumpDuration = 2000;      // Run pump for 5 seconds
const int checkInterval = 30000;    // Check moisture every 30 seconds

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  // Setup relay pin (Active LOW relay)
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);  // Keep pump OFF at startup
  
  Serial.println("\n=== Plant Watering System Started ===");
}

void loop() {
  // Take multiple readings for stability
  int total = 0;
  for(int i = 0; i < 5; i++) {
    total += analogRead(moisturePin);
    delay(100);
  }
  int soilMoistureValue = total / 5;
  
  int moisturePercent = map(soilMoistureValue, dryValue, wetValue, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);
  
  Serial.println("--- Moisture Check ---");
  Serial.print("Raw Value: ");
  Serial.print(soilMoistureValue);
  Serial.print(" | Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");
  
  if (moisturePercent <= lowMoistureThreshold) {
    Serial.println("⚠ SOIL DRY - Activating water pump!");
    
    // Turn ON pump
    digitalWrite(relayPin, LOW);
    delay(pumpDuration);  // Run for specified duration
    
    // Turn OFF pump
    digitalWrite(relayPin, HIGH);
    Serial.println("✓ Pump stopped");
    
  } else {
    Serial.println("✓ Soil moisture OK - No watering needed");
  }
  
  Serial.print("Next check in ");
  Serial.print(checkInterval/1000);
  Serial.println(" seconds\n");
  
  delay(checkInterval);  // Wait before next check
}
