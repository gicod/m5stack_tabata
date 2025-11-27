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
    int32_t totalTime = 0;
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
        float koef_width = float(timer.getSec()) / WORK_TIME_S;
        int32_t width = int32_t(320 * koef_width);
        if (width == 320)
        {
            M5.Lcd.fillRect(0, 20, 320, 220, BACKGROUND_COLOR);
            M5.Lcd.setTextColor(FUNNY_COLOR);
            M5.Lcd.setTextSize(2);
            M5.Lcd.setCursor(40,30);
            M5.Lcd.printf("Completed rounds:%d", timer.getRound());
            M5.Lcd.setCursor(40,50);
            M5.Lcd.printf("Total time:");
            M5.Lcd.setTextSize(5);
            M5.Lcd.setCursor(40, 90);
            M5.Lcd.printf("WORK: ");
            M5.Lcd.fillRect(0, 160, width, 80, WORK_COLOR);
        }
        M5.Lcd.setTextColor(FUNNY_COLOR);
        M5.Lcd.setTextSize(2);
        M5.Lcd.fillRect(200, 50, 60, 20, BACKGROUND_COLOR);
        M5.Lcd.setCursor(200, 50);
        M5.Lcd.printf("%d", totalTime++);
        M5.Lcd.setTextSize(5);
        M5.Lcd.setCursor(230, 90);
        M5.Lcd.fillRect(230, 90, 100, 60, BACKGROUND_COLOR);
        M5.Lcd.printf("%d", timer.getSec());
        M5.Lcd.fillRect(width, 160, 320 - width, 80, BACKGROUND_COLOR);
    }

    void drawRelaxScreen(const TabataTimer &timer)
    {
        float koef_width = float(timer.getSec()) / RELAX_TIME_S;
        int32_t width = int32_t(320 * koef_width);
        if (width == 320)
        {
            M5.Lcd.fillRect(0, 20, 320, 220, BACKGROUND_COLOR);
            M5.Lcd.setTextColor(FUNNY_COLOR);
            M5.Lcd.setTextSize(2);
            M5.Lcd.setCursor(40,30);
            M5.Lcd.printf("Completed rounds:%d", timer.getRound());
            M5.Lcd.setCursor(40,50);
            M5.Lcd.printf("Total time:");
            M5.Lcd.setTextSize(5);
            M5.Lcd.setCursor(40, 90);
            M5.Lcd.printf("RELAX: ");
            M5.Lcd.fillRect(0, 160, width, 80, RELAX_COLOR);
        }
        M5.Lcd.setTextColor(FUNNY_COLOR);
        M5.Lcd.setTextSize(2);
        M5.Lcd.fillRect(200, 50, 60, 20, BACKGROUND_COLOR);
        M5.Lcd.setCursor(200, 50);
        M5.Lcd.printf("%d", totalTime++);
        M5.Lcd.setTextSize(5);
        M5.Lcd.setCursor(230, 90);
        M5.Lcd.fillRect(230, 90, 100, 60, BACKGROUND_COLOR);
        M5.Lcd.printf("%d", timer.getSec());
        M5.Lcd.fillRect(width, 160, 320 - width, 80, BACKGROUND_COLOR);
    }

    void drawFinishedScreen()
    {
        M5.Lcd.fillRect(0, 20, 320, 220, BACKGROUND_COLOR);
        M5.Lcd.setTextColor(FUNNY_COLOR);
        M5.Lcd.setTextSize(5);
        M5.Lcd.setCursor(25, 100);
        M5.Lcd.println("FINISHED!");
        M5.Lcd.setTextColor(TEXT_COLOR);
        M5.Lcd.setTextSize(3);
        M5.Lcd.setCursor(120, 210);
        M5.Lcd.println("reset");
    }
};