/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "13m6-h0SPDXDK0H7jLFo6cEyMcXJXmR0"; // Coffee

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "NorthPoint Wireless";
char pass[] = "";
//char ssid[] = "HOME-4B57-2.4G";
//char pass[] = "delay5747buckled";

void setup()
{
  // Debug console
  Serial.begin(115200);delay(1000);
  Serial.print("\r\nMAC ADDRESS:");
  Serial.println(WiFi.macAddress());
  
  Blynk.begin(auth, ssid, pass);
}

void loop()
{ 
  Blynk.run();
  
  if (digitalRead(0) == 1) {
    Serial.println("GP0 was activated.");
    delay(1000);
    digitalWrite(0,0);
    delay(1000);
    Serial.println("GP0 was deactivated.");
  }
}
