#pragma once

#include "States/GameState.hpp"

class Game{
public:
    Game();
    virtual ~Game();

    const bool running() const;
    void pollEvents();
    void update();
    void updateDelta();
    void render();
    

private:
    sf::RenderWindow* window;
    sf::Event event;
    

    sf::Clock deltaClock;
    float delta;

    std::stack<State*> states;

    // sf::Vector2i mousePosWin;
    // sf::Vector2f mousePosView;


    void initVariables();
    void initWindow();
    void initStates();

};