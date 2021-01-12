#include "GameState.hpp"

GameState::GameState(sf::RenderWindow* rw, std::stack<State*>* states)
    :   State(rw, states){

}

GameState::~GameState(){

}

void GameState::stateInput(const float& dt){
    this->updateMousPositions();

    this->player.input(dt);
}

void GameState::stateUpdate(const float& dt){
     
}


void GameState::stateRender(sf::RenderTarget* target){
    this->player.render(target);
}  

void GameState::endState(){
    std::cout << "ENDING GAME STATE" << std::endl;
}