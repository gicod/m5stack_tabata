#pragma once
#include <M5Stack.h>
#include "config.h"
#include "timer.h"

class Display
{
public:
    void begin()
    {
        M5.Lcd.fillScreen(BACKGROUND_COLOR);
        M5.Lcd.setSwapBytes(true); // быстрее заливка
        M5.Lcd.setBrightness(180); // фиксируем яркость, убираем авто-мерцание
    }

    void update(const TabataTimer &timer)
    {
        switch (timer.getState())
        {
        case TabataTimer::START:
            drawStartScreen();
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
    void drawStartScreen()
    {
        M5.Lcd.setTextSize(2);
        M5.Lcd.setTextColor(TEXT_COLOR);
        M5.Lcd.setCursor(10, 4);
        M5.Lcd.printf("Round:%d", TABATA_ROUNDS);
        M5.Lcd.setTextColor(WORK_COLOR);
        M5.Lcd.setCursor(120, 4);
        M5.Lcd.printf("Work:%d", WORK_TIME_S);
        M5.Lcd.setTextColor(RELAX_COLOR);
        M5.Lcd.setCursor(215, 4);
        M5.Lcd.printf("Relax:%d", RELAX_TIME_S); // по оси Y до 20 пикселя занято

        M5.Lcd.setTextColor(FUNNY_COLOR);
        M5.Lcd.setTextSize(5);
        M5.Lcd.setCursor(30, 65);
        M5.Lcd.println("TABATA");
        M5.Lcd.setCursor(140, 120);
        M5.Lcd.println("TIMER");

        M5.Lcd.setTextColor(TEXT_COLOR);
        M5.Lcd.setTextSize(1);
        M5.Lcd.setCursor(5, 310);
        M5.Lcd.setRotation(0); // поворот текста
        M5.Lcd.println(__TIME__);
        M5.Lcd.setRotation(1); // исходное положение

        // M5.Lcd.setTextColor(TEXT_COLOR);
        // M5.Lcd.setTextSize(2);
        // M5.Lcd.setCursor(60, 220);
        // M5.Lcd.println("5+");

        M5.Lcd.setTextColor(TEXT_COLOR);
        M5.Lcd.setTextSize(3);
        M5.Lcd.setCursor(120, 210);
        M5.Lcd.println("start");
        // M5.Lcd.setCursor(125, 220);
        // M5.Lcd.println("select");

        // M5.Lcd.setTextColor(TEXT_COLOR);
        // M5.Lcd.setTextSize(2);
        // M5.Lcd.setCursor(243, 220);
        // M5.Lcd.println("5-");
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