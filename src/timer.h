#pragma once
#include <Arduino.h>
#include "config.h"

class TabataTimer
{
public:
    enum State
    {
        IDLE,
        WORK,
        RELAX,
        FINISHED
    };

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
        if (state == WORK && secCount <= 0)
        {
            switchToRelax();
            dispNeedUpdate = true;
        }
        else if (state == RELAX && secCount <= 0)
        {
            nextRound();
            dispNeedUpdate = true;
        }
    }

    void start()
    {
        if (roundsCompleted >= TABATA_ROUNDS)
            reset();
        running = true;
        state = WORK;
        millisLast = millis();
        secCount = WORK_TIME_S;
        dispNeedUpdate = true;
    }

    void pause()
    {
        running = !running;
        if (running)
            millisLast = millis() - pauseTime;
        dispNeedUpdate = true;
    }

    void reset()
    {
        running = false;
        state = IDLE;
        roundsCompleted = 0;
        dispNeedUpdate = true;
    }

    State getState() const { return state; }
    uint8_t getRound() const { return roundsCompleted + 1; }
    bool isRunning() const { return running; }
    int getSec() const { return secCount; }

private:
    void switchToRelax()
    {
        state = RELAX;
        secCount = RELAX_TIME_S;
        playBuzzer();
    }

    void nextRound()
    {
        roundsCompleted++;
        if (roundsCompleted >= TABATA_ROUNDS)
        {
            state = FINISHED;
            running = false;
        }
        else
        {
            state = WORK;
            secCount = WORK_TIME_S;
        }
        playBuzzer();
    }

    void playBuzzer()
    {
        // M5.Speaker.tone(BUZZER_FREQ, BUZZER_DURATION);
    }

    bool dispNeedUpdate = false;
    bool running = false;
    State state = IDLE;
    uint8_t roundsCompleted = 0;
    unsigned long millisLast = 0;
    unsigned long pauseTime = 0;
    int secCount = 0;
};