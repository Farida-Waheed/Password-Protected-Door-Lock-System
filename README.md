# 🔐 Password-Based Door Lock System

A microcontroller-based secure door lock system developed using the **8051 microcontroller**. This system integrates a keypad, LCD, LEDs, and buzzer to manage access using password authentication.

## 🏫 Project Information

- **University:** Benha University, Faculty of Engineering (Shoubra)
- **Department:** Communications and Computer Engineering
- **Course:** Microprocessors and Microcontroller

## 👩‍💻 Team Members

- Farida Waheed Abdel Bary 
- Nourhan Farag Mohamed 
- Malak Mounier Abdellatif 
- Razan Ahmed Fawzy 
- Nour Hesham Elsayed 
- Lujain Ahmed Yousef 
- Raneem Ahmed Refaat 

## 📌 Project Overview

The system is designed to:
- Allow access via a 5-digit password.
- Lock/unlock a door for a specified period (5 seconds).
- Display system messages using an LCD.
- Trigger an alert (buzzer + LCD warning) after 3 incorrect attempts.

## 🧠 System Features

- **Microcontroller**: 8051
- **LCD Display**: Provides user interaction and system feedback
- **Keypad**: 4x3 matrix used for password input
- **LEDs**: Red and Green indicators for access status
- **Buzzer**: Alerts on suspicious activity (3 wrong attempts)
- **Password Storage**: Stored in memory using `DB` directives

## ⚙️ Components & Connections

| Component      | Port/Pin (8051) | Description                     |
|----------------|-----------------|---------------------------------|
| LCD RS         | P2.0            | Register select                 |
| LCD RW         | P2.1            | Read/Write control              |
| LCD E          | P2.2            | Enable                          |
| LCD Data (D0-D7)| P3.0 - P3.7    | Data transfer                   |
| Keypad Rows    | P1.0 - P1.3     | Scanning input rows             |
| Keypad Columns | P1.4 - P1.7     | Scanning input columns          |
| Green LED      | P2.4            | Success indicator               |
| Red LED        | P2.3            | Error indicator                 |
| Buzzer         | P0.0            | Sound alert via transistor      |

## 🧾 How It Works

1. System initializes and displays a welcome message.
2. Waits for a 5-digit password via keypad.
3. If correct:
   - Unlocks the door.
   - Displays "Access Granted".
   - Waits 5 seconds, then re-locks.
4. If incorrect:
   - Shows "Wrong Pass".
   - After 3 failed attempts: buzzer + "Intruder Alert".

## 📐 Algorithm Flow

1. Init system & LCD
2. Read password input
3. Compare with stored password
4. Branch to:
   - `SUCCESS` routine
   - `FAIL` routine (with `ATTEMPT` counter)
5. Activate `ALERT` after 3 failures

## 🧪 Testing Results

| Test Case                         | Expected Result                  | Passed |
|----------------------------------|----------------------------------|--------|
| Correct password                 | Door unlocks for 5 seconds       | ✅     |
| One incorrect password           | "Wrong Pass" on LCD              | ✅     |
| Three incorrect passwords        | Buzzer + "Intruder Alert"        | ✅     |

## 💾 Assembly Files

- `DoorLock.a51`: Main program source
- `STARTUP.A51`: Initialization routines
- `.uvproj`, `.uvopt`, `.uvgui.*`: Keil project files

## 🖼 Circuit Design

- **Proteus Simulation**: Included in `.pdsprj` file (`Door_lock.pdsprj`)
- **Real Circuit Implementation**: Breadboard + LCD + keypad setup

## 📷 Screenshots

- **Images of the simulation**:
![image](https://github.com/user-attachments/assets/4bf72fa7-c3b2-45bc-91d1-6f0ede90e1c3)
- **Images of the real circuit**:
![image](https://github.com/user-attachments/assets/1c5f6558-cfab-4c4c-a1e5-f9dca3a5803a)
## 🛠 Tools Used

- **Keil µVision** – Assembly programming
- **Proteus** – Simulation of 8051 circuit
- **8051 Microcontroller Kit** – Hardware implementation



