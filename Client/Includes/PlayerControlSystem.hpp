#ifndef R_TYPE_PlayerControlSystem_H
#define R_TYPE_PlayerControlSystem_H

#include "MonsterControlSystem.hpp"

#define SPEED 15.f

class Player
{
public:
    Player();
    ~Player();
    void UpdatePLayer(bool, Direction);
    void draw(sf::RenderWindow);
    void setPosition();
    Position _posPlayer;
    sf::CircleShape _shapePlayer;
private:

};

#endif //R_TYPE_PlayerControlSystem_H