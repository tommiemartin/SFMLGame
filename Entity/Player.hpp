#pragma once
#include "Entity.hpp"

class Player :public Entity{
public:
    Player(float x, float y, sf::Texture& tex);
    virtual ~Player();
    void input(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target);

    sf::Clock clock;
    float anim_speed;


private:
    void initSprite(const float x, const float y, sf::Texture& tex, sf::IntRect& rect);

    // class Animation{
    //     public:
    //         Animation();
    //         virtual ~Animation();
    //         sf::Texture& texture;
    //         std::map<std::string, Animation> animations;
    //         float anim_speed;

    //     private:
    //         void play();
    //         void pause();
    //         void reset();
    // };

    //for moving characters 
    // Animation* anim;
    
    void updateFrames();
    sf::IntRect currentFrame;
    bool play;
    int prevIndex; //to replay middle frame

    void move(const float& dt);
    sf::Vector2i direction;
    sf::Vector2f velocity;
    float maxVelocity;
    float accel;
    float decel;


};