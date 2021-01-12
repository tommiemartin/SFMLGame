#pragma once

#include "GameState.hpp"
#include "../Button.hpp"

class MainMenuState : public State{
public:
    MainMenuState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~MainMenuState();

    void stateInput(const float& dt);
    void stateUpdate(const float& dt);
    void stateRender(sf::RenderTarget* target=nullptr);
    void endState();


private:
    sf::RectangleShape background;
    sf::Font font;
    std::map<std::string, Button*> buttonMap;

    void initFonts();
    void initButtons();
    
};

