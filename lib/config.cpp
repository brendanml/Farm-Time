#include "config.h"
#include "raylib.h"

int cellSize = 16;
int cellVertical = 48;
int cellHorizontal = 48;
double currentTime = 0;
double lastUpdateTime = 0;

bool TimePassed(double interval) {
    double currentTime = GetTime();
    if(currentTime-lastUpdateTime>=interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}