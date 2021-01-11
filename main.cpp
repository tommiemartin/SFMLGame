#include "Game.hpp"

int main(){

    Game game;

    //Game Loop
    while (game.running() )
    {
        game.input();
        game.update();
        game.render();

    }//while

}//