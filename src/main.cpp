/**
 * @file main.cpp
 * @author Ahmed MJADI (mjadiahmed@gmail.com)
 * @brief Connect your ESP32 to a specific access point (AP) if you have many AP with same name(SSID), Make sure that you used the right password
 * @version 0.1
 * @date 2022-10-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <Arduino.h>
#include "WiFi.h"

const char *ssid = "NEXT-AP1";
// const char *password = "Next2022";
const char *password = "2899100*-+";

const byte bssid[6] = {0x00, 0x19, 0xBE, 0x84, 0xA2, 0xED}; // (N21)0xC0, 0x74, 0xAD, 0x43, 0x08, 0x91 |||  0x00, 0x19, 0xBE, 0x84, 0xA2, 0xED

void setup()
{

  Serial.begin(9600);

  WiFi.begin(ssid, password, NAN, bssid, NAN);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected to the WiFi network");
}

void loop()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("Connecting to WiFi..");
    WiFi.reconnect();
  }

  Serial.print("Connected to WiFi: ");
  Serial.print(WiFi.SSID());
  Serial.print("   ||   AP_MAC: ");
  Serial.print(WiFi.BSSIDstr());
  Serial.print("  ||   RSSI: ");
  Serial.print(WiFi.RSSI());
  Serial.print("  ||   Channel: ");
  Serial.println(WiFi.channel());

  delay(1000);
}