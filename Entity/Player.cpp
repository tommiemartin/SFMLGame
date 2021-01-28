#include "Player.hpp"

Player::Player(float x, float y, sf::Texture& tex){
    currentFrame = sf::IntRect(32,0,32,32);
    play = false;
    prevIndex = 0;

    initSprite(x,y,tex,currentFrame); 
    sprite->scale(4,4);
    direction = sf::Vector2i(0,0);
    velocity = sf::Vector2f(0.f,0.f);
    maxVelocity = 300.f;
    accel = 20.f;
    decel = 50.f;

    // this->anim = new Animation();
    anim_speed = 0.15f;

}

Player::~Player(){    
    // delete this->anim;
}

void Player::input(const float& dt){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) and !sf::Keyboard::isKeyPressed(sf::Keyboard::D)  ){
        direction.x = -1;
        currentFrame.top = 32;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) and !(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) ) {
        direction.x =  1;
        currentFrame.top = 64;
    } else{
        direction.x =  0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) and !sf::Keyboard::isKeyPressed(sf::Keyboard::S) ){
        direction.y = -1;
        currentFrame.top = 96;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) and !sf::Keyboard::isKeyPressed(sf::Keyboard::W) ) {
        direction.y =  1;
        currentFrame.top = 0;
    } else{
        direction.y =  0;
    }

}

void Player::update(const float& dt){
    move(dt);
    updateFrames();
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

void Player::initSprite(const float x, const float y, sf::Texture& tex, sf::IntRect& rect){
    this->sprite = new sf::Sprite(tex, rect);
    this->sprite->setPosition(sf::Vector2f(x,y) );
}

void Player::updateFrames(){
    if( direction.x != 0 || direction.y !=0)
        play = true;
    else
        play = false;

    if(play && clock.getElapsedTime().asSeconds() > anim_speed ){
        if(currentFrame.left == 32 && prevIndex == 64){
            currentFrame.left = 0;
        }else{
            prevIndex = currentFrame.left;
            if(currentFrame.left == 64)
                currentFrame.left -= 32;

            else{
                currentFrame.left += 32;
            }
        }
        sprite->setTextureRect(currentFrame);
        clock.restart();
    }
       
       
}//




