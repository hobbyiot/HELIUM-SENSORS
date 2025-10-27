## H2S-Dev software environment setup

Under construction ...

1. Download and install Arduino
2. Install libraries: LMIC, DHT Sensors, TinyGPS
3. Setup lmic_project_config file according your region; set SX1276, enable interrupts
4. Download the sample code from that repo
5. Login into Helium console, create device and copy the credentials including APPEUI, DEVEUI and APPKEY into the example code config file
6. Connect your H2S-Dev to your computer using a standard ESP32 programmer
7. Compile and upload your code.
8. Watch the Helium console for data arriving! Enjoy!
