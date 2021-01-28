#pragma once

#include "State.hpp"

class GameState : public State{
public:
    GameState(sf::RenderWindow* rw, std::stack<State*>* states, sf::Font& font);
    virtual ~GameState();
    
    void stateInput(const float& dt);
    void stateUpdate(const float& dt);
    void stateRender(sf::RenderTarget* target=nullptr);

protected:


private:
    void loadTextures();
    Player* player;

    sf::Text pauseText;
    void init(sf::Font& f);
    
};