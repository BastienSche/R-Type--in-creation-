#include "../Includes/Graphics.h"

Graphics::Graphics()
{
    // std::cout <<"hey"<<std::endl;
    // _windowManager.initWindow("R-Type", 1000, 1000);
    // _assets.loadTexture();
    // _assets.loadSprite();
    // _assets.initAssets();
    // _menu.initMenu();
    // _l_moveSpeed = 40;
    // _v_moveSpeed = 30;
}

Graphics::~Graphics()
{

}


///
/// Initializes graphics.\n
/// Calls initAssets and initWindow.
///
void Graphics::initGraphics()
{
    std::cout << "initWindow => " << WINDOW_WIDTH << ", " << WINDOW_HEIGHT << std::endl;
    _windowManager.initWindow("R-Type", WINDOW_WIDTH, WINDOW_HEIGHT);
    _assets.initAssets();
    initPlayerShip();
    initBackground();
    initUi();

    _waiting = true;

    _l_moveSpeed = 20;
    _v_moveSpeed = 15;
}

///
/// Init player Ship
///
void Graphics::initPlayerShip()
{
    _p_playerShip = sf::Vector2f(200, 200);
    
    _assets._s_playerShip.setPosition(_p_playerShip);
    _playerShipRect.left = 166;
    _playerShipRect.top = 0;
    _playerShipRect.width = 33;
    _playerShipRect.height = 15;
    _assets._s_playerShip.setTextureRect(_playerShipRect);
    _assets._s_playerShip.setScale(3.f, 3.f);
    _playerShipClock.restart();
}

///
/// init Background
///
void Graphics::initBackground()
{
    _p_background_L1 = sf::Vector2f(0, 0);
    _p_background_L2 = sf::Vector2f(0, 0);
    _p_background_L3 = sf::Vector2f(0, 0);
    _assets._s_background_L1.setPosition(_p_background_L1);
    _assets._s_background_L2.setPosition(_p_background_L2);
    _assets._s_background_L3.setPosition(_p_background_L3);
    _backgroundClock_L1.restart();
    _backgroundClock_L2.restart();
    _backgroundClock_L3.restart();
}

///
/// init Parrallax
///
void Graphics::initParallaxBgOne()
{
    _p_backgroundParallaxOne_L0.x = 0;
    _p_backgroundParallaxOne_L1.x = 0;
    _p_backgroundParallaxOne_L2.x = 0;
    _p_backgroundParallaxOne_L3.x = 0;
    _p_backgroundParallaxOne_L4.x = 0;
    _p_backgroundParallaxOne_L5.x = 0;
    _p_backgroundParallaxOne_L6.x = 0;
    _p_backgroundParallaxOne_L7.x = 0;
}

void Graphics::initUi()
{
    _p_playerLife.x = WINDOW_WIDTH - _assets._r_playerLife.width;
    _p_playerLife.y = 0;

    _p_powerChargeBar.x = 20;
    _p_powerChargeBar.y = 20;

    _p_powerCharge.x = _p_powerChargeBar.x + 20;
    _p_powerCharge.y = _p_powerChargeBar.y + 35;
}

///
/// Draw parrallax
///
void Graphics::drawParallaxBgOne()
{
    // std::cout << "1rst: " << _p_backgroundParallaxOne_L0.x << std::endl;
    if (_c_backgroundParallaxOne_L0.getElapsedTime().asMilliseconds() >= 2){
        _p_backgroundParallaxOne_L0.x += 5;
        if (_p_backgroundParallaxOne_L0.x >= 1950){
            _p_backgroundParallaxOne_L0.x = 0;
        }
        _c_backgroundParallaxOne_L0.restart();
    }
    if (_c_backgroundParallaxOne_L1.getElapsedTime().asMilliseconds() >= 2){
        _p_backgroundParallaxOne_L1.x += 6;
        if (_p_backgroundParallaxOne_L1.x >= 1950){
            _p_backgroundParallaxOne_L1.x = 0;
        }
        _c_backgroundParallaxOne_L1.restart();
    }
    if (_c_backgroundParallaxOne_L2.getElapsedTime().asMilliseconds() >= 2){
        _p_backgroundParallaxOne_L2.x += 7;
        if (_p_backgroundParallaxOne_L2.x >= 1950){
            _p_backgroundParallaxOne_L2.x = 0;
        }
        _c_backgroundParallaxOne_L2.restart();
    }
    if (_c_backgroundParallaxOne_L3.getElapsedTime().asMilliseconds() >= 2){
        _p_backgroundParallaxOne_L3.x += 8;
        if (_p_backgroundParallaxOne_L3.x >= 1950){
            _p_backgroundParallaxOne_L3.x = 0;
        }
        _c_backgroundParallaxOne_L3.restart();
    }
    if (_c_backgroundParallaxOne_L4.getElapsedTime().asMilliseconds() >= 2){
        _p_backgroundParallaxOne_L4.x += 9;
        if (_p_backgroundParallaxOne_L4.x >= 1950){
            _p_backgroundParallaxOne_L4.x = 0;
        }
        _c_backgroundParallaxOne_L4.restart();
    }
    if (_c_backgroundParallaxOne_L5.getElapsedTime().asMilliseconds() >= 2){
        _p_backgroundParallaxOne_L5.x += 10;
        if (_p_backgroundParallaxOne_L5.x >= 1950){
            _p_backgroundParallaxOne_L5.x = 0;
        }
        _c_backgroundParallaxOne_L5.restart();
    }
    if (_c_backgroundParallaxOne_L6.getElapsedTime().asMilliseconds() >= 2){
        _p_backgroundParallaxOne_L6.x += 11;
        if (_p_backgroundParallaxOne_L6.x >= 1950){
            _p_backgroundParallaxOne_L6.x = 0;
        }
        _c_backgroundParallaxOne_L6.restart();
    }
    if (_c_backgroundParallaxOne_L7.getElapsedTime().asMilliseconds() >= 2){
        _p_backgroundParallaxOne_L7.x += 12;
        if (_p_backgroundParallaxOne_L7.x >= 1950){
            _p_backgroundParallaxOne_L7.x = 0;
        }
        _c_backgroundParallaxOne_L7.restart();
    }
    parallaxBgOneSetPos();
    _windowManager._window.draw(_assets._s_bgparallax_0);
    _windowManager._window.draw(_assets._s_bgparallax_1);
    _windowManager._window.draw(_assets._s_bgparallax_2);
    _windowManager._window.draw(_assets._s_bgparallax_3);
    _windowManager._window.draw(_assets._s_bgparallax_4);
    _windowManager._window.draw(_assets._s_bgparallax_5);
    _windowManager._window.draw(_assets._s_bgparallax_6);
    _windowManager._window.draw(_assets._s_bgparallax_7);
    _windowManager._window.draw(_assets._s_bgparallax_0_0);
    _windowManager._window.draw(_assets._s_bgparallax_0_1);
    _windowManager._window.draw(_assets._s_bgparallax_0_2);
    _windowManager._window.draw(_assets._s_bgparallax_0_3);
    _windowManager._window.draw(_assets._s_bgparallax_0_4);
    _windowManager._window.draw(_assets._s_bgparallax_0_5);
    _windowManager._window.draw(_assets._s_bgparallax_0_6);
    _windowManager._window.draw(_assets._s_bgparallax_0_7);
}

///
/// Setp pos parallax
///
void Graphics::parallaxBgOneSetPos()
{
    _assets._s_bgparallax_0.setPosition(_p_backgroundParallaxOne_L0);
    _assets._s_bgparallax_1.setPosition(_p_backgroundParallaxOne_L1);
    _assets._s_bgparallax_2.setPosition(_p_backgroundParallaxOne_L2);
    _assets._s_bgparallax_3.setPosition(_p_backgroundParallaxOne_L3);
    _assets._s_bgparallax_4.setPosition(_p_backgroundParallaxOne_L4);
    _assets._s_bgparallax_5.setPosition(_p_backgroundParallaxOne_L5);
    _assets._s_bgparallax_6.setPosition(_p_backgroundParallaxOne_L6);
    _assets._s_bgparallax_7.setPosition(_p_backgroundParallaxOne_L7);
    _assets._s_bgparallax_0_0.setPosition(_p_backgroundParallaxOne_L0.x - 2000, _p_backgroundParallaxOne_L0.y);
    _assets._s_bgparallax_0_1.setPosition(_p_backgroundParallaxOne_L1.x - 2000, _p_backgroundParallaxOne_L1.y);
    _assets._s_bgparallax_0_2.setPosition(_p_backgroundParallaxOne_L2.x - 2000, _p_backgroundParallaxOne_L2.y);
    _assets._s_bgparallax_0_3.setPosition(_p_backgroundParallaxOne_L3.x - 2000, _p_backgroundParallaxOne_L3.y);
    _assets._s_bgparallax_0_4.setPosition(_p_backgroundParallaxOne_L4.x - 2000, _p_backgroundParallaxOne_L4.y);
    _assets._s_bgparallax_0_5.setPosition(_p_backgroundParallaxOne_L5.x - 2000, _p_backgroundParallaxOne_L5.y);
    _assets._s_bgparallax_0_6.setPosition(_p_backgroundParallaxOne_L6.x - 2000, _p_backgroundParallaxOne_L6.y);
    _assets._s_bgparallax_0_7.setPosition(_p_backgroundParallaxOne_L7.x - 2000, _p_backgroundParallaxOne_L7.y);
}

void Graphics::drawUi()
{
    std::cout << "ZIEUGFIZUGHEFUYI" << std::endl;
    //setup UI
    // int life = 0;
    // int ultCharge = 0;
    
    // life = _windowManager._monster->_PlayerLife;
    // ultCharge = _windowManager._monster->_UltiShootProgress;

    if (_windowManager._monster->_PlayerLife == 3){
        _assets._r_playerLife.top = 0;
    } else if (_windowManager._monster->_PlayerLife == 2){
        _assets._r_playerLife.top = 143;
    } else if (_windowManager._monster->_PlayerLife == 1){
        _assets._r_playerLife.top = 286;
    } else if (_windowManager._monster->_PlayerLife == 0){
        _assets._r_playerLife.top = 429;
    }
    _assets._s_playerLife.setTextureRect(_assets._r_playerLife);
    _assets._s_playerLife.setPosition(_p_playerLife);

    if(_windowManager._monster->_UltiShootProgress == 0){
        _assets._r_powerCharge.top = 0;
        _assets._r_powerChargeBar.top = 0;
        _assets._r_powerCharge.width = 0;
    } else if (_windowManager._monster->_UltiShootProgress == 1){
        _assets._r_powerCharge.top = 0;
        _assets._r_powerChargeBar.top = 0;
        _assets._r_powerCharge.width = 80;
    } else if (_windowManager._monster->_UltiShootProgress == 2){
        _assets._r_powerCharge.top = 0;
        _assets._r_powerChargeBar.top = 0;
        _assets._r_powerCharge.width = 160;
    } else if (_windowManager._monster->_UltiShootProgress == 3){
        _assets._r_powerCharge.top = 0;
        _assets._r_powerChargeBar.top = 0;
        _assets._r_powerCharge.width = 240;
    } else if (_windowManager._monster->_UltiShootProgress == 4){
        _assets._r_powerCharge.top = 0;
        _assets._r_powerChargeBar.top = 0;
        _assets._r_powerCharge.width = 320;
    } else if (_windowManager._monster->_UltiShootProgress >= 5){
        _assets._r_powerCharge.top = 111;
        _assets._r_powerChargeBar.top = 0;
        _assets._r_powerCharge.width = 402;
        if (_c_powerCharge.getElapsedTime().asMilliseconds() >= 1000){
            _assets._r_powerChargeBar.top += 106;
            if (_assets._r_powerChargeBar.top >= 531){
                _assets._r_powerChargeBar.top = 106;
            }
            _c_powerCharge.restart();
        }
    }
    _assets._s_powerCharge.setTextureRect(_assets._r_powerCharge);
    _assets._s_powerChargeBar.setTextureRect(_assets._r_powerChargeBar);
    _assets._s_powerCharge.setPosition(_p_powerCharge);
    _assets._s_powerChargeBar.setPosition(_p_powerChargeBar);

    //draw UI
    _windowManager._window.draw(_assets._s_playerLife);
    _windowManager._window.draw(_assets._s_powerCharge);
    _windowManager._window.draw(_assets._s_powerChargeBar);
}

void Graphics::drawOtherPlayer()
{

}

///
/// Draw player
///
void Graphics::drawPlayer()
{
    _windowManager._window.draw(_assets._s_playerShip);
}

///
/// Set pos of player
///
void Graphics::playerSetPos()
{
    _assets._s_playerShip.setPosition(_p_playerShip);
}

///
/// Check status playerRight
///
void Graphics::playerRight()
{
    if (_playerShipClock.getElapsedTime().asMilliseconds() > 20){
        if (_p_playerShip.x <= 1776){
            _p_playerShip.x += _l_moveSpeed;
        }
        
        playerSetPos();
        _playerShipClock.restart();
    }
}

void Graphics::playerLeft()
{
    if (_playerShipClock.getElapsedTime().asMilliseconds() > 20){
        if (_p_playerShip.x >= 14){
            _p_playerShip.x -= _l_moveSpeed;
        }
        playerSetPos();
        _playerShipClock.restart();
    }
}

void Graphics::playerUp()
{
    if (_playerShipClock.getElapsedTime().asMilliseconds() > 20){
        if (_p_playerShip.y >= 14){
            _p_playerShip.y -= _v_moveSpeed;
        }
        playerSetPos();
        _playerShipClock.restart();
    }
}

void Graphics::playerDown()
{
    if (_playerShipClock.getElapsedTime().asMilliseconds() > 20){
        if (_p_playerShip.y <= 1020){
            _p_playerShip.y += _v_moveSpeed;
        }
        playerSetPos();
        _playerShipClock.restart();
    }
}

void Graphics::playerImmobile()
{
    
}

void Graphics::playerFire()
{

}

void Graphics::playerHit()
{
    //Make spaceship blink in red probably
}

///
/// Sets position for the different layers in the background.
///
void Graphics::backgroundSetPos()
{
    _assets._s_background_L1.setPosition(_p_background_L1);
    _assets._s_background_L2.setPosition(_p_background_L2);
    _assets._s_background_L3.setPosition(_p_background_L3);
}

///
/// Draws parallax background for the game.
///
void Graphics::drawBackground()
{
    if (_backgroundClock_L1.getElapsedTime().asMilliseconds() > 20){
        _p_background_L1.x -= SCROLL_RATE_BG_1;
        _backgroundClock_L1.restart();
    }
    if (_backgroundClock_L2.getElapsedTime().asMilliseconds() > 20){
        _p_background_L2.x -= SCROLL_RATE_BG_2;
        _backgroundClock_L2.restart();
    }
    if (_backgroundClock_L3.getElapsedTime().asMilliseconds() > 20){
        _p_background_L3.x -= SCROLL_RATE_BG_3;
        _backgroundClock_L3.restart();
    }
    backgroundSetPos();
    _windowManager._window.draw(_assets._s_background_L1);
    _windowManager._window.draw(_assets._s_background_L2);
    _windowManager._window.draw(_assets._s_background_L3);
}

///
/// Draws sprite.\n 
/// Shortcut to be able to do _graphics.draw(sprite).
///
void Graphics::draw(sf::Sprite sprite)
{
    _windowManager._window.draw(sprite);
}

///
/// Clears window.\n
/// Shortcut to be able to do _graphics.clear().
///
void Graphics::clear()
{
    _windowManager._window.clear();
}

///
/// display window.\n
/// Shortcut to be able to do _graphics.display().
///
void Graphics::display()
{
    _windowManager._window.display();
}