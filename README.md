# ⚡ AI Smart EV Charging Station

An **AI-based Smart EV Charging Station** developed using **ESP32**, **MQTT**, **ThingsBoard**, sensors, and intelligent energy-management concepts for monitoring and optimizing EV charging.

The project is designed to demonstrate how an ESP32-based charging station can collect sensor data, communicate with a cloud platform, respond to control commands, and apply intelligent charging-management logic.

---

## 🚗 Project Overview

Traditional EV charging stations can operate without considering factors such as:

* Station load
* Charging current
* Energy demand
* Peak-tariff periods
* Charging-state information
* Remote monitoring

This project addresses these requirements using an **ESP32-based IoT architecture**.

The ESP32 acts as the main controller and communicates with **ThingsBoard through MQTT**.

### Basic Architecture

```text
              ┌─────────────────────┐
              │     ThingsBoard      │
              │   Cloud Platform     │
              └──────────┬──────────┘
                         │
                    MQTT / Wi-Fi
                         │
                         ▼
              ┌─────────────────────┐
              │        ESP32        │
              │   Main Controller   │
              └──────────┬──────────┘
                         │
          ┌──────────────┼──────────────┐
          │              │              │
          ▼              ▼              ▼
       Sensors        Relay/Load     Charging
      & Inputs        Control        Station
          │
          ▼
    Data Processing
          │
          ▼
   Intelligent Energy
      Management
```

---

## ✨ Main Features

* ESP32-based embedded controller
* Wi-Fi connectivity
* MQTT communication
* ThingsBoard cloud integration
* Sensor data collection
* Remote telemetry monitoring
* Shared-attribute configuration
* RPC-based remote control
* Relay/control output handling
* Charging-station state management
* Load and current-limit management
* Peak-tariff configuration
* Intelligent energy-management logic
* Wokwi simulation support

---

## 🧠 Intelligent Energy Management

The project contains software modules for intelligent charging and energy-management functions.

The system can work with parameters such as:

```text
Maximum Station Load
Overload Current Limit
Peak Tariff Start Time
Peak Tariff End Time
Prediction Threshold
```

These parameters can be configured through ThingsBoard shared attributes.

The ESP32 receives the configuration through MQTT and applies the corresponding logic locally.

---

## ☁️ ThingsBoard & MQTT

The ESP32 communicates with ThingsBoard using the **MQTT protocol**.

### Communication Flow

```text
ESP32
  │
  │ Wi-Fi
  ▼
Internet
  │
  │ MQTT
  ▼
ThingsBoard
  │
  ├── Telemetry
  ├── Shared Attributes
  └── RPC Commands
```

### Telemetry

The ESP32 can publish device/station information to ThingsBoard for cloud monitoring.

Typical telemetry can include sensor and charging-related parameters.

### Shared Attributes

Shared attributes allow configuration values to be provided by ThingsBoard.

Examples used by this project include:

```text
maxStationLoadW
overloadCurrentA
peakTariffStartHr
peakTariffEndHr
predictionThreshold
```

### RPC

ThingsBoard RPC can be used for sending control commands from the cloud to the ESP32.

This provides a mechanism for remote device control.

---

## 🔧 Hardware

The project is based around an **ESP32 development board**.

Depending on the station configuration, the system can interface with:

* ESP32 DevKit
* DHT sensor
* LEDs
* Push buttons
* Relay/control output
* Charging/load-related inputs
* Other station peripherals

> Hardware configuration may vary depending on the simulation or physical implementation.

---

## 💻 Software & Tools

| Tool / Technology | Purpose                      |
| ----------------- | ---------------------------- |
| ESP32             | Main microcontroller         |
| Embedded C/C++    | Firmware development         |
| Arduino Framework | ESP32 firmware framework     |
| PlatformIO        | Build and project management |
| VS Code           | Development environment      |
| MQTT              | Device-cloud communication   |
| ThingsBoard       | IoT cloud platform           |
| Wokwi             | ESP32 simulation/testing     |
| Git & GitHub      | Version control              |

---

## 📁 Project Structure

```text
AI-Smart-EV-Charging-Station/
│
├── include/
│   ├── Peripherals.h
│   ├── State.h
│   ├── attributes.h
│   ├── config.h
│   ├── edge_ai.h
│   ├── network.h
│   ├── optimization.h
│   ├── rpc.h
│   └── telementry.h
│
├── lib/
│
├── src/
│   ├── main.cpp
│   ├── Peripherals.cpp
│   ├── State.cpp
│   ├── Telementry.cpp
│   ├── attributes.cpp
│   ├── config.cpp
│   ├── edge_ai.cpp
│   ├── network.cpp
│   ├── optimization.cpp
│   ├── rpc.cpp
│   └── model.h
│
├── test/
│   ├── diagram.json
│   ├── wokwi.toml
│   └── README
│
├── .gitignore
└── platformio.ini
```

---

## 🔌 Firmware Modules

### `main.cpp`

Main firmware entry point.

Responsible for initializing the system and running the main application loop.

### `network.cpp`

Handles network/Wi-Fi-related functionality required for communication.

### `attributes.cpp`

Handles ThingsBoard shared-attribute requests and configuration updates.

### `rpc.cpp`

Contains Remote Procedure Call functionality for cloud-to-device commands.

### `Telementry.cpp`

Handles telemetry-related data communication.

### `Peripherals.cpp`

Contains peripheral-related functionality such as inputs and outputs.

### `State.cpp`

Maintains charging-station/system state information.

### `optimization.cpp`

Contains energy-management and charging optimization logic.

### `edge_ai.cpp`

Contains the project's edge-AI-related functionality.

---

## 🔄 System Working Flow

```text
             START
               │
               ▼
        Initialize ESP32
               │
               ▼
       Initialize Sensors
               │
               ▼
          Connect Wi-Fi
               │
               ▼
      Connect to ThingsBoard
               │
               ▼
     Request Configuration
       / Shared Attributes
               │
               ▼
       Read Sensor/Input Data
               │
               ▼
       Process Station State
               │
               ▼
    Energy Management / Logic
               │
               ▼
       Control Output/Relay
               │
               ▼
       Publish Telemetry
               │
               ▼
      Receive RPC Commands
               │
               ▼
             LOOP
```

---

## 🧪 Wokwi Simulation

The repository includes Wokwi-related files:

```text
test/
├── diagram.json
└── wokwi.toml
```

These files can be used for ESP32 simulation and testing where supported by the project configuration.

---

## ⚙️ PlatformIO Configuration

The project uses:

```ini
[env:esp32doit-devkit-v1]
platform = espressif32
board = esp32doit-devkit-v1
framework = arduino
```

Required libraries include:

```text
PubSubClient
DHT sensor library
Adafruit Unified Sensor
ArduinoJson
```

---

## 🚀 How to Run

### 1. Clone the repository

```bash
git clone https://github.com/rahulamate2005/AI-Smart-EV-Charging-Station.git
```

### 2. Open the project

Open the project folder in **VS Code** with PlatformIO installed.

### 3. Install dependencies

PlatformIO reads the required libraries from:

```text
platformio.ini
```

### 4. Configure the device

Configure the required Wi-Fi and ThingsBoard/device parameters according to the project's configuration.

### 5. Build

Use PlatformIO:

```text
PlatformIO → Build
```

### 6. Upload

Connect the ESP32 and use:

```text
PlatformIO → Upload
```

### 7. Monitor

Open the serial monitor to observe ESP32 output.

---

## 📡 Communication Architecture

```text
             ┌───────────────┐
             │  EV Charging  │
             │    Station    │
             └───────┬───────┘
                     │
                     ▼
              ┌─────────────┐
              │    ESP32    │
              └──────┬──────┘
                     │
                  Wi-Fi
                     │
                     ▼
                  MQTT
                     │
                     ▼
            ┌────────────────┐
            │  ThingsBoard   │
            │     Cloud      │
            └────────────────┘
                     │
          ┌──────────┴──────────┐
          ▼                     ▼
     Telemetry                RPC
          │                     │
          ▼                     ▼
      Monitoring             Control
```

---

## 🎯 Project Objectives

1. Develop an ESP32-based smart EV charging controller.
2. Establish IoT communication using MQTT.
3. Monitor charging-station parameters remotely.
4. Integrate the device with ThingsBoard.
5. Implement configurable charging and load-management parameters.
6. Explore intelligent energy-management techniques.
7. Demonstrate embedded firmware development using ESP32.

---

## 🛠️ Technologies

```text
ESP32
Embedded C/C++
Arduino Framework
PlatformIO
VS Code
MQTT
ThingsBoard
Wi-Fi
ArduinoJson
Wokwi
Git
GitHub
```

---

## 📌 Project Status

**Development Status:** Working Prototype / Development Project

The firmware has been developed and tested in the project environment, with ESP32, MQTT, ThingsBoard, and simulation components integrated into the project.

---

##  Author

Rahul Amate

EEE Student | Embedded Systems & Firmware Enthusiast

### Areas of Interest

* Embedded C
* Embedded Systems
* Firmware Development
* ESP32
* IoT
* MQTT
* Microcontrollers
* Hardware–Software Integration

---

## 📄 License

This project is intended for educational, internship, and portfolio purposes.
