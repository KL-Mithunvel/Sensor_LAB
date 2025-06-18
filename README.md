# Sensor_LAB
BMHA203P Sensors and Instrumentations 
# Specification

## Title of the Invention
**Sensor-Based Safety Control System for Kitchen Mixer Appliances**

---

## Background of the Invention

Kitchen mixers are commonly used household appliances, typically operating at high rotational speeds. Accidents may occur when users inadvertently interact with the mixer blades while they are still spinning, especially during cleaning or ingredient additions. Existing safety mechanisms are either rudimentary (e.g., mechanical latches) or entirely absent.

There is a need for a reliable, sensor-driven safety system that can detect human presence or obstructions near the mixing zone and immediately halt the motor to prevent injury.

---

## Summary of the Invention

The invention relates to a safety control system integrated into kitchen mixers, using proximity and touch sensors to detect the presence of human interaction near dangerous moving parts. The system utilizes a microcontroller unit (MCU), real-time sensor data acquisition, and a power cutoff mechanism (e.g., solid-state relay) to disable motor operation upon detection of potential safety hazards.

The invention improves user safety without impeding regular operation, and can be retrofitted to existing appliances or embedded in new designs.

---

## Brief Description of the Drawings

- **Fig. 1**: System block diagram showing sensor, control unit, motor driver, and power interface
- **Fig. 2**: Circuit schematic for proximity sensor interface
- **Fig. 3**: Flowchart of the safety logic in the control firmware
- **Fig. 4**: Exploded view of mixer assembly with sensor placement

---

## Detailed Description of the Invention

The proposed system comprises the following components:

### 1. Sensors
- **Proximity Sensor (IR or Ultrasonic)** mounted near the mixing bowl detects motion or hand presence.
- **Capacitive Touch Sensor** optionally embedded on the body or lid of the mixer.

### 2. Control Unit
- A **microcontroller** (e.g., Raspberry Pi Pico, Arduino, or STM32) processes sensor data.
- Runs embedded firmware that interprets input conditions and takes action based on predefined safety rules.

### 3. Actuation and Cutoff
- A **solid-state relay (SSR)** or electronic switch is used to **immediately disconnect motor power** when unsafe conditions are detected.

### 4. Power and User Interface
- The system operates on standard AC input with a regulated DC supply for the MCU and sensors.
- An optional **LCD display** provides real-time status updates (e.g., “Safe to Operate”, “Hand Detected – Motor Locked”).

### 5. Operation Logic
- When the system is powered on, it enters standby mode.
- If a start command is received (via button press), the system checks for sensor activity.
- If no hazard is detected, motor is powered on.
- If at any time a sensor detects a safety breach, **the motor is immediately shut off** and a warning is displayed.

---

## Advantages of the Invention

- **Improved Safety**: Immediate response to proximity or touch, reducing injury risk.
- **Retrofittable**: Can be added to existing mixers with minimal modifications.
- **Modular Design**: Allows customization based on appliance size and risk zones.
- **Low-Cost Implementation**: Utilizes widely available components.

---

## Industrial Applicability

This invention is applicable in:
- Household kitchen appliances
- Commercial bakery mixers
- Food processing units where rotating blades are used
- Any consumer appliance with exposed moving parts

---

## Best Mode of Implementation

The preferred embodiment uses:
- **IR proximity sensor** (e.g., Sharp GP2Y0A)
- **Raspberry Pi Pico microcontroller**
- **40A solid-state relay (for 230V AC cut-off)**
- Touch sensor (TTP223 module)
- Powered by a **12V DC adapter**
- Custom PCB for compact installation

---

## Claims

**[NOTE: Not included in this document. Will be written separately with legal definitions.]**

---

## Abstract

A sensor-based safety mechanism for kitchen mixers, utilizing proximity and touch sensors to detect hazardous conditions and immediately halt motor operation via a solid-state relay. The invention enhances user safety without compromising appliance performance and can be integrated into both new and existing mixer designs.

---
