#pragma once
#include "Entity.hpp"

class Player :public Entity{
public:
    Player(float x, float y, sf::Texture* tex);
    virtual ~Player();
    void input(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target);


private:
    void move(const float dir_x, const float dir_y, const float& dt);
    float moveSpeed;

};