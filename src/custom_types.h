#pragma once
#include <M5Stack.h>
#include "config.h"

enum TabataState
{
    START,
    RELAX,
    WORK,
    FINISHED
};
TabataState tabataState = START;

struct TrainingStage
{
    String name;
    uint16_t color;
    int time_s;
};

const TrainingStage workStage = {"WORK", WORK_COLOR, WORK_TIME_S};
const TrainingStage relaxStage = {"RELAX", RELAX_COLOR, RELAX_TIME_S};

TrainingStage getTrainingStageItems(TabataState state)
{
    if(state == RELAX)
        return relaxStage;
    else if (state == WORK) 
        return workStage;

    return workStage; //!
}