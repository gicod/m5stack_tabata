#include <Arduino.h>
#include <M5Stack.h>
#include "config.h"
#include "custom_types.h"
#include "display.h"
#include "buttons.h"
#include "timer.h"
#include "network.h"
#include "tests.h"

Display display;
Buttons buttons;
TabataTimer timer;
WiFiManager wifi;

void setup()
{
    M5.begin(true, false, true); //? без SD для ускорения
    M5.Power.begin();

    Serial.begin(115200);

    display.begin();
    wifi.connect();
    timer.begin();

    // debug
    //  test_rawAxes2();
    //  display.drawFinishedScreen();
}

void loop()
{
    buttons.update(timer);
    timer.update();

    if (timer.disp_isNeedUpdate())
    {
        display.update(timer);
    }
}