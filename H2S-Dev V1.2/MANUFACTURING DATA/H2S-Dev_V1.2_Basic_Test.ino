// Helium IoT Network Sensor Development board
// H2S-Dev V1.2 Basic
// Basic automated test software written in Arduino Environment

// This software and the corresponding hardware are open source under MIT License

// Copyright (C) HobbyIoT

#define LED_BUILTIN 4
#define LED_1PPS 25

#include <SPI.h>
#include <LoRa.h>

void setup() {

  Serial.begin(115200);
  while(!Serial);

  LoRa.setPins(5, 15, 32); // set CS, reset, IRQ pin

  pinMode(4, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(35, INPUT); // Battery sense input
  pinMode(39, INPUT); // USB-C/5V sense input

  Serial.begin(115200);
}

void loop() {

  float vcc5 = 0, vbat = 0;
// By default the test result is 0 = 'failed'
  char result = 0;

  Serial.println();
  Serial.println("**=============================================================**");
  Serial.println("**         Helium IoT Network Sensor Development board         **");
  Serial.println("*                     H2S-Dev V1.2 Basic                       **");
  Serial.println("*             A simple automated test software                  *");
  Serial.println("*        https://github.com/hobbyiot/HELIUM-SENSORS/            *");
  Serial.println("*                https://www.hobbyiot.net/                      *");
  Serial.println("**=============================================================**");    

  Serial.println();

// Welcome blink

  for(char i=0;i<3;i++) {
    digitalWrite(LED_BUILTIN,HIGH); digitalWrite(LED_1PPS,HIGH); delay(100);
    digitalWrite(LED_BUILTIN,LOW); digitalWrite(LED_1PPS,LOW); delay(300);
  }
  
delay(1000);

  Serial.println(F("Testing board modules..."));
  Serial.println();

  vcc5 = analogRead(39)/819;
  Serial.print("Input voltage:   ");
  Serial.print(vcc5);
  Serial.print(" V ... ");
  
  if (vcc5 > 4.5) {
    result++;
    Serial.println("PASS");
    digitalWrite(LED_BUILTIN,HIGH); delay(100); digitalWrite(LED_BUILTIN,LOW);
  } else {
    Serial.println("FAIL");
    // digitalWrite(LED_BUILTIN,HIGH); delay(300); digitalWrite(LED_1PPS,LOW);
  }
  delay(1000);

  vbat = analogRead(35)/589;
    Serial.print("Charger voltage: ");
    Serial.print(vbat);
    Serial.print(" V ... ");
  if (vbat < 2.2) {
    result++;
    Serial.println("PASS");
    delay(500);
    Serial.print("Connect battery: ");
    do {
      digitalWrite(LED_BUILTIN,HIGH); delay(100); digitalWrite(LED_BUILTIN,LOW); delay(300);
      digitalWrite(LED_BUILTIN,HIGH); delay(100); digitalWrite(LED_BUILTIN,LOW);
      delay(1000);
      vbat = analogRead(35)/589;
    } while (vbat < 3.5);

    Serial.print(vbat);
    Serial.print(" V ... ");
    
    result++;
    Serial.println("PASS");
    digitalWrite(LED_BUILTIN,HIGH); delay(100); digitalWrite(LED_BUILTIN,LOW); delay(300);
    digitalWrite(LED_BUILTIN,HIGH); delay(100); digitalWrite(LED_BUILTIN,LOW);
  } else {
    Serial.println("FAIL");
    // digitalWrite(LED_BUILTIN,HIGH); delay(300); digitalWrite(LED_1PPS,LOW);
  }
  delay(1000);

    if (!LoRa.begin(868E6)) {         // initialize ratio at 868 MHz
    Serial.println("LoRa init failed. Check your connections.");
    }
    else
    {
      result++;
      Serial.println("Checking LoRa module    ... PASS");
      digitalWrite(LED_BUILTIN,HIGH); delay(100); digitalWrite(LED_BUILTIN,LOW); delay(300);
      digitalWrite(LED_BUILTIN,HIGH); delay(100); digitalWrite(LED_BUILTIN,LOW); delay(300);
      digitalWrite(LED_BUILTIN,HIGH); delay(100); digitalWrite(LED_BUILTIN,LOW);
    }

//    LoRa.dumpRegisters(Serial);

  if(result == 4) {
    Serial.println("--------------------------------");
    Serial.println("Total result            ... PASS");
    Serial.println();
    Serial.println("Test finished. Press RESET to start over... ");
    Serial.println("... or have fun with your new board!");
    
delay(1000);

    while(1)
    //Flash LED for test PASS
      for(char i=0;i<3;i++) {
      digitalWrite(LED_BUILTIN,HIGH); delay(50); digitalWrite(LED_BUILTIN,LOW); delay(1000);
      }
  } else {
    Serial.println("--------------------------------");
    Serial.println("Total result:           ... FAIL");
    Serial.println();
    Serial.println("Test finished. Press RESET to start over... ");
    while(1)
    //Blink LED for test FAIL
      for(char i=255;i>0;i--) {
      analogWrite(LED_BUILTIN,i);
      delay(8);
    }
    delay(500);
  }
}
