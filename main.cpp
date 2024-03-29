#include "raylib.h"
#include "Game.h"
#include "Grid.h"

int main(void)
{
    Game game = Game();

    while (!WindowShouldClose())
    {
        game.Update();
        game.Draw();
    }

    CloseWindow();

    return 0;
}