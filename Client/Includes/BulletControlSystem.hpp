//
// Created by Gabriel de Taxis on 20/09/2022.
//

#ifndef R_TYPE_BULLETCONTROLSYSTEM_HH
#define R_TYPE_BULLETCONTROLSYSTEM_HH

#include "Assets.h"

class Bullet
{
public:
    Bullet(Position pos);
    ~Bullet();
    sf::CircleShape _shapeBullet;
    Position _posBullet;
    BulletDir _direction;
    int _TouchWall;
    bool _Drawable;

    void ManageDirectionBullet(int);
    void UpdateDirectionBullet();
    int CheckColissionsWall();

private:

};

class UltimateBullets
{
public:
    UltimateBullets(Position pos);
    ~UltimateBullets();

    Position _posUltimateBulletsSpawn;

    std::vector<Bullet *> _TabOfUltimateBullet; // 0 -> TopLeft // 1 -> TopMid // 2 -> TopRight // 3 -> BotLeft // 4 -> BotMid // 5 -> botRight // 6 -> right

    void managerUltimateBullets();


private:

};

#endif //R_TYPE_BULLETCONTROLSYSTEM_HH
