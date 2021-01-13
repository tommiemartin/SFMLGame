#include "Player.hpp"

Player::Player(float x, float y, sf::Texture& tex){
    initSprite(x,y,tex); 
    sprite->scale(3,3);
    direction = sf::Vector2i(0,0);
    velocity = sf::Vector2f(0.f,0.f);
    maxVelocity = 200.f;
    accel = 10.f;
    decel = 15.f;
}

Player::~Player(){    
}

void Player::input(const float& dt){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) ){
        direction.x = -1;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
        direction.x =  1;
    } else{
        direction.x =  0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) ){
        direction.y = -1;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ) {
        direction.y =  1;
    } else{
        direction.y =  0;
    }
}

void Player::update(const float& dt){
    move(dt);
}
void Player::render(sf::RenderTarget* target){
    target->draw(*this->sprite);
}  

void Player::move(const float& dt){
    if (direction.x == -1){ //move x
        velocity.x += direction.x * accel;
        velocity.x = std::max(velocity.x, -maxVelocity);
    } else if (direction.x == 1){
        velocity.x += direction.x * accel;
        velocity.x = std::min(velocity.x, maxVelocity);
    } else { //decel X
        if(velocity.x > decel){
            velocity.x -= decel;
        } else if (velocity.x < -decel)
        {
            velocity.x += decel;
        } else{
            velocity.x = 0;
        } 
    }

    if (direction.y == -1){ //move y
        velocity.y += direction.y * accel;
        velocity.y = std::max(velocity.y, -maxVelocity);
    } else if (direction.y == 1){
        velocity.y += direction.y * accel;
        velocity.y = std::min(velocity.y, maxVelocity);
    } else { //decel Y
        if(velocity.y > decel){
            velocity.y -= decel;
        } else if (velocity.y < -decel)
        {
            velocity.y += decel;
        } else{
            velocity.y = 0;
        } 
    }

    sprite->move(velocity * dt);
}