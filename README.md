# Smart-Coffee-ESP8266
## Purpose
The purpose of this project was to take my roommates old cheap coffee maker and make it into a smart coffee maker using an ESP8266 WiFi chip. That is, it can turn on with a voice command from a google home, Alexa, or even Cortana on Windows 10. Using this feature, I also made a routine on my own google home that triggers the coffee maker to start in the mornings automatically whenever my alarm goes off. This helps motivate me to get up and makes my morning routine just a little smoother.
## Parts of the process
1. Blynk App and IFTTT
2. ESP8266 Chip Software
3. ESP8266 Chip Hardware
4. Interface with Coffee Maker
5. Google Home Routine
### Blynk App and IFTTT
This project uses Blynk and IFTTT to link together the hardware with smart devices like Alexa or Google Home.

After downloading the Blynk app on a smartphone, make an account and create a new project. Select "ESP8266" as the device and "WiFi" as the connection type. Place a button on the screen and specify the output as "GP0" in "SWITCH" mode. Open the settings and copy down the AUTH TOKEN, this is unique to your applet and you will need it for when you make the code to upload to the ESP8266 and when you make the IFTTT applet.

Next, create an IFTTT applet with whatever you want as the trigger. My most commonly used trigger is "Say a simple phrase" with Google Home. The action should be a web request, you will need to figure out what the ip of blynk-cloud.com is by sending a ping, and you will need the AUTH TOKEN from earlier for the URL. Below is a list of variables that should be present in the IFTTT web request.
* URL          = "http://[insert ping results]/[insert AUTH TOKEN]/update/D0"
* Method       = "PUT"
* Content Type = "application/json"
* Body         = "["1"]"

### ESP8266 Chip Software
The IDE I used to code, compile, and upload to the chip was the Arduino IDE. This made installing the ESP8266 board and Blynk library easy using the IDE features. After including the libraries in the program the next step is to acquire 3 different values and define them in 3 different char arrays. These are the only unique values that would be required from someone setting this up separately. Everything else should work as is after downloading the code.

The first value is an array of characters that you will populate with the AUTH TOKEN for the Blynk applet that you created earlier. This will allow the Blynk servers to recognize the ESP8266 device and connect it to the applet that you created, and then allow IFTTT to update the pins with web requests. The second and third values you need to collect and add to the code are the login credentials for the WiFi network, the password field can be left as "" if there is no password on the network.

### ESP8266 Chip Hardware
[To Do] Included in the GitHub repository is a Multisim Schematic of the circuit that I soldered onto the PCB board

### Interface with the Coffee Maker
[To Do] The only thing you have to do to interface the Device with the coffee maker is to connect the two opposite terminals of the "On" button of the coffee maker to the two terminals of the transistor. The polarity of the connection is irrelevant because the transistor is Bipolar.

### Google Home Routine
[To Do] Either just say the words that you specified in step 1 with IFTTT to the google home or open up a routine, maybe the "Good Morning" routine, and add those words.
