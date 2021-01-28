#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class PauseMenu{
public:
    PauseMenu(sf::VideoMode& vm, sf::Font& font);
	virtual ~PauseMenu();

    // std::map<std::string, gui::Button*>& getButtons();

	//Functions
	const bool isButtonPressed(const std::string key);

	// void addButton(const std::string key, 
	// 	const float y, 
	// 	const float width,
	// 	const float height,
	// 	const unsigned char_size, 
	// 	const std::string text);
	void update(const sf::Vector2i& mousePosWindow);
	void render(sf::RenderTarget& target);
	
private:
	sf::Font& font;
	sf::Text menuText;

	sf::RectangleShape bg; 
	sf::RectangleShape container;

	// std::map<std::string, gui::Button*> buttons;

};