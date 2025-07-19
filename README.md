#  Moonrider Indicator Control System (Wokwi + ATmega328P)

This project implements an **automotive indicator control system** using the ATmega328P microcontroller on Wokwi. The system handles **Left**, **Right**, and **Hazard** light indicators as per embedded software requirements and simulates real-world logic with GPIO, PWM, UART, and button control.

---

##  Assignment Objectives

- Develop C-based base software for indicator control
- Simulate with ATmega328P on Wokwi
- Blink indicators at 300ms intervals
- Capture button press events using GPIO
- Publish system state logs via UART
- Integrate BLE control (future extension)
- Build application logic modularly for Simulink integration

---

## 🛠 Hardware Simulation Setup (Wokwi)

| Component       | Pin            |
|----------------|----------------|
| Left Button     | D2             |
| Right Button    | D3             |
| Left LED        | D9 (PWM)       |
| Right LED       | D10 (PWM)      |
| UART Output     | Serial Monitor |

---

##  Core Features

-  **1-sec Button Hold**: Detects long-press using scheduler and state tracking
-  **300ms LED Blink**: Non-blocking blink using timer logic
-  **Mode Switching**: Switch between left/right/hazard modes seamlessly
-  **Hazard Mode**: Activated by pressing both buttons together for 1 sec
-  **Debounce Logic**: Avoids retriggering while holding
-  **UART Logging**: Publishes state changes via Serial Monitor

---

## 🧪 How to Use (Wokwi)

1. Open simulation in Wokwi  
2. Press and hold:
   - Left Button (D2) → Toggles Left indicator
   - Right Button (D3) → Toggles Right indicator
   - Both for 1s → Activates Hazard mode
3. Observe LED behavior and Serial logs

▶ [Live Wokwi Simulation](https://wokwi.com/projects/436893161708829697)

---

## 💬 UART Output Examples

```
[INIT] System Initialized
[MODE] LEFT ON
[MODE] RIGHT OFF
[MODE] HAZARD ON
💬 UART Log Output:  
https://github.com/sajidk2002/indicator-control-moonrider/blob/main/UART_LOG.txt

```

---

##  Future Scope

- BLE integration to trigger indicator logic via phone
- Full Simulink model and auto code generation
- Buzzer integration for indicator sound
- CAN logging for vehicle comm systems

---

##  File Structure

```
indicator-control-moonrider/
├── indicator_control.ino      # Main C-based sketch for Wokwi
├── README.md                  # Documentation (this file)
├── UART_LOG.txt               # Serial monitor log (optional)
├── simulation_link.txt        # Wokwi URL
├── video_link.txt             # Google Drive link of the video
```

---

##  Demo & Submission

- ✅ [Google Drive – Video Demonstration](https://drive.google.com/YOUR-VIDEO-LINK)
- ✅ [Wokwi Simulation](https://wokwi.com/projects/436893161708829697)

---

##  Author

**Sajid Muhammad**  
B.Tech ECE 2024 | Embedded Systems Trainee  
[GitHub](https://github.com/YOUR-USERNAME)

