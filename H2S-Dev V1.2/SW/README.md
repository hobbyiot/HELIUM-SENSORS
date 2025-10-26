## H2S-Dev with DHT11 temperature and humidity sensor example

The most recent example code in ([H2S-DEV-THS-V0.5.ino](https://github.com/hobbyiot/HELIUM-SENSORS/blob/main/H2S-Dev%20V1.2/SW/H2S-DEV-THS-V0.5.ino)) sends a valid LoRaWAN packet over The Helium network with a payload containing temperature and humidity data as they are read from a DHT11 sensor, connected to GPIO#13 using frequency and encryption settings according your region.

You can solder and wire the DHT11 sensor within the H2S-Dev soldering area or just use Crowtail connector directly to the H2S-Dev board using the [Elecrow DHT11 sensor module](https://www.elecrow.com/crowtail-temperature-humidity-sensor-p-1229.html).

![](https://github.com/hobbyiot/HELIUM-SENSORS/blob/main/H2S-Dev%20V1.2/PICS/H2S-Dev%20V1.2%20Basic%20%2B%20Crowtail%20DHT11.png)

The data format and the JSON script for decoding it will be soon described in separate article in the project's GitHub (https://github.com/hobbyiot/HELIUM-SENSORS)

You can also direct the received data via Helium console directly to a Google sheet!

![](https://github.com/hobbyiot/HELIUM-SENSORS/blob/main/H2S-Dev%20V1.2/PICS/HD%20Integration.png)
