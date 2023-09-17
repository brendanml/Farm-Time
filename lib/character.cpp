#include "character.h"
using namespace std;
Character::Character() {
    frontSpritesheet = LoadImage("../resources/characters/bren/walk/front/spritesheet.png");
    backSpritesheet = LoadImage("../resources/characters/bren/walk/back/spritesheet.png");
    leftSpritesheet = LoadImage("../resources/characters/bren/walk/left/spritesheet.png");
    rightSpritesheet = LoadImage("../resources/characters/bren/walk/right/spritesheet.png");
    front = ImageFromImage(frontSpritesheet, Rectangle{8,0,16,32});
    back = ImageFromImage(backSpritesheet, Rectangle{8,0,16,32});
    left = ImageFromImage(leftSpritesheet, Rectangle{8,0,16,32});
    right = ImageFromImage(rightSpritesheet, Rectangle{8,0,16,32});
    UnloadImage(frontSpritesheet);
    UnloadImage(backSpritesheet);
    UnloadImage(leftSpritesheet);
    UnloadImage(rightSpritesheet);
    frontTexture = LoadTextureFromImage(front);
    backTexture = LoadTextureFromImage(back);
    leftTexture = LoadTextureFromImage(left);
    rightTexture = LoadTextureFromImage(right);
    UnloadImage(front);
    UnloadImage(back);
    UnloadImage(left);
    UnloadImage(right);
    currentTexture = frontTexture;
}
Character::~Character() {
    UnloadTexture(frontTexture);
    UnloadTexture(backTexture);
}
void Character::draw() {
    DrawTexture(currentTexture, x, y, WHITE);
}
void Character::movement(int walkable[][48]) {
    if(IsKeyDown(KEY_DOWN) && TimePassed(.2)) {
        if(walkable[yTile+1][xTile]==0) {
            y+=16;
            yTile+=1;
        }
        currentTexture = frontTexture;
        direction = 0;
    }
    else if(IsKeyDown(KEY_UP) && TimePassed(.2)) {
        if(walkable[yTile-1][xTile]==0) {
            y-=16;
            yTile -=1;
        }
        currentTexture = backTexture;
        direction = 2;
    }
    else if(IsKeyDown(KEY_LEFT) && TimePassed(.2)) {
        if(walkable[yTile][xTile-1]==0) {
            x-=16;
            xTile -= 1;
        }
        currentTexture = leftTexture;
        direction = 1;
    }
    else if(IsKeyDown(KEY_RIGHT) && TimePassed(.2)) {
        if(walkable[yTile][xTile+1]==0) {                
            x+=16;
            xTile += 1;
        }
        currentTexture = rightTexture;
        direction = 3;
    }        
}
void Character::update(int walkable[][48]) {
    movement(walkable);
}
