#pragma once
#include <M5Stack.h>
#include "timer.h"

class Buttons
{
public:
    void update(TabataTimer &timer)
    {
        M5.update();

        if (M5.BtnA.wasPressed()) // pause
        {
            if (tabataState == WORK || tabataState == RELAX)
                timer.pause();
            if (tabataState == FINISHED)
                timer.begin();
        }

        if (M5.BtnB.wasPressed()) // start
        {
            if (tabataState == START || tabataState == FINISHED)
                timer.start();
            if (tabataState == RELAX || tabataState == RELAX)
                timer.resume();
            if (tabataState == FINISHED)
                timer.begin();
        }

        if (M5.BtnC.wasPressed()) // break
            timer.begin();
    }
};