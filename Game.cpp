#include "Game.hpp"

Game::Game(){
    this->initVariables();
    this->initWindow();
    this->initKeys();
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
    this->fullscreen = false;
    this->delta = 0.f;
}


void Game::initWindow(){
    std::ifstream ifs("Config/window.ini");

    videoModes = sf::VideoMode::getFullscreenModes(); // ???

    //defaults
    sf::VideoMode videoMode (1920,1080);
    // sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();

    this->fullscreen = false;
    std::string winTitle = "";
    unsigned framerate = 144;
    bool vsync = false;
    unsigned anti_alias = 0;

    if (ifs.is_open() ){
        std::getline(ifs, winTitle);
        ifs >> videoMode.width >> videoMode.height;
        ifs >> framerate;
        ifs >> vsync;
    }
    ifs.close();

    this->window_settings.antialiasingLevel = anti_alias;
    this->window = new sf::RenderWindow(videoMode,winTitle,sf::Style::Titlebar | sf::Style::Close);
    
    if (fullscreen){
            this->window = new sf::RenderWindow(videoMode,winTitle,sf::Style::Fullscreen, window_settings);

    } else {
            this->window = new sf::RenderWindow(videoMode,winTitle,sf::Style::Titlebar | sf::Style::Close, window_settings);
    }

    this->window->setFramerateLimit(framerate);
    this->window->setVerticalSyncEnabled(vsync);
}

void Game::initStates(){
    this->states.push(new MainMenuState(this->window, &this->states )); 
}

const bool Game::running() const{
    return this->window->isOpen();
}


void Game::updateDelta(){
    // how long it takes to update 1 frame
    this->delta = this->deltaClock.restart().asSeconds();
    // std::cout << this->delta << std::endl;
}

void Game::initKeys(){

    //load from file
    // std::ifstream ifs("Config/file.ini");
    // if(ifs.is_open() ){
    //     std::string key = "";
    //     int key_value = 0;
    //     while (ifs >> key >> key_value){
    //         this->supportedKeys[key] = key_value;
    //     }
    // }

    // map<K, V>
    this->supportedKeys["Escape"] = sf::Keyboard::Key::Escape;
    this->supportedKeys["W"] = sf::Keyboard::Key::W;
    this->supportedKeys["A"] = sf::Keyboard::Key::A;
    this->supportedKeys["S"] = sf::Keyboard::Key::S;
    this->supportedKeys["D"] = sf::Keyboard::Key::D;

    //debug
    // for (auto i : this->supportedKeys){
    //     std::cout << i.first << " " << i.second << std::endl;
    // }

}


/***************************
 *  EVENTS, UPDATE AND RENDER 
 ***************************/

void Game::input(){
    //Game Window
    while (this->window->pollEvent(this->event) ){
        if(this->event.type == sf::Event::Closed){
            this->window->close();
        }
    }

}//


void Game::update(){
    updateDelta();
    
    if(!this->states.empty()){
        this->states.top()->stateInput(this->delta);
        this->states.top()->stateUpdate(this->delta);


        //switch to state run() which would have input, update, render??

        if(this->states.top()->getQuit() ){
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else{
        this->window->close(); //close app if states stack is empty
    }

}

void Game::render(){
    this->window->clear();
    /// render ///

    if(!this->states.empty())
        this->states.top()->stateRender(this->window);


    /// render ///
    this->window->display();  
}