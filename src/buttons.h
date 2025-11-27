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
            if (tabataState == RELAX || tabataState == WORK)
                timer.pause();
            if (tabataState == FINISHED)
                timer.begin();
        }

        if (M5.BtnB.wasPressed()) // start
        {
            if (tabataState == START || tabataState == FINISHED)
                timer.start();
            if (tabataState == RELAX || tabataState == WORK)
                if(!timer.isRunning())
                    timer.resume();
            if (tabataState == FINISHED)
                timer.begin();
        }

        if (M5.BtnC.wasPressed()) // break
            timer.begin();
    }
};