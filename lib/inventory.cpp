#include "inventory.h"

void Inventory::draw() {
    DrawRectangle(cellSize*cellHorizontal/2-(cellSize*cellHorizontal/8), cellSize*cellVertical-32, cellSize*cellHorizontal/4, 32, DARKBROWN);
    if(inventory[0] == 1) {
        DrawText(TextFormat("%d x Wood", woodCount), cellSize*cellHorizontal/2-(cellSize*cellHorizontal/9),cellSize*cellVertical-26, 20, RAYWHITE);
    }
}