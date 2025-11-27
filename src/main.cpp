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

struct TrainingStage {
    String name;
    uint16_t color;
    int time_s;
};

TrainingStage workStage = {"WORK", WORK_COLOR, WORK_TIME_S};
TrainingStage relaxStage = {"RELAX", RELAX_COLOR, RELAX_TIME_S};

void setup() {
    M5.begin(true, false, true);  // без SD для ускорения
    M5.Power.begin();

    Serial.begin(115200);
    
    display.begin();
    wifi.connect();
    timer.begin();

    //debug
    // test_rawAxes2();
    // display.drawFinishedScreen();
}

void loop() {
    buttons.update(timer);
    timer.update();

    if(timer.disp_isNeedUpdate())
    {
        display.update(timer);
    }
}