/*
ESP8266 witty Board Blink Example Sanjeev Sharma 
 Control electric appliance i.e bulb or LED on the ESP8266 based Witty Board.
 This example code is in the public domain
 
 The LED/Bulb on the ESP8266 based Witty Board module is connected to GPIO5 i.e pin 5 On Witty Board.
 We can connect led or electrical appliance to following GPIO's free on Witty Board GPIO9,GPIO10,GPIO4,GPIO5
 In addition to that The RGB LED pins seem to be red = GPIO15, green = GPIO12, blue = GPIO13 pins which also can be used. 

 Please follow sketch below.

 https://blog.the-jedi.co.uk/2016/01/02/wifi-witty-esp12f-board/ 

 (which is also the TXD pin; so we cannot use Serial.print() at the same time)
 
 Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/

void setup() {
  pinMode(5, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(5, LOW);   // Turn the LED/Bulb on (Note that LOW is the voltage level, 5 is GPIO5 pin on Witty Board
                                    // but actually the LED is on; this is because 
                                    // it is acive low on the ESP-01)
  delay(1000);                      // Wait for a second
  digitalWrite(5, HIGH);  // Turn the LED/Bulb off by making the voltage HIGH
  delay(2000);                      // Wait for two seconds (to demonstrate the active low LED)
}
