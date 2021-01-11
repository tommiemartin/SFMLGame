#pragma once

#include "State.hpp"

class GameState : public State{
public:
    GameState(sf::RenderWindow* rw);
    virtual ~GameState();
    
    void stateInput(const float& dt);
    void stateUpdate(const float& dt);
    void stateRender(sf::RenderTarget* target=nullptr);
    void endState();


private:
    Entity player;
 

};