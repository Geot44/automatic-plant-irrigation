# 🌱 Automatic Plant Irrigation System (ESP8266)

An automatic irrigation system using the **ESP8266 microcontroller** and a **capacitive soil moisture sensor**.  
The system measures soil moisture and activates a **gravity-based drip irrigation contraption** that delivers water drop by drop, ensuring efficient use of water and healthier plant growth.

---

## 🚀 Features

### ✅ Current Implementation
- Reads soil moisture values using a capacitive sensor.  
- Activates a gravity-fed water contraption when soil moisture drops below a set threshold.  
- Conserves water by irrigating **only when needed**.  

### 🧪 Testing Code
- A secondary sketch is provided to test the moisture sensor.  
- Instead of controlling the pump, this version uses the **ESP8266 onboard LED**:  
  - LED ON → Moisture sufficient.  
  - LED OFF → Soil dry.  

### 🔮 Planned Enhancements
- Refined pump control with relay modules for greater precision.  
- Mobile app integration for live monitoring and control.  
- Addition of NPK sensor for soil fertility assessment.  
- Integration of air humidity / weather data for predictive irrigation.  
- AI-based soil health and irrigation recommendations.  

---

## 🛠️ Hardware Components
- ESP8266 Development Board (e.g., NodeMCU / Wemos D1 Mini).  
- Capacitive Soil Moisture Sensor.  
- Gravity-based drip irrigation contraption (3D-printable / DIY).  

---

## 💻 Software Requirements
- [Arduino IDE](https://www.arduino.cc/en/software)  
- ESP8266 Board Package  
  - Add this URL in Arduino IDE → **File → Preferences → Additional Boards Manager URLs**:  
    ```
    http://arduino.esp8266.com/stable/package_esp8266com_index.json
    ```
- Required libraries: *none for current stage*.  

---

## 📂 Project Structure
automatic-plant-irrigation/
├── src/
│ ├── main/ # Main irrigation system code (sensor + pump)
│ └── tests/ # Testing code (sensor + LED simulation)
├── docs/ # Documentation, circuit diagrams, reports
└── README.md # Project overview (this file)

---

## ⚙️ Setup & Usage

1. **Clone the repository**
   ```bash
   git clone https://github.com/HardwareHustler/automatic-plant-irrigation.git
   cd automatic-plant-irrigation
Main Code (with Pump)

Navigate to src/main/.

Open the .ino file in Arduino IDE.

Upload to ESP8266.

Insert sensor in soil, set threshold, and observe pump operation.

Testing Code (with LED)

Navigate to src/tests/.

Open the .ino file in Arduino IDE.

Upload to ESP8266.

Check Serial Monitor readings and onboard LED response.

📊 Calibration & Thresholds

Sensor readings vary by soil and sensor unit.

To calibrate:

Measure raw values in dry soil.

Measure in wet soil.

Choose a threshold between the two.

Update the moistureThreshold in the code accordingly.

📌 Roadmap

Stage 2: Relay-controlled precision pump.

Stage 3: Mobile app (Wi-Fi monitoring).

Stage 4: Soil fertility (NPK sensor).

Stage 5: AI-based predictive irrigation.
