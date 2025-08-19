#include <Arduino.h>
#include <M5Stack.h>
#include "config.h"
#include "display.h"
#include "buttons.h"
#include "timer.h"
#include "network.h"

Display display;
Buttons buttons;
TabataTimer timer;
WiFiManager wifi;

void setup() {
    M5.begin();
    Serial.begin(115200);

    display.begin();
    wifi.connect();
    timer.begin();
}

void loop() {
    buttons.update(timer);
    timer.update();
    display.update(timer);
    // delay(50);
}