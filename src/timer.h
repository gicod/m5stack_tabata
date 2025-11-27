#pragma once
#include <Arduino.h>
#include "config.h"

class TabataTimer
{
public:
    void begin()
    {
        reset();
    }

    bool disp_isNeedUpdate()
    {
        if (dispNeedUpdate)
        {
            dispNeedUpdate = false;
            return true;
        }
        return false;
    }

    void secCheck()
    {
        if (millis() - millisLast >= 1000)
        {
            secCount--;
            millisLast = millis();
            dispNeedUpdate = true;
        }
    }

    void update()
    {
        if (!running)
            return;

        secCheck();
        if (tabataState == RELAX && secCount <= 0)
        {
            switchToWork();
            dispNeedUpdate = true;
        }
        else if (tabataState == WORK && secCount <= 0)
        {
            nextRound();
            dispNeedUpdate = true;
        }
    }

    void reset()
    {
        running = false;
        tabataState = START;
        roundsCompleted = 0;
        dispNeedUpdate = true;
    }

    void start()
    {
        if (tabataState == START)
        {
            reset();
            tabataState = RELAX;
        }
        running = true;
        millisLast = millis();
        secCount = getTrainingStageItems(tabataState).time_s;
        dispNeedUpdate = true;
    }

    void resume()
    {
        running = true;
        dispNeedUpdate = true;
    }

    void pause()
    {
        running = false;
    }

    void turnSound()
    {
        soundIsOn = !soundIsOn;
        playBuzzer();
    }

    uint8_t getRound() const { return roundsCompleted; }
    bool isRunning() const { return running; }
    int getSec() const { return secCount; }

private:
    bool soundIsOn = true;
    bool dispNeedUpdate = false;
    bool running = false;
    uint8_t roundsCompleted = 0;
    unsigned long millisLast = 0;
    int secCount = 0;

    void switchToWork()
    {
        tabataState = WORK;
        secCount = getTrainingStageItems(tabataState).time_s;
        playBuzzer();
    }

    void nextRound()
    {
        roundsCompleted++;
        if (roundsCompleted >= TABATA_ROUNDS)
        {
            tabataState = FINISHED;
            running = false;
        }
        else
        {
            tabataState = RELAX;
            secCount = getTrainingStageItems(tabataState).time_s;
        }
        playBuzzer();
    }

    void playBuzzer()
    {
        if(soundIsOn)
            M5.Speaker.tone(BUZZER_FREQ, BUZZER_DURATION);
    }
};