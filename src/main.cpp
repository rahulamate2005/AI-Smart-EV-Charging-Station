#include <Arduino.h>
#include <Wifi.h>
#include "State.h"
#include "config.h"
#include "Peripherals.h"
#include "Network.h"
#include "telementry.h"
#include "model.h"
#include "edge_ai.h"
#include "optimization.h"
void setup()
{

    Serial.begin(115200);
    dht.begin(); 
    configTime(0,0,"pool.ntp.org","time.nist.gov"); // initialise sesnor
     pinMode(BTN_PLUGIN,INPUT_PULLUP);
      pinMode(BTN_PLUGOUT,INPUT_PULLUP);
      pinMode(LED_GREEN,OUTPUT);
      pinMode(LED_YELLOW,OUTPUT);
      pinMode(LED_RED,OUTPUT);
      connectWiFi();
      // Configure MQTT server
    mqtt.setServer(MQTT_SERVER, MQTT_PORT);
 connectMQTT();

}

unsigned long now;
unsigned long last_print;
static bool lastMqttState=false;

void loop()
{ mqtt.loop();
    //print vals every 1 sec
    now = millis();
    if((now - last_print) > 1000)
    {
        last_print = now;
      sample_sensor();
        runEdgeAIInference();
        if(manualOverrideActive==0){
        runOptimization();}
      publishTelemetry();

        
    
    }

   plug_status(); 
   updateLeds();
   applyRelayDutyCycle();
}