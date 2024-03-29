#include "Game.h"
extern "C"
{
#include "raylib.h"
}

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