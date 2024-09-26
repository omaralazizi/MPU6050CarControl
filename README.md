# MPU6050CarControl
moving car with hand motion
Project Overview
MPU6050CarControl is an AVR-based project designed to control a 4-DC motor car using hand gestures. The project consists of two main devices:

Hand Device:

  Components: MPU6050 accelerometer & gyroscope, LCD display, HC-05 Bluetooth module, ATmega328P.
  Function: Captures hand movements and transmits control signals via Bluetooth.
  
Car Device:

  Components: 4 DC motors, H-Bridge (motor driver), HC-05 Bluetooth module, ATmega328P.
  Function: Receives control signals from the hand device and moves the car accordingly.
  
Key Features

  MPU6050 Gesture Control: Captures hand movements for forward, backward, left, and right motion in addition to controlling the speed.
  LCD Display: Displays feedback on hand position and precentage of the car speed.
  Bluetooth Communication: HC-05 modules facilitate wireless communication between the hand device and the car.
  Low-Level AVR Programming: Written in C, using direct register manipulation for precise control of peripherals and hardware.
  
Hardware Requirements
  Hand Device:
    MPU6050 (accelerometer & gyroscope)
    16x2 LCD
    HC-05 Bluetooth module
    ATmega328P microcontroller
 Car Device:
    4 DC motors
    L298N H-Bridge motor driver
    HC-05 Bluetooth module
    ATmega328P microcontroller
    
Software Overview

The code for both devices is written in C with low-level AVR programming to ensure efficient and precise control over hardware components. Key peripherals (I2C, UART, Timer/Counter, and GPIO) are controlled via direct register access, providing a fast and optimized control system.

Hand Device

MPU6050: The sensor data is processed to determine the orientation and movement of the hand.
LCD: Displays real-time hand movement information and status updates.
Bluetooth (HC-05): Transmits the hand movement data to the car.

Car Device

Bluetooth (HC-05): Receives the data from the hand device.
Motor Control: Based on the received signals, the car moves forward, backward, or turns using the 4 DC motors controlled by the L298N H-Bridge.
