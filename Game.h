#pragma once
#include "Grid.h"

class Game
{
    public:
    Game();
    void Update();
    void Draw();
    private:
    Grid grid;
};