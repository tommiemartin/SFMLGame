#include "Game.hpp"

Game::Game(){
    this->initVariables();
    this->initWindow();
    this->initStates();
}

Game::~Game(){
    delete this->window;

    while(!this->states.empty()){
        delete this->states.top(); //delete data at pointer
        this->states.pop(); //delete pointer
    }

        
}

void Game::initVariables(){
    this->window = nullptr;
}


void Game::initWindow(){
    std::ifstream ifs("Config/window.ini");

    sf::VideoMode videoMode (1920,1080);
    std::string winTitle = "";
    unsigned framerate = 144;
    bool vsync = false;

    if (ifs.is_open() ){
        std::getline(ifs, winTitle);
        ifs >> videoMode.width >> videoMode.height;
        ifs >> framerate;
        ifs >> vsync;
    }

    ifs.close();

    this->window = new sf::RenderWindow(videoMode,winTitle,sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(framerate);
    this->window->setVerticalSyncEnabled(vsync);
}

void Game::initStates(){
    this->states.push(new GameState(this->window )); 
}

const bool Game::running() const{
    return this->window->isOpen();
}


void Game::pollEvents(){
    while (this->window->pollEvent(this->event) ){
        if(this->event.type == sf::Event::Closed){
            this->window->close();
        }
    }

}//

void Game::updateDelta(){
    // how long it takes to update 1 frame
    this->delta = this->deltaClock.restart().asSeconds();
    // std::cout << this->delta << std::endl;
}


/***************************
 *  UPDATE AND RENDER 
 ***************************/

void Game::update(){
    updateDelta();

    if(!this->states.empty())
        this->states.top()->updateState(this->delta);
}

void Game::render(){
    this->window->clear();
    /// render ///

    if(!this->states.empty())
        this->states.top()->renderState(this->window);


    /// render ///
    this->window->display();  
}