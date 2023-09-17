#ifndef INVENTORY_H
#define INVENTORY_H
#include <stdio.h>
#include "raylib.h"
#include <cstdlib>
#include <iostream>
#include <deque>
#include <raymath.h>
#include "config.h"
class Inventory {
    public:
    int inventory[9] = {};
    int woodCount = 0;
    void draw();
};
#endif