# Helium IoT Network Sensor Development board | H2S-Dev V1.2
## Manufacturing data - Basic variant

### General

Manufacturing data is required to establish the production process of a device. The minimum set of documents include graphical information representing the layers of the printed circuit board (PCB) layers, bill of materials (BOM) of the components, pick-place file with machine instructions of coordinates and rotation of each component to populate on the board as well as assembly drawings of the component sketches on the board. Additional information may include 3D views, real pictures of a prototype and other information to ensure the quality manufacturing process.

### Gerber files

Gerber files contain graphical information of the layers of the PCB. Copper layers, solder mask layers, silk screen print, PCB border and others are used to manufacture the board. Drill files contain information about the coordinates, size and type (round/slot) of the board holes. Gerber and drill files use a specific format related with the classical photo and drill machines used for manufacturing. Number precision (digits after the decimal point) is corresponding to precision of each process used to manufacture the real board.

### Pick-place data

Pick-place data is required for component placement. Each component designator is related to the part position on the board. Coordinates together with rotation information are provided for the manufacturing process. An inspection of the actual placement before soldering is always a good practice.

### Bill of materials (BOM)

Bill of materials (BOM) is the actual list of components used. It contains important information for the exact type defined by the manufacturer and the corresponding part number. Specific parameters like voltage, current, material, etc. are also part of the BOM. It may also include other useful information as per manufacturer's requirements.

### H2S-Dev V1.2 Variants

Helium IoT Network Sensor Development board (H2S-Dev V1.2) has several assembly variants suitable for a specific user application. The basic variant include ESP32 MCU, LoRa module, power supply as well as LED indicators and programming interface. The Full variant additionally incorporates a GNSS module and RaspberryPi interface connector. Variations of the MCU are also possible related to the RAM size required.

#
The hardware of the Helium IoT Network Sensor Development board V1.2 is designed as an open source project in the Altium Circuit Maker environment. To access the project follow the links below.

https://workspace.circuitmaker.com/Projects/Details/sivanovbg/H2S-Dev-V12

https://365.altium.com/files/AC741A32-A420-4803-868D-E6CB6756A587
#
More useful information: [H2S-Dev board Hardware description and features](https://github.com/hobbyiot/HELIUM-SENSORS/blob/main/H2S-Dev%20V1.1/DOCS/H2S-Dev%20board%20Hardware%20description%20and%20features.pdf)
