/*******************************************************************************
 *
 * Permission is hereby granted, free of charge, to anyone
 * obtaining a copy of this document and accompanying files,
 * to do whatever they want with them without any restriction,
 * including, but not limited to, copying, modification and redistribution.

 * NO WARRANTY OF ANY KIND IS PROVIDED.
 *
 * This example sends a valid LoRaWAN packet over The Helium network
 * with a payload containing temperature and humidity data
 * as they are read from a DHT11 sensor, connected to GPIO13
 * using frequency and encryption settings according your region.
 *
 * The data format and the JSON script for decoding it
 * are described in separate article in the project's GitHub
 * (https://github.com/hobbyiot/HELIUM-SENSORS)
 *
 * This uses OTAA (Over-the-air activation), where where a DevEUI and
 * application key is configured, which are used in an over-the-air
 * activation procedure where a DevAddr and session keys are
 * assigned/generated for use with all further communication.
 *
 * To use this sketch, first register your application and device with
 * The Helium network console (https://console.helium.com/welcome)
 * to set or generate an AppEUI, DevEUI and AppKey.
 * Multiple devices can use the same AppEUI, but each device has its own
 * DevEUI and AppKey.
 *
 * ****** Do not forget to define the radio type correctly in config.h !!! ******
 *
 * Copyright (c) 2025 HobbyIoT (S. Ivanov)
 * Copyright (c) 2015 Thomas Telkamp and Matthijs Kooijman
 *
 *******************************************************************************/


#include "H2S-CFG-YOUR_DEVBOARD.h"

#include <lmic.h>
#include <hal/hal.h>
#include <SPI.h>
#include "DHT.h"

#define DHTPIN 13
#define DHTTYPE DHT11

#define THDATA '9'

#define DTYPE THDATA

DHT dht(DHTPIN, DHTTYPE);

// DEVEUI MUST BE LSB!!!
static const u1_t PROGMEM DEVEUI[8]={ H2S_DEVEUI };
void os_getDevEui (u1_t* buf) { memcpy_P(buf, DEVEUI, 8);}

// APPEUI MUST BE LSB!!!
static const u1_t PROGMEM APPEUI[8]={ H2S_APPEUI };
void os_getArtEui (u1_t* buf) { memcpy_P(buf, APPEUI, 8);}

// APPKEY MUST BE *MSB*!!!
static const u1_t PROGMEM APPKEY[16] = { H2S_APPKEY };
void os_getDevKey (u1_t* buf) {  memcpy_P(buf, APPKEY, 16);}

static uint8_t mydata_t[7], mydata_h[7], packet[16];
char mydatat[7],mydatah[7];

float t, h;

u1_t ptr;

static osjob_t sendjob;

// Schedule TX every this many seconds (might become longer due to duty
// cycle limitations).
const unsigned TX_INTERVAL = 300;

// Pin mapping
const lmic_pinmap lmic_pins = {
    .nss = 5,
    .rxtx = LMIC_UNUSED_PIN,
    .rst = 15,
    .dio = {32, 33, 34}, // 25, 26, 27
};

void onEvent (ev_t ev) {
    Serial.print(os_getTime());
    Serial.print(": ");
    switch(ev) {
        case EV_SCAN_TIMEOUT:
            Serial.println(F("EV_SCAN_TIMEOUT"));
            break;
        case EV_BEACON_FOUND:
            Serial.println(F("EV_BEACON_FOUND"));
            break;
        case EV_BEACON_MISSED:
            Serial.println(F("EV_BEACON_MISSED"));
            break;
        case EV_BEACON_TRACKED:
            Serial.println(F("EV_BEACON_TRACKED"));
            break;
        case EV_JOINING:
            Serial.println(F("EV_JOINING"));
            break;
        case EV_JOINED:
            Serial.println(F("EV_JOINED"));

            // Disable link check validation (automatically enabled
            // during join, but not supported by TTN at this time).
            LMIC_setLinkCheckMode(0);
            break;
        case EV_RFU1:
            Serial.println(F("EV_RFU1"));
            break;
        case EV_JOIN_FAILED:
            Serial.println(F("EV_JOIN_FAILED"));
            break;
        case EV_REJOIN_FAILED:
            Serial.println(F("EV_REJOIN_FAILED"));
            break;
            break;
        case EV_TXCOMPLETE:
            Serial.println(F("EV_TXCOMPLETE (includes waiting for RX windows)"));
            if (LMIC.txrxFlags & TXRX_ACK)
              Serial.println(F("Received ack"));
            if (LMIC.dataLen) {
              Serial.println(F("Received "));
              Serial.println(LMIC.dataLen);
              Serial.println(F(" bytes of payload"));
            }
            // Schedule next transmission
            os_setTimedCallback(&sendjob, os_getTime()+sec2osticks(TX_INTERVAL), do_send);
            break;
        case EV_LOST_TSYNC:
            Serial.println(F("EV_LOST_TSYNC"));
            break;
        case EV_RESET:
            Serial.println(F("EV_RESET"));
            break;
        case EV_RXCOMPLETE:
            // data received in ping slot
            Serial.println(F("EV_RXCOMPLETE"));
            break;
        case EV_LINK_DEAD:
            Serial.println(F("EV_LINK_DEAD"));
            break;
        case EV_LINK_ALIVE:
            Serial.println(F("EV_LINK_ALIVE"));
            break;
         default:
            Serial.println(F("Unknown event"));
            break;
    }
}

void do_send(osjob_t* j){
    // Check if there is not a current TX/RX job running
    if (LMIC.opmode & OP_TXRXPEND) {
        Serial.println(F("OP_TXRXPEND, not sending"));
    } else {
        // Prepare upstream data transmission at the next possible time.
        t = dht.readTemperature();
//        delay(1000);
        h = dht.readHumidity();
//        delay(1000);
        dtostrf(t,0,2,mydatat);
        dtostrf(h,0,2,mydatah);
        Serial.println();
        Serial.print("Temperature: ");
        Serial.println(t);
        Serial.print("Humidity: ");
        Serial.println(h);
        Serial.println();

        for(int i=0;i<7;i++) {
          mydata_t[i]=mydatat[i];
          mydata_h[i]=mydatah[i];
        }

        ptr = 0;

        packet[ptr++] = '1'; // channel 1
        packet[ptr++] = DTYPE;

        for(;ptr<9;ptr++) {
          packet[ptr] = mydata_t[ptr-2];
        }
        for(;ptr<16;ptr++) {
          packet[ptr] = mydata_h[ptr-9];
        }
        packet[ptr] = 0x00; // End of packet
        Serial.println("*** Packet prepared! ***");
        LMIC_setTxData2(1, packet, sizeof(packet), 0);
        Serial.println(F("Packet queued"));
    }
    // Next TX is scheduled after TX_COMPLETE event.
}

void setup() {

    Serial.begin(115200);
    while(!Serial);

    Serial.println();
    Serial.println("**          THE HELIUM Network BEAR Node (c) HobbyIoT          **");
    Serial.println("*        With ESP32 Module + LoRa module based on SX1276        *");
    Serial.println("Example code by IBM LMIC framework TTN-OTAA set up for EU 868 MHz");
    Serial.println("                    *** H2S-DEV-THS-V0.5 ***                     ");
    Serial.println("**=============================================================**");    
    Serial.println();
    
    Serial.println(F("Starting"));
    
    dht.begin();

    #ifdef VCC_ENABLE
    // For Pinoccio Scout boards
    pinMode(VCC_ENABLE, OUTPUT);
    digitalWrite(VCC_ENABLE, HIGH);
    delay(1000);
    #endif

    // LMIC init
    os_init();
    // Reset the MAC state. Session and pending data transfers will be discarded.
    LMIC_reset();
    
    // allow much more clock error than the X/1000 default. See:
    // https://github.com/mcci-catena/arduino-lorawan/issues/74#issuecomment-462171974
    // https://github.com/mcci-catena/arduino-lmic/commit/42da75b56#diff-16d75524a9920f5d043fe731a27cf85aL633
    // the X/1000 means an error rate of 0.1%; the above issue discusses using
    // values up to 10%. so, values from 10 (10% error, the most lax) to 1000
    // (0.1% error, the most strict) can be used.
    LMIC_setClockError(1 * MAX_CLOCK_ERROR / 40);
    

    // Sub-band 2 - Helium Network
//     LMIC_selectSubBand(1); // zero indexed - for US band (915 MHz)
    LMIC_setupBand(1, 14, 100); //1,14,100

    // bit_t LMIC_setupBand (u1_t bandidx, s1_t txpow, u2_t txcap);
    // bandidx = 1, txpow = 14, txcap = 100 = 1%
    
    LMIC_setLinkCheckMode(0);
    LMIC_setDrTxpow(DR_SF7, 14); //14

    // Start job (sending automatically starts OTAA too)
    do_send(&sendjob);
}

void loop() {
    os_runloop_once();
}
