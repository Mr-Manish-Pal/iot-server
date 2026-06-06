# 🚀 ESP32 Wireless Sensor Monitoring System

<p align="center">
  <img src="images/dashboard.png" width="850">
</p>

<p align="center">
  <img src="https://img.shields.io/badge/ESP32-IoT-blue?style=for-the-badge">
  <img src="https://img.shields.io/badge/WiFi-Enabled-success?style=for-the-badge">
  <img src="https://img.shields.io/badge/HTTP-Communication-orange?style=for-the-badge">
  <img src="https://img.shields.io/badge/PlatformIO-Embedded-red?style=for-the-badge">
</p>

<p align="center">
Real-Time Wireless Sensor Monitoring using Dual ESP32 Architecture
</p>

---

## 🎯 Project Highlights

✅ Dual ESP32 Client-Server Architecture

✅ Real-Time Sensor Monitoring

✅ HTTP-Based Wireless Communication

✅ Web Dashboard Hosting on ESP32

✅ Air Quality Monitoring using MQ135

✅ Obstacle Detection using IR Sensor

✅ Scalable IoT Infrastructure

---

## 🏆 Why This Project Matters

This project demonstrates a complete embedded IoT workflow:

Sensor Acquisition ➜ Data Processing ➜ Wireless Communication ➜ Web Server ➜ Real-Time Dashboard

Unlike basic ESP32 projects, this implementation follows an actual client-server architecture commonly used in industrial IoT systems.

---

## 📸 System Architecture

```text
┌─────────────────────────┐
│      Sensor Node        │
│       ESP32 #1          │
├─────────────────────────┤
│ MQ135 Air Sensor        │
│ IR Obstacle Sensor      │
└──────────┬──────────────┘
           │
           │ HTTP Requests
           ▼
┌─────────────────────────┐
│      Server Node        │
│       ESP32 #2          │
├─────────────────────────┤
│ Embedded Web Server     │
│ Dashboard Generator     │
└──────────┬──────────────┘
           │
           ▼
┌─────────────────────────┐
│ Browser Dashboard       │
│ Laptop / Mobile         │
└─────────────────────────┘
```

---

## 🎥 Live Demonstration

<p align="center">
  <img src="images/demo.gif" width="850">
</p>

---

## 🛠 Hardware Stack

| Component | Purpose |
|------------|------------|
| ESP32 #1 | Sensor Node |
| ESP32 #2 | Web Server |
| MQ135 | Air Quality Monitoring |
| IR Sensor | Object Detection |
| WiFi Network | Communication Medium |

---

## ⚡ Features

### Sensor Node
- Reads MQ135 values
- Detects objects using IR sensor
- Sends data wirelessly

### Server Node
- Receives HTTP requests
- Stores latest sensor state
- Hosts dashboard

### Dashboard
- Live sensor values
- Auto-refresh
- Network accessible
- Mobile friendly

---

## 📊 Example Dashboard

```text
ESP32 SENSOR SERVER

IR SENSOR
1

MQ135 VALUE
3152

LAST UPDATE
0 sec
```

---

## 🧠 Embedded Concepts Used

- GPIO
- ADC
- WiFi Networking
- HTTP Client
- HTTP Server
- Sensor Interfacing
- Client-Server Architecture
- Embedded Web Development
- IoT System Design

---

## 🚀 Future Upgrades

- MQTT
- ESP-NOW
- Cloud Integration
- Data Logging
- Grafana Dashboard
- Mobile App
- Telegram Alerts
- Multiple Sensor Nodes

---

## 👨‍💻 Author

### Manish Pal

Embedded Systems Engineer (Learning Journey)

Focused on:
- ESP32
- STM32
- Embedded C/C++
- IoT Systems
- Industrial Communication Protocols

⭐ If you like this project, give it a star.