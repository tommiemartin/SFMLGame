#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include <iostream>
#include<vector>

// #include <fstream>
// #include <ctime>
// #include <cstdlib>

enum button_states{BTN_IDLE =0,BTN_HOVER,BTN_ACTIVE};

class Button{
public:
    Button(float x,float y, float width, float height,
    sf::Font font, std::string text,
    sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);

    ~Button();

    const bool isPressed() const;
    void render(sf::RenderTarget* target);
    void update(sf::Vector2f mousePos);

private:
    sf::RectangleShape button;
    short unsigned button_state;

    // sf::Font* font;
    sf::Font font;
    sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;



};

