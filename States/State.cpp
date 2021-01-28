#include "State.hpp"

    State::State(sf::RenderWindow* rw, std::stack<State*>* states){
        this->window = rw;
        this->states = states;

        this->quit  = false;
        this->paused = false;
    }


     State::~State(){

    }

    void State::updateMousPositions(){
        this->mousePosScreen = sf::Mouse::getPosition();
        this->mousePosWindow = sf::Mouse::getPosition(*this->window);
        this->mousePosView   = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window) );
    
        // std::cout << "STATE UPDATE MOUSE POS" << this->mousePosView.x << " " << this->mousePosView.y << std::endl;
    }

    const bool& State::getQuit() const{
        return this->quit;
    }

    void State::setQuit(){
        this->quit = true;
    }

    void State::pauseState(){
        this->paused = true;
    }

    void State::unpauseState(){
        this->paused = false;
    }


    
