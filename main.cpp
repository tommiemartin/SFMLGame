#include "Game.hpp"

int main(){

    Game game;

    //Game Loop
    while (game.running() )
    {
        game.pollEvents();
        game.update();
        game.render();

    }//while

}//