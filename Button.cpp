#include "Button.hpp"

Button::Button(float x,float y, float width, float height,
    sf::Font font, std::string text,
    sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{ 
    this->button_state = BTN_IDLE;
    this->button.setPosition(sf::Vector2f(x,y) );
    this->button.setSize(sf::Vector2f(width,height) );
    this->font = font;
    this->text.setFont(this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(30);

    this->text.setPosition(
        this->button.getPosition().x + (this->button.getGlobalBounds().width  /2.f) - this->text.getGlobalBounds().width /2.f,
        this->button.getPosition().y + (this->button.getGlobalBounds().height /2.f) - this->text.getGlobalBounds().height /2.f
    );

    this->idleColor   = idleColor;
    this->hoverColor  = hoverColor;
    this->activeColor = activeColor; 

    this->button.setFillColor(this->idleColor);

}

Button::~Button(){

}

const bool Button::isPressed() const{
    if(this->button_state == BTN_ACTIVE )
        return true;

    return false;
}

void Button::render(sf::RenderTarget* target){
    target->draw(this->button);
    target->draw(this->text);

}

void Button::update(sf::Vector2f mousePos){

    this->button_state = BTN_IDLE;
    if (this->button.getFillColor() != idleColor)
        this->button.setFillColor(idleColor);

        // std::cout << " IDLE " << std::endl;

    if(this->button.getGlobalBounds().contains(mousePos) ){
        this->button_state = BTN_HOVER;
        if (this->button.getFillColor() != hoverColor)
            this->button.setFillColor(hoverColor);

            // std::cout << " HOVER " << std::endl;

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            this->button_state = BTN_ACTIVE;
            if (this->button.getFillColor() != activeColor)
            this->button.setFillColor(activeColor);

            // std::cout << " ACTIVE " << std::endl;

        }   
    }
}//