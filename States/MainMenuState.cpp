#include "MainMenuState.hpp"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states)
:State(window, states){

    this->initFonts();
    this->background.setSize(sf::Vector2f(window->getSize().x,window->getSize().y) );
    this->background.setFillColor(sf::Color::Magenta);
    this->initButtons();
}

MainMenuState::~MainMenuState(){
    for (auto i = this->buttonMap.begin(); i != this->buttonMap.end(); ++i){
        delete i->second;
    }
}

void MainMenuState::initFonts(){
    if(!this->font.loadFromFile("Resource/Fonts/BLKCHCRY.TTF") ){
        throw("ERROR::MAINMENUSTATE : COULD NOT LOAD FONT");
    }
}

void MainMenuState::initButtons(){
    this->buttonMap["NewGame"]  = new Button(250,250,250,50,font,"New Game",sf::Color::Blue,sf::Color::Green,sf::Color::Yellow);
    this->buttonMap["QuitGame"] = new Button(250,350,250,50,font,"Quit Game",sf::Color::Blue,sf::Color::Green,sf::Color::Yellow);

}


void MainMenuState::stateInput(const float& dt){
    this->updateMousPositions();
}

void MainMenuState::stateUpdate(const float& dt){

    //Buttons
    for(auto &i :this->buttonMap){
        i.second->update(this->mousePosView);
    }
    if(this->buttonMap["NewGame"]->isPressed() ){
        this->states->push(new GameState(this->window, this->states));
    }

    if(this->buttonMap["QuitGame"]->isPressed() ){
        this->endState();
    }
}

void MainMenuState::stateRender(sf::RenderTarget* target){
    target->draw(this->background);
    // this->test_button->render(target);
    for(auto &i :this->buttonMap){
        i.second->render(target);
    }
}  


void MainMenuState::endState(){
    std::cout << "ENDING MENU STATE" << std::endl;
}
