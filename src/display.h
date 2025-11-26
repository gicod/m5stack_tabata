#pragma once
#include <M5Stack.h>
#include "config.h"
#include "timer.h"

class Display
{
public:
    void begin()
    {
        M5.begin();
        M5.Power.begin();
        M5.Lcd.fillScreen(BACKGROUND_COLOR);
        M5.Lcd.setTextColor(TEXT_COLOR);
        M5.Lcd.setTextSize(3);
    }

    void update(const TabataTimer &timer)
    {
        M5.Lcd.fillScreen(BACKGROUND_COLOR);

        switch (timer.getState())
        {
        case TabataTimer::IDLE:
            drawIdleScreen();
            break;
        case TabataTimer::WORK:
            drawWorkScreen(timer);
            break;
        case TabataTimer::RELAX:
            drawRelaxScreen(timer);
            break;
        case TabataTimer::FINISHED:
            drawFinishedScreen();
            break;
        }
    }

private:
    void drawIdleScreen()
    {
        M5.Lcd.setCursor(10, 10);
        M5.Lcd.println(__TIME__);
        M5.Lcd.setCursor(10, 100);
        M5.Lcd.println("TABATA TIMER");
        M5.Lcd.setCursor(10, 150);
        M5.Lcd.println("Press B to start");
    }

    void drawWorkScreen(const TabataTimer &timer)
    {
        M5.Lcd.fillScreen(WORK_COLOR);
        M5.Lcd.setCursor(50, 50);
        M5.Lcd.printf("Round: %d/%d", timer.getRound(), TABATA_ROUNDS);
        M5.Lcd.setCursor(50, 100);
        M5.Lcd.println("WORK");
        M5.Lcd.setCursor(50, 150);
        M5.Lcd.printf("Time: %d", timer.getSec());
    }

    void drawRelaxScreen(const TabataTimer &timer)
    {
        M5.Lcd.fillScreen(RELAX_COLOR);
        M5.Lcd.setCursor(50, 50);
        M5.Lcd.printf("Round: %d/%d", timer.getRound(), TABATA_ROUNDS);
        M5.Lcd.setCursor(50, 100);
        M5.Lcd.println("RELAX");
        M5.Lcd.setCursor(50, 150);
        M5.Lcd.printf("Time: %d", timer.getSec());
    }

    void drawFinishedScreen()
    {
        M5.Lcd.fillScreen(BACKGROUND_COLOR);
        M5.Lcd.setCursor(10, 100);
        M5.Lcd.println("FINISHED!");
        M5.Lcd.setCursor(10, 150);
        M5.Lcd.println("Press B to relaxart");
    }
};