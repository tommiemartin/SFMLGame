#pragma once

#include "../Entity/Player.hpp"


class State{
public:
    State(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~State();

    virtual void stateInput(const float& dt) =0;
    virtual void stateUpdate(const float& dt) =0;
    virtual void stateRender(sf::RenderTarget* target=nullptr) =0;

    const bool& getQuit() const; //from game
    
private:

    
protected:  
    sf::RenderWindow* window;
    std::stack<State*>* states; //passed by ref recieved here as pointer
   
    //all textures used by the state
    std::map<std::string, sf::Texture> textures; 
    virtual void loadTextures() =0;

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView; //for camera
    void updateMousPositions();

    void setQuit();
    bool quit;
};