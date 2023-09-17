#ifndef CHARACTER_H
#define CHARACTER_H
#include <stdio.h>
#include "raylib.h"
#include <cstdlib>
#include <iostream>
#include <deque>
#include <raymath.h>
#include "config.h"

class Character {
    public:
    int x = 0;
    int y = 0;
    int xTile = 0;
    int yTile = 1;
    int direction = 0;

    Image frontSpritesheet;
    Image front;
    Texture frontTexture;
    Image backSpritesheet;
    Image back;
    Texture backTexture;
    Image leftSpritesheet;
    Image left;
    Texture leftTexture;
    Image rightSpritesheet;
    Image right;
    Texture rightTexture;
    Texture currentTexture;
    Character();
    ~Character();
    void draw();
    void movement(int walkable[][48]);
    void update(int walkable[][48]);
};
#endif