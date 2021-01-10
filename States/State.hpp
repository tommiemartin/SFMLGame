#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
// #include "SFML/Network.hpp"

#include <iostream>
#include<vector>

#include <fstream>
// #include <sstream>

#include<stack>
#include<map>

class State{
public:
    State(sf::RenderWindow* rw);
    virtual ~State();

    virtual void updateState(const float& dt) =0;
    virtual void renderState(sf::RenderTarget* target=nullptr) =0;

    virtual void endState() =0;

private:
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;


};