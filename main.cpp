#include <stdio.h>
#include "raylib.h"
#include <cstdlib>
#include <iostream>
#include <deque>
#include <raymath.h>
using namespace std;    

int cellSize = 32;
int cellCount = 24;

class Grass {
    public:
    Image grass1;
    Image grass2;
    Image grass3;
    Image tree1;
    Texture grassTextureOne;
    Texture grassTextureTwo;
    Texture grassTextureThree;
    Texture tree1Text;

    int grassMap[24][24] = {
        {0, 2, 1, 1, 0, 2, 1, 2, 2, 0, 1, 0, 0, 1, 1, 2, 0, 2, 1, 0, 0, 1, 0, 2},
        {1, 1, 0, 0, 1, 1, 0, 2, 0, 1, 0, 1, 2, 0, 2, 1, 2, 2, 0, 1, 0, 0, 1, 2},
        {0, 2, 2, 0, 2, 1, 2, 1, 2, 0, 2, 0, 2, 1, 2, 0, 1, 2, 1, 0, 2, 0, 2, 0},
        {2, 1, 1, 0, 2, 0, 1, 2, 0, 0, 1, 2, 2, 1, 2, 0, 2, 2, 1, 0, 2, 0, 1, 1},
        {1, 1, 2, 2, 0, 0, 0, 0, 2, 1, 2, 1, 0, 2, 1, 2, 0, 1, 2, 0, 2, 0, 2, 2},
        {2, 0, 1, 1, 2, 2, 1, 1, 0, 0, 1, 1, 2, 1, 0, 2, 0, 2, 1, 1, 2, 0, 0, 2},
        {1, 1, 2, 0, 2, 2, 1, 2, 0, 0, 1, 1, 2, 2, 2, 0, 1, 1, 0, 2, 2, 0, 0, 2},
        {2, 0, 2, 1, 2, 1, 2, 2, 1, 0, 1, 1, 0, 0, 2, 0, 2, 1, 2, 1, 0, 0, 1, 1},
        {1, 1, 0, 0, 0, 0, 2, 1, 1, 2, 1, 0, 0, 0, 1, 2, 1, 2, 0, 2, 0, 1, 1, 0},
        {0, 0, 1, 1, 0, 2, 2, 2, 2, 1, 2, 1, 1, 0, 1, 0, 1, 1, 1, 2, 0, 0, 2, 1},
        {2, 0, 0, 2, 1, 1, 2, 2, 1, 0, 2, 0, 0, 0, 0, 1, 2, 1, 2, 0, 0, 1, 0, 0},
        {0, 2, 0, 2, 1, 1, 1, 1, 2, 1, 1, 0, 2, 2, 1, 2, 0, 2, 2, 1, 1, 0, 0, 1},
        {1, 0, 2, 1, 0, 2, 1, 0, 0, 2, 0, 1, 1, 0, 1, 2, 1, 2, 0, 1, 0, 2, 2, 2},
        {1, 1, 0, 1, 0, 2, 1, 0, 0, 2, 1, 1, 2, 1, 0, 1, 1, 2, 2, 0, 0, 2, 1, 0},
        {2, 1, 0, 2, 1, 2, 2, 0, 1, 0, 1, 0, 2, 2, 0, 1, 0, 2, 1, 1, 0, 1, 2, 0},
        {0, 2, 1, 2, 1, 1, 1, 0, 2, 0, 0, 0, 1, 0, 1, 1, 1, 2, 0, 2, 1, 1, 0, 0},
        {0, 1, 0, 1, 0, 0, 1, 2, 1, 0, 2, 2, 0, 2, 0, 0, 0, 1, 1, 1, 2, 2, 2, 1},
        {1, 2, 2, 1, 0, 1, 2, 2, 0, 0, 1, 2, 2, 1, 1, 0, 0, 2, 0, 0, 1, 2, 2, 0},
        {0, 2, 1, 1, 0, 0, 2, 0, 2, 0, 2, 1, 2, 2, 0, 1, 2, 0, 2, 0, 1, 0, 2, 1},
        {2, 1, 1, 0, 0, 0, 1, 2, 0, 2, 1, 0, 2, 1, 0, 1, 2, 1, 0, 0, 1, 2, 2, 2},
        {2, 0, 1, 2, 1, 1, 0, 1, 1, 2, 2, 0, 0, 2, 0, 1, 0, 0, 1, 1, 0, 2, 0, 1},
        {1, 0, 1, 0, 2, 2, 0, 1, 1, 0, 2, 1, 0, 0, 1, 2, 1, 2, 0, 1, 2, 0, 0, 2},
        {0, 2, 1, 0, 2, 2, 2, 0, 2, 1, 1, 1, 2, 0, 0, 1, 2, 1, 0, 1, 2, 1, 1, 0},
        {1, 0, 2, 0, 1, 1, 0, 0, 0, 1, 1, 0, 2, 0, 0, 1, 1, 0, 1, 2, 0, 0, 1, 1}
    };
    Grass() {
        grass1 = LoadImage("./resources/decor/grass/grass-004.png");
        grass2 = LoadImage("./resources/decor/grass/grass-005.png");
        grass3 = LoadImage("./resources/decor/grass/grass-006.png");
        grassTextureOne = LoadTextureFromImage(grass1);
        grassTextureTwo = LoadTextureFromImage(grass2);
        grassTextureThree = LoadTextureFromImage(grass3);
        UnloadImage(grass1);
        UnloadImage(grass2);
        UnloadImage(grass3);
    }
    ~Grass() {
        UnloadTexture(grassTextureOne);
        UnloadTexture(grassTextureTwo);
        UnloadTexture(grassTextureThree);
    }
    void renderBackground() {
        for(int col = 0; col<cellCount+1; col++) {
            for(int row = 0; row<cellCount+1; row++) {
                    if(grassMap[row][col]==0) {
                        DrawTexture(grassTextureOne,row*cellSize,col*cellSize,WHITE);
                    }
                    if(grassMap[row][col]==1) {
                        DrawTexture(grassTextureTwo,row*cellSize,col*cellSize,WHITE);
                    }
                    if(grassMap[row][col]==2) {
                        DrawTexture(grassTextureThree,row*cellSize,col*cellSize,WHITE);
                    }
            }
        }
    }
};
class Tree {
    public:
    Texture2D treeTextureOne;
    Texture2D treeTextureTwo;
    int treeMap[24][24] = {
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0},
        {0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1}
    };
    Tree() {
        treeTextureOne = LoadTexture("./resources/trees/tree-001.png");
        treeTextureTwo = LoadTexture("./resources/trees/tree-003.png");
    }
    ~Tree() {
        UnloadTexture(treeTextureOne);
        UnloadTexture(treeTextureTwo);
    }
    void draw() {
        int x;
        int y;
        for(int row = 0; row<cellCount-1;row++) {
            for(int col = 0; col<cellCount-1;col++) {
                x = cellSize*col;
                y = cellSize*row;
                if(treeMap[row][col]==1) {
                    DrawTexture(treeTextureOne, x,y,WHITE);
                    DrawRectangle(x+8,y+16,48,32,BLACK);
                }
                if(treeMap[row][col]==2) {
                    DrawTexture(treeTextureTwo, x,y,WHITE);
                    DrawRectangle(x+8,y+16,48,32,BLACK);
                }
            }
        }
    }
};
class Character {
    public:
    int x = cellCount*cellSize/2-24;
    int y = cellCount*cellSize/2-32;
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
    Character() {
        frontSpritesheet = LoadImage("./resources/characters/character1/walk/front/spritesheet.png");
        backSpritesheet = LoadImage("./resources/characters/character1/walk/back/spritesheet.png");
        leftSpritesheet = LoadImage("./resources/characters/character1/walk/left/spritesheet.png");
        rightSpritesheet = LoadImage("./resources/characters/character1/walk/right/spritesheet.png");
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
    ~Character() {
        UnloadTexture(frontTexture);
        UnloadTexture(backTexture);
    }
    void draw() {
        DrawTexture(currentTexture, x, y, WHITE);
    }
    void update() {
        if(IsKeyPressed(KEY_DOWN)) {
            y+=16;
            currentTexture = frontTexture;
        }
        if(IsKeyPressed(KEY_UP)) {
            y-=16;
            currentTexture = backTexture;
        }
        if(IsKeyPressed(KEY_LEFT)) {
            x-=16;
            currentTexture = leftTexture;
        }
        if(IsKeyPressed(KEY_RIGHT)) {
            x+=16;
            currentTexture = rightTexture;
        }
    }
};

int main() {
    InitWindow(cellSize*cellCount, cellSize*cellCount, "farm time");
    SetWindowPosition(200, 200);   
    SetTargetFPS(60);
    Grass grass = Grass();
    Character main = Character();
    Tree tree = Tree();

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground((Color){170,246,131,0});
        grass.renderBackground();
        main.update();
        main.draw();
        tree.draw();
        //without this it would leave trace of ball (redraw)
        EndDrawing();
    }
    CloseWindow();
    return 0;
}