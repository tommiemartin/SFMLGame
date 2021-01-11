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

class Entity{
public:
    Entity();
    virtual ~Entity();

    virtual void move(const float dir_x, const float dir_y, const float& dt);

    // virtual void update(const float& dt) =0 ;
    // virtual void render(sf::RenderTarget* target) = 0;

    virtual void input(const float& dt);
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);

private:
    sf::RectangleShape shape;
    float moveSpeed;


};