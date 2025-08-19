#pragma once
#include <M5Stack.h>
#include "timer.h"

class Buttons {
public:
    void update(TabataTimer& timer) {
        M5.update();
        
        if (M5.BtnA.wasPressed()) {
            if (timer.getState() == TabataTimer::IDLE || timer.getState() == TabataTimer::FINISHED) {
                timer.start();
            } else {
                timer.pause();
            }
        }
        
        if (M5.BtnB.wasPressed()) {
            // Future functionality
        }
        
        if (M5.BtnC.wasPressed()) {
            timer.reset();
        }
    }
};