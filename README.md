# Embedded System Diploma Project

This repository contains the implementation of the Microcontroller Abstraction Layer (MCAL) and Electronic Control Unit (ECU) layers for the PIC18F46K20 microcontroller board. These modules serve as drivers for various functionalities of the microcontroller, designed according to the specifications outlined in the datasheet of the PIC18F46K20.

## Diploma Information

This project is part of an Embedded System Diploma program, led by: **[Ahmed Abd El-Ghafar El-Kenany](https://www.linkedin.com/in/ahmedabdelghafarmohammed/)**. The diploma focuses on providing hands-on experience and theoretical knowledge in embedded systems, particularly in microcontroller programming and hardware interfacing. Eng. Ahmed Abdulghaffar is an experienced embedded systems engineer with a passion for teaching and guiding aspiring professionals in the field.


## Modules Documentation

### MCAL (Microcontroller Abstraction Layer)

The MCAL module serves as an abstraction layer for the underlying hardware of the PIC18F46K20 microcontroller.
It provides interfaces and functions to interact with various peripherals and features of the microcontroller, such as: <br><br>
- **GPIO (General Purpose Input/Output)**<br>
-  **ADC (Analog-to-Digital Converter)** <br>
-  **UART (Universal Asynchronous Receiver-Transmitter)** <br>
-  **timers (timer0, timer1,timer2, timer3)** <br>
-  **CAPTURE/COMPARE/PWM (CCP) MODULES** <br><br>
The implementation follows the specifications outlined in the PIC18F46K20 datasheet, ensuring compatibility and optimal performance.
[PIC18F46K20 datasheet link](https://ww1.microchip.com/downloads/en/devicedoc/40001303h.pdf)

### ECU (Electronic Control Unit) Layers

The ECU layers encompass higher-level functionalities and drivers built upon the MCAL module. Each ECU layer is designed to control specific components or subsystems of an embedded system. These layers include:

Each module within the repository is thoroughly documented, providing insights into its functionality, usage, and integration with the PIC18F46K20 microcontroller board. Additionally, examples and sample code snippets are included to demonstrate the implementation and usage of each module effectively.
