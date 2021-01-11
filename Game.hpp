#pragma once

#include "States/MainMenuState.hpp"

class Game{
public:
    Game();
    virtual ~Game();

    const bool running() const;
    
    void input();
    void update();
    void updateDelta();
    void render();
    

private:
    sf::RenderWindow* window;
    sf::Event event;


    sf::Clock deltaClock;
    float delta;

    std::stack<State*> states;
    std::map<std::string, int> supportedKeys; //?


    void initVariables();
    void initWindow();
    void initStates();
    void initKeys();

};