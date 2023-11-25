#if defined(CONFIG_IDF_TARGET_ESP32)

  #define NEOPIXEL_RGB_PIN       26
  #define NEOPIXEL_RGBW_PIN      32
  #define DOTSTAR_DATA_PIN       33
  #define DOTSTAR_CLOCK_PIN      27
  #define DEVICE_SUFFIX          ""
#endif
 
#include "HomeSpan.h"
#include "extras/Pixel.h"   
#include <HomeSpan.h>


#include "LED.h"
#include "DEV_RELAY.h"
#include "NeoPixel_RGB.h"



void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

homeSpan.setPairingCode("03145154");
homeSpan.setQRID("031-45-154");

  homeSpan.begin(Category::Bridges, "AP Bridge");

     // Accessory 1: LED
  new SpanAccessory();
   new Service::AccessoryInformation();
     new Characteristic::Identify();
     new Characteristic::Name("LED");  
    new LED(15);

      // Accessory 2: Relay Switch
  new SpanAccessory();
    new Service::AccessoryInformation();    
      new Characteristic::Identify();     
      new Characteristic::Name("Switch");                    
    new DEV_RELAY(18);  // instantiates a new relay

  new SpanAccessory();                                                         
    new Service::AccessoryInformation();                                         
      new Characteristic::Identify();                                              
    // __VA_OPT__(new Characteristic::Name(__VA_ARGS__));
    new Characteristic::Name("NeopixelLED");  
    new NeoPixel_RGB(NEOPIXEL_RGB_PIN,8);                       // create 8-LED NeoPixel RGB Strand with full color control

}

void loop() {
  // put your main code here, to run repeatedly:
homeSpan.poll();
}
