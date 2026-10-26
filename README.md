# ESP32 DHT22 Temperature and Humidity Monitoring with ThingSpeak

## Student Information
- **Name:** Osaid Motawi
- **University ID:** 12341143

## Project Description
This IoT project uses an ESP32 microcontroller and a DHT22 sensor to measure temperature and relative humidity. The ESP32 connects to Wi-Fi and sends both measurements to ThingSpeak approximately every 20 seconds. The public ThingSpeak channel displays the readings in two time-series charts.

## Components and Tools
- ESP32 development board (simulated)
- DHT22 temperature and humidity sensor
- Wokwi simulator
- Arduino libraries: `DHT.h`, `WiFi.h`, and `ThingSpeak.h`
- ThingSpeak cloud platform

## Wiring
| DHT22 pin | ESP32 pin |
| --- | --- |
| VCC | 3V3 |
| DATA | GPIO 15 |
| NC | Not connected |
| GND | GND |

See `diagram.json` and the wiring screenshot for the simulation schematic.

## How It Works
1. The ESP32 connects to the `Wokwi-GUEST` Wi-Fi network.
2. The DHT22 sensor provides temperature in °C and humidity in %.
3. The ESP32 writes temperature to ThingSpeak Field 1 and humidity to Field 2.
4. The code checks the ThingSpeak response and prints the readings and university ID to the Serial Monitor.
5. New readings are sent approximately every 20 seconds.

## Links
- **Wokwi simulation:** https://wokwi.com/projects/478968277604189185
- **Public ThingSpeak channel:** https://thingspeak.com/channels/3551822
- **ThingSpeak Channel ID:** `3551822`

## Running the Simulation
1. Open the Wokwi project linked above.
2. Ensure the required libraries are installed.
3. To send data to your own ThingSpeak channel, set the channel ID and a valid **Write API Key** in your **private** copy of the sketch. Never commit the key to GitHub.
4. Run the simulation and open the Serial Monitor.
5. Check the public ThingSpeak channel for updated temperature and humidity graphs.

> **Security:** The public source code should contain a placeholder rather than a real Write API Key. If a key was previously exposed, regenerate it in ThingSpeak.

## Screenshots
### Wokwi Circuit
![Wokwi ESP32 and DHT22 wiring](https://github.com/Osaid-Motawi/ESP32-DHT22-ThingSpeak-LAB/blob/main/screenshots/image%201.png)

### Serial Monitor
![Serial Monitor readings and successful ThingSpeak upload](https://github.com/Osaid-Motawi/ESP32-DHT22-ThingSpeak-LAB/blob/main/screenshots/image%202.png)

### ThingSpeak Charts
![Public ThingSpeak temperature and humidity charts](https://github.com/Osaid-Motawi/ESP32-DHT22-ThingSpeak-LAB/blob/main/screenshots/image%203.png)

## Results
The simulation successfully connected to Wi-Fi and uploaded readings to ThingSpeak. During testing, the sensor values were changed from approximately 24 °C and 40% humidity to 31.3 °C and 60.5% humidity. The public channel showed multiple entries and both charts reflected the changes over time.
