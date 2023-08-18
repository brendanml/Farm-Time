#include <stdio.h>
#include "raylib.h"
#include <cstdlib>
#include <iostream>
#include <deque>
#include <raymath.h>
using namespace std;    

int cellSize = 32;
int cellVertical = 24;
int cellHorizontal = 26;

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

    int grassMap[24][26] = {
        {0, 2, 1, 1, 0, 2, 1, 2, 2, 0, 1, 0, 0, 1, 1, 2, 0, 2, 1, 0, 0, 1, 0, 2,1, 1},
        {1, 1, 0, 0, 1, 1, 0, 2, 0, 1, 0, 1, 2, 0, 2, 1, 2, 2, 0, 1, 0, 0, 1, 2,1, 1},
        {0, 2, 2, 0, 2, 1, 2, 1, 2, 0, 2, 0, 2, 1, 2, 0, 1, 2, 1, 0, 2, 0, 2, 0,1, 1},
        {2, 1, 1, 0, 2, 0, 1, 2, 0, 0, 1, 2, 2, 1, 2, 0, 2, 2, 1, 0, 2, 0, 1, 1,1, 1},
        {1, 1, 2, 2, 0, 0, 0, 0, 2, 1, 2, 1, 0, 2, 1, 2, 0, 1, 2, 0, 2, 0, 2, 2,1, 1},
        {2, 0, 1, 1, 2, 2, 1, 1, 0, 0, 1, 1, 2, 1, 0, 2, 0, 2, 1, 1, 2, 0, 0, 2,1, 1},
        {1, 1, 2, 0, 2, 2, 1, 2, 0, 0, 1, 1, 2, 2, 2, 0, 1, 1, 0, 2, 2, 0, 0, 2,1, 1},
        {2, 0, 2, 1, 2, 1, 2, 2, 1, 0, 1, 1, 0, 0, 2, 0, 2, 1, 2, 1, 0, 0, 1, 1,1, 1},
        {1, 1, 0, 0, 0, 0, 2, 1, 1, 2, 1, 0, 0, 0, 1, 2, 1, 2, 0, 2, 0, 1, 1, 0,1, 1},
        {0, 0, 1, 1, 0, 2, 2, 2, 2, 1, 2, 1, 1, 0, 1, 0, 1, 1, 1, 2, 0, 0, 2, 1,1, 1},
        {2, 0, 0, 2, 1, 1, 2, 2, 1, 0, 2, 0, 0, 0, 0, 1, 2, 1, 2, 0, 0, 1, 0, 0,1, 1},
        {0, 2, 0, 2, 1, 1, 1, 1, 2, 1, 1, 0, 2, 2, 1, 2, 0, 2, 2, 1, 1, 0, 0, 1,1, 1},
        {1, 0, 2, 1, 0, 2, 1, 0, 0, 2, 0, 1, 1, 0, 1, 2, 1, 2, 0, 1, 0, 2, 2, 2,1, 1},
        {1, 1, 0, 1, 0, 2, 1, 0, 0, 2, 1, 1, 2, 1, 0, 1, 1, 2, 2, 0, 0, 2, 1, 0,1, 1},
        {2, 1, 0, 2, 1, 2, 2, 0, 1, 0, 1, 0, 2, 2, 0, 1, 0, 2, 1, 1, 0, 1, 2, 0,1, 1},
        {0, 2, 1, 2, 1, 1, 1, 0, 2, 0, 0, 0, 1, 0, 1, 1, 1, 2, 0, 2, 1, 1, 0, 0,1, 1},
        {0, 1, 0, 1, 0, 0, 1, 2, 1, 0, 2, 2, 0, 2, 0, 0, 0, 1, 1, 1, 2, 2, 2, 1,1, 1},
        {1, 2, 2, 1, 0, 1, 2, 2, 0, 0, 1, 2, 2, 1, 1, 0, 0, 2, 0, 0, 1, 2, 2, 0,1, 1},
        {0, 2, 1, 1, 0, 0, 2, 0, 2, 0, 2, 1, 2, 2, 0, 1, 2, 0, 2, 0, 1, 0, 2, 1,1, 1},
        {2, 1, 1, 0, 0, 0, 1, 2, 0, 2, 1, 0, 2, 1, 0, 1, 2, 1, 0, 0, 1, 2, 2, 2,1, 1},
        {2, 0, 1, 2, 1, 1, 0, 1, 1, 2, 2, 0, 0, 2, 0, 1, 0, 0, 1, 1, 0, 2, 0, 1,1, 1},
        {1, 0, 1, 0, 2, 2, 0, 1, 1, 0, 2, 1, 0, 0, 1, 2, 1, 2, 0, 1, 2, 0, 0, 2,1, 1},
        {0, 2, 1, 0, 2, 2, 2, 0, 2, 1, 1, 1, 2, 0, 0, 1, 2, 1, 0, 1, 2, 1, 1, 0,1, 1},
        {1, 0, 2, 0, 1, 1, 0, 0, 0, 1, 1, 0, 2, 0, 0, 1, 1, 0, 1, 2, 0, 0, 1, 1,1, 1}
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
        for(int row = 0; row<=cellVertical; row++) {
            for(int col = 0; col<=cellHorizontal; col++) {
                    if(grassMap[row][col]==0) {
                        DrawTexture(grassTextureOne,col*cellSize,row*cellSize,WHITE);
                    }
                    if(grassMap[row][col]==1) {
                        DrawTexture(grassTextureTwo,col*cellSize,row*cellSize,WHITE);
                    }
                    if(grassMap[row][col]==2) {
                        DrawTexture(grassTextureThree,col*cellSize,row*cellSize,WHITE);
                    }
            }
        }
    }
};
class Tree {
    public:
    Texture2D treeTextureOne;
    Texture2D treeTextureTwo;
    int treeMap[24][26] = {
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0,1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,1, 1},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,1, 1},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0,1, 1},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0,1, 1},
        {0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,1, 1},
        {0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0,1, 1},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1,1, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0,1, 1},
        {0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,1, 1},
        {1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1,1, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0,1, 1},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0,1, 1},
        {0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1,1, 1},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,1, 1},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0,1, 1},
        {0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,1, 1},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,1, 1},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1,1, 1}
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
        int xTree;
        int yTree;
        int xHitbox;
        int yHitbox;
        bool tree = false;
        for(int row = 0; row<cellVertical-1;row++) {
            for(int col = 0; col<cellHorizontal;col++) {
                tree = false;
                xTree = (cellSize*col) - 8;
                yTree = cellSize*row;
                if(treeMap[row][col]==1) {
                    DrawTexture(treeTextureOne, xTree,yTree,WHITE);
                    tree = true;
                }
                else if(treeMap[row][col]==2) {
                    DrawTexture(treeTextureTwo, xTree,yTree,WHITE);
                    tree = true;
                }
               //if(tree) {drawHitbox(xTree+8,yTree);};
            }
        }
    }
    void drawHitbox(int x, int y) {
        DrawRectangle(x,y+16,48,48,BLACK);
    }
};
class Character {
    public:
    int x = 0;
    int y = 0;
    int xTile = 0;
    int yTile = 1;

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
    void update(int walkable[][48]) {
        if(IsKeyPressed(KEY_DOWN) && walkable[yTile+1][xTile]==0) {
            y+=16;
            yTile+=1;
            currentTexture = frontTexture;
        }
        if(IsKeyPressed(KEY_UP)&& walkable[yTile-1][xTile]==0) {
            y-=16;
            yTile -=1;
            currentTexture = backTexture;
        }
        if(IsKeyPressed(KEY_LEFT) && walkable[yTile][xTile-1]==0) {
            x-=16;
            xTile -= 1;
            currentTexture = leftTexture;
        }
        if(IsKeyPressed(KEY_RIGHT)&& walkable[yTile][xTile+1]==0) {
            x+=16;
            xTile += 1;
            currentTexture = rightTexture;
        }
    }
};

class Game {
    public:
    Grass grass = Grass();
    Character main = Character();
    Tree tree = Tree();
    int walkable[48][48] = {
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
{1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
{1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0},
{0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
{0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
{1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
{1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
{1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
{1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0},
{0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
{0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
{1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
{1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
{1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1},
{1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1},
{1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
{0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
{1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
};
    void update() {
        grass.renderBackground();
        main.update(walkable);
    }
    void draw() {
        main.draw();
        tree.draw();
    }
};

int main() {
    InitWindow((cellSize*(cellVertical+3)-16), cellSize*cellVertical, "farm time");
    SetWindowPosition(200, 200);   
    SetTargetFPS(60);
    Game game = Game();

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground((Color){170,246,131,0});
        game.update();
        game.draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}