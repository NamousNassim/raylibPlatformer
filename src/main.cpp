#include "Game.hpp"
#include <iostream>
int main()
{
    //     //1280 × 720 pixels

  

    Game game = Game(1280,720,"Platformer Game");
    game.Initializer();

    game.Run();
    


}