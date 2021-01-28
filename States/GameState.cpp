#include "GameState.hpp"

GameState::GameState(sf::RenderWindow* rw, std::stack<State*>* states, sf::Font& font)
    :   State(rw, states){

    this->loadTextures();
    player = new Player(200,200, this->textures["HERO_SHEET"]);

    init(font);

}

GameState::~GameState(){
    delete this->player;
}

void GameState::init(sf::Font& f){
    pauseText.setPosition(sf::Vector2f(
        this->window->getSize().x /2  - this->pauseText.getGlobalBounds().width, 
        this->window->getSize().y /2 - this->pauseText.getGlobalBounds().height) ); //not centered
    pauseText.setFont(f);
    pauseText.setCharacterSize(40);
    pauseText.setString("PAUSED");
    pauseText.setColor(sf::Color::Red);
}

void GameState::loadTextures(){
    // sf::Texture loader;
    // loader.loadFromFile("res/Images/temp.png");
    // this->textures["PLAYER_IDLE"] = loader;

    this->textures["HERO_SHEET"].loadFromFile("res/Images/hero.png");
}

void GameState::stateInput(const float& dt){
    this->updateMousPositions();


    if(!this->paused){
        this->player->input(dt);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        paused = !paused;
    }
}


void GameState::stateUpdate(const float& dt){
    if(!this->paused){
        this->player->update(dt);
   
    }
}//


void GameState::stateRender(sf::RenderTarget* target){
        this->player->render(target);

        if(this->paused)
            target->draw(this->pauseText);
}  

