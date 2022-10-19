// #include "Assets.h"
#include "Menu.h"
// #include "WindowManaging.h"
#include <iostream>
#include <string>

#define SCROLL_RATE_BG_1 1;
#define SCROLL_RATE_BG_2 2;
#define SCROLL_RATE_BG_3 3;

class Graphics
{
    private:

        // Menu _menu;

        int _l_moveSpeed;
        int _v_moveSpeed;

        //Positions
        sf::Vector2f _p_playerShip;
        sf::Vector2f _p_background_L1;
        sf::Vector2f _p_background_L2;
        sf::Vector2f _p_background_L3;

        sf::Vector2f _p_backgroundParallaxOne_L0;
        sf::Vector2f _p_backgroundParallaxOne_L1;
        sf::Vector2f _p_backgroundParallaxOne_L2;
        sf::Vector2f _p_backgroundParallaxOne_L3;
        sf::Vector2f _p_backgroundParallaxOne_L4;
        sf::Vector2f _p_backgroundParallaxOne_L5;
        sf::Vector2f _p_backgroundParallaxOne_L6;
        sf::Vector2f _p_backgroundParallaxOne_L7;

        sf::Vector2f _p_playerLife;
        sf::Vector2f _p_powerCharge;
        sf::Vector2f _p_powerChargeBar;

        sf::IntRect _playerShipRect;

        //Clocks
        sf::Clock _playerShipClock;
        sf::Clock _backgroundClock_L1;
        sf::Clock _backgroundClock_L2;
        sf::Clock _backgroundClock_L3;

        sf::Clock _c_backgroundParallaxOne_L0;
        sf::Clock _c_backgroundParallaxOne_L1;
        sf::Clock _c_backgroundParallaxOne_L2;
        sf::Clock _c_backgroundParallaxOne_L3;
        sf::Clock _c_backgroundParallaxOne_L4;
        sf::Clock _c_backgroundParallaxOne_L5;
        sf::Clock _c_backgroundParallaxOne_L6;
        sf::Clock _c_backgroundParallaxOne_L7;

        sf::Clock _c_powerCharge;
        
    public:

        enumState _gameState;

        //PLAYER 2
        Position _posPlayer2;
        sf::CircleShape _shapePlayer2;

        Position _posPlayer3;
        sf::CircleShape _shapePlayer3;

        Position _posPlayer1;
        sf::CircleShape _shapePlayer1;
        
        bool _waiting;

        Graphics &operator=(const Graphics &);
        Assets _assets;
        WindowManaging _windowManager;
        sf::Vector2i _mousePos;
        bool _mouseClick;

        Graphics();
        ~Graphics();

        void initGraphics();
        void initPlayerShip();
        void initUi();

        void draw(sf::Sprite sprite);
        void clear();
        void display();

        void drawUi();

        //Player Methods
        void drawPlayer();
        void playerSetPos();

        void playerRight();
        void playerLeft();
        void playerUp();
        void playerDown();
        void playerImmobile();
        
        void playerHit();
        void playerFire();

        void drawOtherPlayer();

        //Background Methods
        void initBackground();
        void drawBackground();
        void backgroundSetPos();

        void initParallaxBgOne();
        void drawParallaxBgOne();
        void parallaxBgOneSetPos();
};