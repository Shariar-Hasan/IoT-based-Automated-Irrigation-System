# IoT based Automated Irrigation System & Mobile App for Tea Garden

![IoT based Automated Irrigation System & Mobile App for Tea Garden](./cover.png)

## B.Sc. Engineering Thesis

### Course Code: CSE 800

#### Submitted to:

Department of Computer Science & Engineering  
University of Chittagong

---

<center> 
![GitHub Repo Stars](https://img.shields.io/github/stars/Shariar-Hasan/IoT-based-Automated-Irrigation-System.svg?style=social) ![License](https://img.shields.io/badge/license-MIT-blue.svg) [![Build Status](https://travis-ci.com/Shariar-Hasan/IoT-based-Automated-Irrigation-System.svg?branch=master)](https://travis-ci.com/Shariar-Hasan/IoT-based-Automated-Irrigation-System) [![Download ZIP](https://img.shields.io/badge/Download-ZIP-brightgreen.svg)](https://codeload.github.com/Shariar-Hasan/IoT-based-Automated-Irrigation-System/zip/refs/heads/main)</center>
---

## Table of Contents

- [Project Overview](#project-overview)
- [Project Features](#project-features)
- [Installation and Setup](#installation-and-setup)
- [Usage](#usage)
- [Contact](#contact)
- [License](#license)

## Project Overview

The **IoT based Automated Irrigation System & Mobile App for Tea Garden** is a B.Sc. Engineering thesis project carried out in partial fulfillment of the requirements for the degree of B.Sc. (Engineering) in Computer Science and Engineering at the University of Chittagong. This project aims to develop an automated irrigation system for tea gardens using Internet of Things (IoT) technology along with a mobile app interface.

---

## Project Features

- **Automated Irrigation:** The system utilizes various sensors, including soil moisture and rain sensors, to determine the optimal irrigation needs for the tea garden.
- **Mobile App Interface:** A mobile app is developed to provide real-time monitoring and control of the irrigation system remotely. The Pumping motor can also be manually turn OFF or ON by the Mobile App.
- **Weather Status:** The system can detect rain and sunny conditions using the rain sensor, providing accurate weather data to assist in irrigation decisions.
- **Soil Moisture Monitoring:** Soil moisture sensors measure the soil's moisture level, ensuring that plants receive the appropriate amount of water.
- **Water Pump Control:** The system automatically controls the water pump based on the weather conditions and soil moisture levels.

---

## Installation and Setup

1. Clone this repository to your local machine.
2. Install the required libraries using the Arduino IDE's Library Manager:
   - ESP8266WiFi
   - BlynkSimpleEsp8266
3. Open the Arduino IDE and load the **Project Arduino Code** in Final Defence Section.
4. Replace the placeholder values in the code with your WiFi credentials and Blynk authentication token.
5. Upload the code to your ESP8266 device using cable connector.
6. Install the Blynk app on your mobile device and create a project using the provided template ID and name.
   ![Setup](./Final%20Defence/Assets/Overview%201.png)

---

## Usage

1. Power up your ESP8266 device.
2. Turn on the Wifi Router or Mobile hotspot where you want to connect.
3. Launch the Blynk app on your mobile device and connect to the project.
4. Monitor the soil moisture and weather status in real-time.
5. Control the water pump manually or let the system automate the irrigation based on sensor readings.
   ![Usage](./Final%20Defence/Assets/Overview%202.png)

---

## Contact

For questions or inquiries, please contact:

- Shariar Hasan
- Email: shahriar.hasan.1523@gmail.com

---

## License

This project is licensed under the [MIT License](LICENSE).
