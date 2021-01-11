#include "MainMenuState.hpp"

MainMenuState::MainMenuState(sf::RenderWindow* window)
:State(window){

    this->initFonts();
    this->background.setSize(sf::Vector2f(window->getSize().x,window->getSize().y) );
    this->background.setFillColor(sf::Color::Magenta);

    this->test_button = new Button(250,250,250,50,font,"TEST BUTTON",sf::Color::Blue,sf::Color::Green,sf::Color::Yellow);

}

MainMenuState::~MainMenuState(){
    delete this->test_button;
}

void MainMenuState::initFonts(){
    if(!this->font.loadFromFile("Resource/Fonts/BLKCHCRY.TTF") ){
        throw("ERROR::MAINMENUSTATE : COULD NOT LOAD FONT");
    }
}


void MainMenuState::stateInput(const float& dt){
    this->updateMousPositions();
}

void MainMenuState::stateUpdate(const float& dt){
    this->test_button->update(this->mousePosView);
}


void MainMenuState::stateRender(sf::RenderTarget* target){
    target->draw(this->background);
    this->test_button->render(target);
}  

void MainMenuState::endState(){
    std::cout << "ENDING MENU STATE" << std::endl;
}
