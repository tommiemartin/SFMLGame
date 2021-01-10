#pragma once

#include "State.hpp"

class GameState : public State{
public:
    GameState(sf::RenderWindow* rw);
    virtual ~GameState();

    void updateState(const float& dt);
    void renderState(sf::RenderTarget* target=nullptr);

    void endState();

private:



};