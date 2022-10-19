#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cstdlib>
#include <cstring>
#include <SFML/Audio.hpp>
#include <bitset>
#include <string>
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <sstream>
#include "asio.hpp"

#define WINDOW_WIDTH 1400
#define WINDOW_HEIGHT 800

enum { max_length = 1024 };
// #include "Systems/BulletControlSystem.hpp"

enum enumInput { Z, Q, S, D, ESC };
enum Direction{Top = 0, Right = 1, Bot = 2, Left = 3, Nop = -1};
enum ManagerAction{Move = 0, Shoot = 1, Ulti = 2};
// enum Level{LvL1 = 1, LvL2 = 2, LvL3 = 3, LvL4 = 4, LvL5 = 5};
enum BulletDir{TopRightRight = 0, TopMid = 1, TopRight = 2, BotRightRight = 3, BotMid = 4, BotRight = 5, RRight = 6, Nothing = 7};
enum enumState { MENU, MENU_SETTINGS, MENU_AUDIO, MENU_VIDEO, ROOM, GAME, PAUSE, SETTINGS, CINEMATIC };

struct Position
{
//    sf::Vector3f pos(int x, int y);
    float x;
    float y;
    float z;
};


///
/// In charge of managing every asset in the game.
///
class Assets
{
private:
    
    
public:
    Assets();
    ~Assets();
    
    void initAssets();
    void loadTexture();
    void loadSprite();
    void loadBgParallaxTexture();
    void loadBgParallaxSprite();
    void setScales();
    void setRects();


    sf::Texture _t_background_L1;
    sf::Texture _t_background_L2;
    sf::Texture _t_background_L3;
    sf::Texture _t_playerShip;
    sf::Texture _t_bgButton;
    sf::Texture _t_bgMenu;
    sf::Texture _t_bgparallax_0;
    sf::Texture _t_bgparallax_1;
    sf::Texture _t_bgparallax_2;
    sf::Texture _t_bgparallax_3;
    sf::Texture _t_bgparallax_4;
    sf::Texture _t_bgparallax_5;
    sf::Texture _t_bgparallax_6;
    sf::Texture _t_bgparallax_7;

    sf::Texture _t_powerChargeBar;
    sf::Texture _t_powerCharge;
    sf::Texture _t_playerLife;



    sf::Sprite _s_playerShip;
    sf::Sprite _s_background_L1;
    sf::Sprite _s_background_L2;
    sf::Sprite _s_background_L3;
    sf::Sprite _s_bgButton;
    sf::Sprite _s_bgMenu;
    sf::Sprite _s_bgparallax_0;
    sf::Sprite _s_bgparallax_1;
    sf::Sprite _s_bgparallax_2;
    sf::Sprite _s_bgparallax_3;
    sf::Sprite _s_bgparallax_4;
    sf::Sprite _s_bgparallax_5;
    sf::Sprite _s_bgparallax_6;
    sf::Sprite _s_bgparallax_7;

    sf::Sprite _s_bgparallax_0_0;
    sf::Sprite _s_bgparallax_0_1;
    sf::Sprite _s_bgparallax_0_2;
    sf::Sprite _s_bgparallax_0_3;
    sf::Sprite _s_bgparallax_0_4;
    sf::Sprite _s_bgparallax_0_5;
    sf::Sprite _s_bgparallax_0_6;
    sf::Sprite _s_bgparallax_0_7;

    sf::Sprite _s_powerChargeBar;
    sf::Sprite _s_powerCharge;
    sf::Sprite _s_playerLife;

    sf::IntRect _r_playerLife;
    sf::IntRect _r_powerCharge;
    sf::IntRect _r_powerChargeBar;
};