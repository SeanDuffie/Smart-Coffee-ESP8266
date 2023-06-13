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
  This runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "13m6-h0SPDXDK0H7jLFo6cEyMcXJXmR0"; // Coffee Auth Token from Blynk App

// Your WiFi credentials. Set password to "" for open networks.
char ssid[] = "Turkish Delights";
char pass[] = "Wemissgary!123";

int trigger; // Delay active or not
int m; // number of minutes to delay
int s; // number of seconds remaining

BlynkTimer timer; // Announcing the timer

BLYNK_WRITE(V0) // Checks the value for the delay in the Blynk App
{
  m = (param.asInt()); // Coffee takes 6 minutes to Brew, so it is manually adjusted
}

BLYNK_WRITE(V1) // Checks to see if the delay is started in the Blynk App
{
  trigger = (param.asInt());
}

void setup() // Only runs once at the beginning
{
  Serial.begin(115200);delay(1000);// Debug console
  Serial.print("\r\nMAC ADDRESS:");
  Serial.println(WiFi.macAddress()); // Acquire MAC Address for first setup and WiFi whitelisting
  
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000, pinCheck); // timer will run every second
}

void loop() // Continuous loop
{ 
  Blynk.run();
  timer.run();
}

void pinCheck() // Checks for signals from Blynk, and updates the output pins accordingly
{
  s = -1;
  //Serial.print("Total minutes = "); Serial.println(m); Serial.println();
  
  if (trigger == 1)
  {
    trigger = 0;
    Blynk.virtualWrite(V1, trigger);
    Blynk.virtualWrite(m, V0);
    s = m * 60;
    Serial.print("App Triggered. Delay is "); Serial.print(m * 60); Serial.println(" seconds");
  }
  
  while (s > -1)
  {
    Blynk.run();
    //Serial.print("    Seconds left = "); Serial.print(s); Serial.print("; V1 = "); Serial.print(trigger); Serial.print("; V0 = "); Serial.println(m);
    
    if (s > 0)
    {
      delay(1000);
      s -= 1;
    }
    
    else if (s == 0)
    {
        digitalWrite(0,1);
        Serial.println("Coffee Maker started");
        delay(1000);
        digitalWrite(0,0);
        s -= 1;
    }
  }
}
