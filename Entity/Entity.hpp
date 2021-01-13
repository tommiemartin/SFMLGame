#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include <iostream>
#include<vector>

#include <fstream>
#include <sstream>

#include<stack>
#include<map>

class Entity{
public:
    Entity();
    virtual ~Entity();

    virtual void input(const float& dt)  =0;
    virtual void update(const float& dt) =0;
    virtual void render(sf::RenderTarget* target)=0;

protected:
    sf::Texture* texture;
    sf::Sprite* sprite;
    void initSprite(const float x, const float y,sf::Texture* tex);

};