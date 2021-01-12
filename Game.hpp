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
    std::stack<State*> states;

    std::vector<sf::VideoMode> videoModes; // never used
    sf::ContextSettings window_settings;

    sf::Event event;

    sf::Clock deltaClock;
    float delta;

    std::map<std::string, int> supportedKeys; //?

    bool fullscreen;

    void initVariables();
    void initWindow();
    void initStates();
    void initKeys();

};