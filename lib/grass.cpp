#include "grass.h"
using namespace std;
Grass::Grass() {
    grass1 = LoadImage("../resources/decor/grass/grass-004.png");
    grass2 = LoadImage("../resources/decor/grass/grass-005.png");
    grass3 = LoadImage("../resources/decor/grass/grass-006.png");
    grassTextureOne = LoadTextureFromImage(grass1);
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
    grassTextureTwo = LoadTextureFromImage(grass2);
    grassTextureThree = LoadTextureFromImage(grass3);
    UnloadImage(grass1);
    UnloadImage(grass2);
    UnloadImage(grass3);
}
Grass::~Grass() {
    UnloadTexture(grassTextureOne);
    UnloadTexture(grassTextureTwo);
    UnloadTexture(grassTextureThree);
}
void Grass::draw() {
    for(int row = 0; row<=cellVertical; row++) {
        for(int col = 0; col<=cellHorizontal; col++) {
                if(grassMap[row][col]==0) {
                    DrawTexture(grassTextureOne,col*cellSize*2,row*cellSize*2,WHITE);
                }
                else if(grassMap[row][col]==1) {
                    DrawTexture(grassTextureTwo,col*cellSize*2,row*cellSize*2,WHITE);
                }
                else if(grassMap[row][col]==2) {
                    DrawTexture(grassTextureThree,col*cellSize*2,row*cellSize*2,WHITE);
                }
        }
    }
}
