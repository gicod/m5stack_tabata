#include <Arduino.h>
#include <M5Stack.h>
#include "config.h"
#include "display.h"
#include "buttons.h"
#include "timer.h"
#include "network.h"
#include "tests.h"

Display display;
Buttons buttons;
TabataTimer timer;
WiFiManager wifi;

void setup() {
    M5.begin(true, false, true);  // без SD для ускорения
    M5.Power.begin();

    Serial.begin(115200);
    
    display.begin();
    wifi.connect();
    timer.begin();

    // test_rawAxes2();
}

void loop() {
    buttons.update(timer);
    timer.update();

    if(timer.disp_isNeedUpdate())
    {
        // M5.Lcd.startWrite();
        display.update(timer);
        // M5.Lcd.endWrite();
    }
}