#include "../../Includes/PlayerControlSystem.hpp"

///
/// Constructeur Player() \n
/// _ShapePlayer -> Shape of player \n
/// _posPlayer -> Position of player
///
Player::Player()
{
    _shapePlayer.setRadius(40.f);
    _shapePlayer.setFillColor(sf::Color::Cyan);
    _posPlayer.x = 100.f;
    _posPlayer.y = 100.f;
}

Player::~Player()
{
}

///
/// Set the position for the Player
///
void Player::setPosition()
{
    _shapePlayer.setPosition(_posPlayer.x, _posPlayer.y);
}

/// 
/// Draw the Player
///
void Player::draw(sf::RenderWindow mWindow)
{
    mWindow.draw(_shapePlayer);
}

/// 
/// Set the direction of player
/// 
void Player::UpdatePLayer(bool action, Direction direction)
{
    if (action == true && direction != -1) {
        if (direction == Top) {
            _posPlayer.y = _posPlayer.y - SPEED;
            // std::cout << "TOP" << std::endl;
        }
        if (direction == Right) {
            _posPlayer.x = _posPlayer.x + SPEED;
            // std::cout << "DROITE" << std::endl;
        }
        if (direction == Bot) {
            _posPlayer.y = _posPlayer.y + SPEED;
            // std::cout << "BAS" << std::endl;
        }
        if (direction == Left) {
            _posPlayer.x = _posPlayer.x - SPEED;
            // std::cout << "GAUCHE" << std::endl;
        }
    }
}



// Player::Player()
// {
//     _shapePlayer.setRadius(40.f);
//     _shapePlayer.setFillColor(sf::Color::Cyan);
//     _posPlayer.x = 100.f;
//     _posPlayer.y = 100.f;
// }

// Player::~Player()
// {
// }

// void Player::setPosition()
// {
//     _shapePlayer.setPosition(_posPlayer.x, _posPlayer.y);
// }

// void Player::draw(sf::RenderWindow mWindow)
// {
//     mWindow.draw(_shapePlayer);
// }

// void Player::UpdatePLayer(bool action, Direction direction)
// {
//     if (action == true && direction != -1) {
//         if (direction == Top) {
//             _posPlayer.y = _posPlayer.y - 1.f;
//             std::cout << "TOP" << std::endl;
//         }
//         if (direction == Right) {
//             _posPlayer.x = _posPlayer.x + 1.f;
//             std::cout << "DROITE" << std::endl;
//         }
//         if (direction == Bot) {
//             _posPlayer.y = _posPlayer.y + 1.f;
//             std::cout << "BAS" << std::endl;
//         }
//         if (direction == Left) {
//             _posPlayer.x = _posPlayer.x - 1.f;
//             std::cout << "GAUCHE" << std::endl;
//         }
//     }
// }
