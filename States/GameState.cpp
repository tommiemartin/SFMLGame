#include "GameState.hpp"

GameState::GameState(sf::RenderWindow* rw, std::stack<State*>* states)
    :   State(rw, states){

    this->loadTextures();
    player = new Player(200,200, &this->textures["PLAYER_IDLE"]);
}

GameState::~GameState(){
    delete this->player;
}

void GameState::loadTextures(){
    // sf::Texture loader;
    // loader.loadFromFile("res/Images/temp.png");
    // this->textures["PLAYER_IDLE"] = loader;

    this->textures["PLAYER_IDLE"].loadFromFile("res/Images/temp.png");
}

void GameState::stateInput(const float& dt){
    this->updateMousPositions();

    this->player->input(dt);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        setQuit();
    }
}


void GameState::stateUpdate(const float& dt){
     
}


void GameState::stateRender(sf::RenderTarget* target){
    this->player->render(target);
}  

