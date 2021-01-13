#include "Player.hpp"

Player::Player(float x, float y, sf::Texture* tex){
    initSprite(x,y,tex); 
    sprite->scale(3, 3);

    this->moveSpeed = 100.f;
}

Player::~Player(){    
}

void Player::input(const float& dt){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        move(-1.f,0.f,dt);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        move(1.f,0.f,dt);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        move(0.f,-1.f,dt);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        move(0.f,1.f,dt);
    }
}

void Player::update(const float& dt){

}
void Player::render(sf::RenderTarget* target){
    target->draw(*this->sprite);
}  

void Player::move(const float dir_x, const float dir_y, const float& dt){
    this->sprite->move(dir_x * this->moveSpeed * dt, dir_y * this->moveSpeed * dt);
}