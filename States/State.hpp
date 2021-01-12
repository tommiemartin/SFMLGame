#pragma once

#include "../Entity/Entity.hpp"


class State{
public:
    State(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~State();

    virtual void stateInput(const float& dt) =0;
    virtual void stateUpdate(const float& dt) =0;
    virtual void stateRender(sf::RenderTarget* target=nullptr) =0;
    virtual void endState() = 0;

    void updateMousPositions();

    virtual void checkQuitState();
    const bool& getQuit() const;


private:
    std::vector<sf::Texture> textures;
    bool quit;

protected:  
    sf::RenderWindow* window;
    std::stack<State*>* states; //passed by ref recieved here as pointer

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView; //for camera

};