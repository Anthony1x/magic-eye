#include "Game.h"
#include "raylib.h"
#include <iostream>

Game::Game()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    grid = Grid(50);

    InitWindow(screenWidth, screenHeight, "optical illusion");

    SetTargetFPS(240);
}

void Game::Update()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        int cellSize = 50;

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

            auto gg = ColorNormalize(currentColor);

            auto cR = gg.x;
            auto cG = gg.y;
            auto cB = gg.z;

            std::cout << "Clicked cell color: (" << cellX << ", " << cellY << ") - " << cR << ", " << cG << ", " << cB
                      << std::endl;

            // grid.SetCellColor(cellX, cellY, WHITE);
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
