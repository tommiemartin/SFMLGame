#include "Entity.hpp"

Entity::Entity(){
    this->sprite = nullptr;
}

Entity::~Entity(){
    delete this->sprite;
}

void Entity::initSprite(const float x, const float y, sf::Texture* tex){
    this->texture = tex;
    this->sprite = new sf::Sprite(*this->texture);
    this->sprite->setPosition(sf::Vector2f(x,y) );
}
