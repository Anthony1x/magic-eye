#include "Game.h"

Game::Game()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "optical illusion");

    cellSize = 200;

    grid = Grid(cellSize);

    SetTargetFPS(30);
}

void Game::Update()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();

        // Calculate cell coordinates based on mouse position
        int cellX = mouseX / cellSize;
        int cellY = mouseY / cellSize;

        // Check if click is within grid bounds
        int numCells = grid.GetNumCells(cellSize);
        if (cellX >= 0 && cellX < numCells && cellY >= 0 && cellY < numCells)
        {
            Color currentColor = grid.GetCellColor(cellX, cellY);

            grid.SetCellColor(cellX, cellY, WHITE);
        }
    }
}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    grid.DrawGrid();

    EndDrawing();
}
