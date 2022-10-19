#include "../../Includes/BulletControlSystem.hpp"

///
/// Constructeur bullet
///
Bullet::Bullet(Position pos)
{
    _shapeBullet.setRadius(10.f);
    _shapeBullet.setFillColor(sf::Color::Red);
    _posBullet = pos;
    _direction = Nothing;
    _TouchWall++;
    _Drawable = true;
}

///
/// Destructeur bullet
///
Bullet::~Bullet()
{
}

///
/// Update direction of bullet
///
void Bullet::UpdateDirectionBullet()
{
    if (_direction == TopRightRight) { //TOP RIGHT RIGHT
        _posBullet.x = _posBullet.x + 60.f;
        _posBullet.y = _posBullet.y - 30.f;
    } else if (_direction == TopMid) { // TOP MID
        _posBullet.y = _posBullet.y - 30.f;
    } else if (_direction == TopRight) { // TOP RIGHT
        _posBullet.x = _posBullet.x + 30.f;
        _posBullet.y = _posBullet.y - 30.f;
    } else if (_direction == BotRightRight) { // BOT RIGHT RGHT
        _posBullet.x = _posBullet.x + 60.f;
        _posBullet.y = _posBullet.y + 30.f;
    } else if (_direction == BotMid) { // BoT MID
        _posBullet.y = _posBullet.y + 30.f;
    } else if (_direction == BotRight) { // BOT RIGHT
        _posBullet.x = _posBullet.x + 30.f;
        _posBullet.y = _posBullet.y + 30.f;
    } else if (_direction == RRight) { // RIGHT
        _posBullet.x = _posBullet.x + 30.f;
    }
}

///
/// Manage bullet
///
void Bullet::ManageDirectionBullet(int n)
{
    if (_direction == Nothing) {
        if (n == 0) { //TOP RIGHT RIGHT
            _direction = TopRightRight;
        } else if (n == 1) { // TOP MID
            _direction = TopMid;
        } else if (n == 2) { // TOP RIGHT
            _direction = TopRight;
        } else if (n == 3) { // BOT RIGHT RGHT
            _direction = BotRightRight;
        } else if (n == 4) { // BoT MID
            _direction = BotMid;
        } else if (n == 5) { // BOT RIGHT
            _direction = BotRight;
        } else if (n == 6) { // RIGHT
            _direction = RRight;
        }
    }
}

///
/// Check collision for wall for bullet
///
int Bullet::CheckColissionsWall()
{
    if (_posBullet.x >= WINDOW_WIDTH) {
        return (0);
    }                                                   
    if (_posBullet.y + _shapeBullet.getGlobalBounds().height <= 0) {
        if (_direction == TopMid) {
            return (0);
        }
        if (_direction == TopRightRight) {
            _direction = BotRightRight;
        }
        if (_direction == TopRight) {
            _direction = BotRight;
        }
        if (_direction == TopMid) {
            _direction = BotMid;
        }
    }
    if (_posBullet.y + _shapeBullet.getGlobalBounds().height >= WINDOW_HEIGHT) {
        if (_direction == BotMid) {
            return (0);
        }
        if (_direction == BotRightRight) {
            _direction = TopRightRight;
        }
        if (_direction == BotRight) {
            _direction = TopRight;
        }
        if (_direction == BotMid) {
            _direction = TopMid;
        }
    }
    return (-1);
}

///
/// Constructeur ultimate bullet
///
UltimateBullets::UltimateBullets(Position pos)
{
    for (int i = 0; i < 7; i++)
    {
        Bullet *bullet = new Bullet(pos);
        _TabOfUltimateBullet.push_back(bullet);
        // std::cout << "Buullet Creatred ULTI" << std::endl;
    }
    // std::cout << "POs : " << pos.x << ", " << pos.y << std::endl;
    _posUltimateBulletsSpawn = pos;
    managerUltimateBullets();
}

///
/// Destructeur ultimate bullet
///
UltimateBullets::~UltimateBullets()
{
}

///
/// Manager ultimate bullet
///
void UltimateBullets::managerUltimateBullets()
{
    for (int i = 0; i < _TabOfUltimateBullet.size(); i++) {
        // SetupDirBullet(_TabOfPosBullet.at(i));
    }
}