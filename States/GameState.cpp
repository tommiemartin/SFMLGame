#include "GameState.hpp"

GameState::GameState(sf::RenderWindow* rw)
    :   State(rw){

}

GameState::~GameState(){

}

void GameState::updateState(const float& dt){
    std::cout << "GAME STATE" << std::endl;
}


void GameState::renderState(sf::RenderTarget* target){
    
} 

void GameState::endState(){
    
}