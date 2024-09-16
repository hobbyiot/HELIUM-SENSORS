# Helium IoT Network Sensor Development board | H2S-Dev V1.2
## Main changes and improvements

![](https://github.com/hobbyiot/HELIUM-SENSORS/blob/main/H2S-Dev%20V1.2/PICS/H2S-Dev%20V1.2%20PER.PNG)

- A U.FL connector has been replaced the fixed LoRa spring antenna to improve the flexibility for the developers to connect most suitable antenna according the radio power and frequency requirements;

- A Basic variant of the development board has been defined as a cheap version of the PCB to improve cost efectiveness and design flexibility;

- A Full variant of the development board is now including GNSS module that gives the development of a Helium based GNSS tracking device a kick start to test the application

The project targets a LoRaWAN device - Helium IoT Network Sensor Development board (H2S-Dev) product with GNSS tracking option for primary usage with the LoRaWAN based Helium network. The board is mainly targeted to makers and hobbyists.

It’s built around ESP32 MCU module and LoRaWAN SX1276 based radio module, supporting worldwide radio frequency bands, I2C standard interfaces for connecting various sensors and the relatively cheap integrated GNSS module with small chip antenna on it. The development board also incorporates a standard 7-pin ESP32 serial programming interface to use with any compatible Serial to USB adapter. Set of LED indicators - Power, “1 second” GNSS, Charging and General purpose LEDs are on board for indicating certain activities. USB-C and LiPo battery sockets are available for dual powering with charging circuitry and battery level sensing line routed to a CPU GPIO pin. There is also a development area grid - holes matrix area (4 rows x 8 holes each, 0.1 inch / 2.54 mm pitch) with power and ground points nearby for adding sensors, interfaces, and add-ons. Several GPIOs are routed close to the matrix area.
#
More information: [H2S-Dev board V1.2 Hardware description and features](https://github.com/hobbyiot/HELIUM-SENSORS/blob/main/H2S-Dev%20V1.2/H2S-Dev%20board%20V1.2%20Hardware%20description%20and%20features.pdf)

