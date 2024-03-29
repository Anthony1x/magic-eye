#include "Grid.h"

Grid::Grid()
{
}

Grid::Grid(int cellSize) : cellSize(cellSize)
{
    int numCells = GetNumCells(cellSize);
    cellColors = std::vector<Color>(numCells * numCells);

    // Initialize all cell colors to black
    for (int i = 0; i < numCells * numCells; i++)
    {
        cellColors[i] = BLACK;
    }
}

Color Grid::GetCellColor(int x, int y)
{
    return cellColors[y * GetNumCells(cellSize) + x];
}

void Grid::SetCellColor(int x, int y, Color color)
{
    int numCells = GetNumCells(cellSize);
    if (x >= 0 && x < numCells && y >= 0 && y < numCells)
    {
        cellColors[y * numCells + x] = color;
    }
}

void Grid::DrawGrid()
{
    int numCells = GetNumCells(cellSize);

    /* for (int i = 0; i <= numCellsX; i++) {
    // Draw vertical lines
      DrawLine(i * cellSize, 0, i * cellSize, GetScreenHeight(), RAYWHITE);
    }

    for (int i = 0; i <= numCellsY; i++) {
        // Draw horizontal lines
        DrawLine(0, i * cellSize, GetScreenWidth(), i * cellSize, RAYWHITE);
    }
    */

    // Draw cell colors
    for (int y = 0; y < numCells; y++)
    {
        for (int x = 0; x < numCells; x++)
        {
            Color aa = cellColors[y * numCells + x];
            DrawRectangle(x * cellSize, y * cellSize, cellSize, cellSize, aa);
        }
    }
}

// Helper function to get number of cells based on screen size
int Grid::GetNumCells(int cellSize)
{
    return (GetScreenWidth() / cellSize) + 1; // Add 1 to ensure full coverage
}
