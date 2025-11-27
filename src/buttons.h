#pragma once
#include <M5Stack.h>
#include "timer.h"

class Buttons
{
public:
    void update(TabataTimer &timer)
    {
        M5.update();

        if (M5.BtnA.wasPressed()) //pause
        {
            // Future functionality
        }

        if (M5.BtnB.wasPressed()) //start
        {
            if (timer.getState() == TabataTimer::START || timer.getState() == TabataTimer::FINISHED)
            {
                timer.start();
            }
            else
            {
                timer.pause();
            }
        }

        if (M5.BtnC.wasPressed()) //break
        {
            timer.reset();
        }
    }
};