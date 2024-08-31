# Helium IoT Network Sensor Development board | H2S-Dev V1.2
## Hardware review

### Circuit schematic

The circuit schematic of the Helium IoT Network Sensor Development board (H2S-Dev V1.2) is shown on the picture below. Central area presents the MCU and optional GNSS module together with the LoRa radio module and antenna connector.

![](https://github.com/hobbyiot/HELIUM-SENSORS/blob/main/H2S-Dev%20V1.2/PICS/H2S-Dev%20V1.2%20SCH.PNG)

On the left the mandatory I/O interface connectors are situated. Right part consists the optional connectors. On the bottom part of the sheet the battery input and charging circuitry are placed together with the DC/DC converter responsible for generating the supply voltage for the entire design. LED indicators and a Reset switch are placed according to their corresponding function.

The schematic is drawn on a A3 standard page. Detailed schematic in PDF format: [H2S-Dev V1.2 Schematic](https://github.com/hobbyiot/HELIUM-SENSORS/blob/main/H2S-Dev%20V1.2/HW/H2S-Dev%20V1.2%20Schematic.pdf)

### Printed Circuit board

The printed circuit board (PCB) of the Helium IoT Network Sensor Development board (H2S-Dev V1.2) is designed to use a standard FR-4 1.6 mm 2-layer material for production.

H2S-Dev V1.2 Top Layer     |  H2S-Dev V1.2 Bottom Layer
:-------------------------:|:-------------------------:
![](https://github.com/hobbyiot/HELIUM-SENSORS/blob/main/H2S-Dev%20V1.2/PICS/H2S-Dev%20V1.2%20TL%203D.PNG)  |  ![](https://github.com/hobbyiot/HELIUM-SENSORS/blob/main/H2S-Dev%20V1.2/PICS/H2S-Dev%20V1.2%20BL%203D.PNG)

Main parts are situated for convenient operation and minimal interference between radios implemented. The LoRa module pin 1 to U.FL antenna small trace is routed with a special attention to ensure the 50 ohm impedance requirement of that trace. The GNSS module is far away, on the other edge of the board, and it is surrounded by solid copper regions on both top and bottom copper layers according the recommendations for proper reception of the satellite signals by the small chip antenna.

JST battery connector and USB-C power socket are situated on the down left of the board close to the corresponding circuitry. Programming interface is a 7-pin heder for conncting a suitable module to burn a software sketch into the MCU via serial interface.

On the top of the board 2x20 connector and Groove compatible footprints are located. Both of them carry powering and I2C interfaces.

![](https://github.com/hobbyiot/HELIUM-SENSORS/blob/main/H2S-Dev%20V1.2/PICS/H2S-Dev%20V1.2.PNG)

The size and mechanics and 2x20 connector connections of the Helium IoT Network Sensor Development board V1.2 comply with the recent RaspberryPi specifications.

The hardware of the Helium IoT Network Sensor Development board V1.2 is designed as an opensource project in the Altium Circuit Maker environment. To access project follow the links below.

https://workspace.circuitmaker.com/Projects/Details/sivanovbg/H2S-Dev-V12

https://365.altium.com/files/AC741A32-A420-4803-868D-E6CB6756A587
#
More useful information: [H2S-Dev board Hardware description and features](https://github.com/hobbyiot/HELIUM-SENSORS/blob/main/H2S-Dev%20V1.1/DOCS/H2S-Dev%20board%20Hardware%20description%20and%20features.pdf)

