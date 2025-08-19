#pragma once
#include <M5Stack.h>
#include "config.h"
#include "timer.h"

class Display {
public:
    void begin() {
        M5.begin();
        M5.Power.begin();
        M5.Lcd.fillScreen(BACKGROUND_COLOR);
        M5.Lcd.setTextColor(TEXT_COLOR);
        M5.Lcd.setTextSize(3);
    }

    void update(const TabataTimer& timer) {
        M5.Lcd.fillScreen(BACKGROUND_COLOR);
        
        switch (timer.getState()) {
            case TabataTimer::IDLE:
                drawIdleScreen();
                break;
            case TabataTimer::WORK:
                drawWorkScreen(timer);
                break;
            case TabataTimer::REST:
                drawRestScreen(timer);
                break;
            case TabataTimer::FINISHED:
                drawFinishedScreen();
                break;
        }
    }

private:
    void drawIdleScreen() {
        M5.Lcd.setCursor(50, 100);
        M5.Lcd.println("TABATA TIMER");
        M5.Lcd.setCursor(50, 150);
        M5.Lcd.println("Press A to start");
    }

    void drawWorkScreen(const TabataTimer& timer) {
        M5.Lcd.fillScreen(WORK_COLOR);
        M5.Lcd.setCursor(50, 50);
        M5.Lcd.printf("Round: %d/%d", timer.getRound(), TABATA_ROUNDS);
        M5.Lcd.setCursor(50, 100);
        M5.Lcd.println("WORK");
        M5.Lcd.setCursor(50, 150);
        M5.Lcd.printf("Time: %lu", (WORK_TIME_MS - timer.getElapsed()) / 1000);
    }

    void drawRestScreen(const TabataTimer& timer) {
        M5.Lcd.fillScreen(REST_COLOR);
        M5.Lcd.setCursor(50, 50);
        M5.Lcd.printf("Round: %d/%d", timer.getRound(), TABATA_ROUNDS);
        M5.Lcd.setCursor(50, 100);
        M5.Lcd.println("REST");
        M5.Lcd.setCursor(50, 150);
        M5.Lcd.printf("Time: %lu", (REST_TIME_MS - timer.getElapsed()) / 1000);
    }

    void drawFinishedScreen() {
        M5.Lcd.fillScreen(BACKGROUND_COLOR);
        M5.Lcd.setCursor(50, 100);
        M5.Lcd.println("FINISHED!");
        M5.Lcd.setCursor(50, 150);
        M5.Lcd.println("Press A to restart");
    }
};