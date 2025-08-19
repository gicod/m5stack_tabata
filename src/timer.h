#pragma once
#include <Arduino.h>
#include "config.h"

class TabataTimer {
public:
    enum State { IDLE, WORK, REST, FINISHED };

    void begin() {
        reset();
    }

    void update() {
        if (!running) return;

        unsigned long currentMillis = millis();
        if (state == WORK && currentMillis - lastTime >= WORK_TIME_MS) {
            switchToRest();
        } else if (state == REST && currentMillis - lastTime >= REST_TIME_MS) {
            nextRound();
        }
    }

    void start() {
        if (roundsCompleted >= TABATA_ROUNDS) reset();
        running = true;
        state = WORK;
        lastTime = millis();
    }

    void pause() {
        running = !running;
        if (running) lastTime = millis() - pauseTime;
    }

    void reset() {
        running = false;
        state = IDLE;
        roundsCompleted = 0;
    }

    State getState() const { return state; }
    uint8_t getRound() const { return roundsCompleted + 1; }
    bool isRunning() const { return running; }
    unsigned long getElapsed() const { return millis() - lastTime; }

private:
    void switchToRest() {
        state = REST;
        lastTime = millis();
        playBuzzer();
    }

    void nextRound() {
        roundsCompleted++;
        if (roundsCompleted >= TABATA_ROUNDS) {
            state = FINISHED;
            running = false;
        } else {
            state = WORK;
            lastTime = millis();
        }
        playBuzzer();
    }

    void playBuzzer() {
        // M5.Speaker.tone(BUZZER_FREQ, BUZZER_DURATION);
    }

    bool running = false;
    State state = IDLE;
    uint8_t roundsCompleted = 0;
    unsigned long lastTime = 0;
    unsigned long pauseTime = 0;
};