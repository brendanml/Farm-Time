#include "tree.h"
using namespace std;
Tree::Tree() {
    printf("WORKINGG");
    treeTextureOne = LoadTexture("../resources/trees/tree-004.png");
    treeTextureTwo = LoadTexture("../resources/trees/tree-003.png");
}
Tree::~Tree() {
    UnloadTexture(treeTextureOne);
    UnloadTexture(treeTextureTwo);
}
void Tree::draw() {
    int xTree;
    int yTree;
    bool tree = false;
    for(int row = 0; row<16;row++) {
        for(int col = 0; col<16;col++) {
            tree = false;
            xTree = 48*col;
            yTree = 48*row;
            if(treeMap[row][col]==1) {
                DrawTexture(treeTextureOne, xTree,yTree,WHITE);
                tree = true;
            }
            else if(treeMap[row][col]==2) {
                DrawTexture(treeTextureTwo, xTree,yTree,WHITE);
                tree = true;
            }
            //toggle drawing tree hitbox
            //if(tree) {drawHitbox(xTree,yTree);};
        }
    }
}
void Tree::drawHitbox(int x, int y) {
    DrawRectangle(x,y+16,48,48,BLACK);
}

