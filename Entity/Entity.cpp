#include "Entity.hpp"

Entity::Entity(){
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
    this->moveSpeed = 100.f;
}

Entity::~Entity(){

}

void Entity::input(const float& dt){
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

void Entity::update(const float& dt){

}
void Entity::render(sf::RenderTarget* target){
    target->draw(this->shape);
}  

void Entity::move(const float dir_x, const float dir_y, const float& dt){
    this->shape.move(dir_x * this->moveSpeed * dt, dir_y * this->moveSpeed * dt);
}