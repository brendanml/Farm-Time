#include "inventory.h"
using namespace std;


Inventory::Inventory() {
    invbar = LoadImage("../resources/ui/inventory-icons/inventory.png");
    ImageResize(&invbar, invbar.width / 3, invbar.height / 3);
    invbarTexture = LoadTextureFromImage(invbar);
    logs = LoadImage("../resources/ui/inventory-icons/logs.png");
    ImageResize(&logs, logs.width / 16, logs.height / 16);
    logsTexture = LoadTextureFromImage(logs);
}

Inventory::~Inventory() {
    UnloadTexture(invbarTexture);
    UnloadTexture(logsTexture);
}

void Inventory::draw() {
    // DrawRectangle(cellSize*cellHorizontal/2-(cellSize*cellHorizontal/8), cellSize*cellVertical-32, cellSize*cellHorizontal/4, 32, DARKBROWN);
    DrawTexture(invbarTexture,cellSize*cellHorizontal/2-(cellSize*cellHorizontal/8), cellSize*cellVertical-44,WHITE);
    if(inventory[0] == 1) {
        DrawText(TextFormat("%dx", woodCount), cellSize*cellHorizontal/2-(cellSize*cellHorizontal/9)-6,cellSize*cellVertical-40, 15, RAYWHITE);
        DrawTexture(logsTexture,cellSize*cellHorizontal/2-(cellSize*cellHorizontal/8)+12, cellSize*cellVertical-34,WHITE);
    }
}