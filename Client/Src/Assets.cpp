#include "../Includes/Assets.h"

Assets::Assets()
{
    
}

Assets::~Assets()
{

}

///
/// Initialize every asset
///
void Assets::initAssets()
{
    loadTexture();
    loadSprite();
    setRects();
    setScales();
}

///
/// Is in charge of loading every texture from files
///
void Assets::loadTexture()
{
    if (!_t_background_L1.loadFromFile("Assets/Backgrounds/Purple/T_PurpleBackground_Version1_Layer1.png"))
        std::cerr << "Error loading texture" <<std::endl;
    if (!_t_background_L2.loadFromFile("Assets/Backgrounds/Purple/T_PurpleBackground_Version1_Layer2.png"))
        std::cerr << "Error loading texture" <<std::endl;
    if (!_t_background_L3.loadFromFile("Assets/Backgrounds/Purple/T_PurpleBackground_Version1_Layer3.png"))
        std::cerr << "Error loading texture" <<std::endl;
    if (!_t_playerShip.loadFromFile("Assets/r-typesheet1.gif"))
        std::cerr << "Error loading texture" <<std::endl;
    if (!_t_bgButton.loadFromFile("Assets/raft/btnBG.png"))
        std::cerr << "Error loading texture" <<std::endl;
    if (!_t_bgMenu.loadFromFile("Assets/raft/BG.png"))
        std::cerr << "Error loading texture" <<std::endl;
    if (!_t_playerLife.loadFromFile("Assets/raft/LifesHeartsSprites.png"))
        std::cerr << "Error loading texture" <<std::endl;
    if (!_t_powerChargeBar.loadFromFile("Assets/raft/PowerChargeBar.png"))
        std::cerr << "Error loading texture" <<std::endl;
    if (!_t_powerCharge.loadFromFile("Assets/raft/PowerCharge.png"))
        std::cerr << "Error loading texture" <<std::endl;
    loadBgParallaxTexture();
}

void Assets::loadBgParallaxTexture()
{
    if (!_t_bgparallax_0.loadFromFile("Assets/Backgrounds/Other/bkgd_0.png"))
        std::cerr << "Error loading texture" <<std::endl;
    if (!_t_bgparallax_1.loadFromFile("Assets/Backgrounds/Other/bkgd_1.png"))
        std::cerr << "Error loading texture" <<std::endl;
    if (!_t_bgparallax_2.loadFromFile("Assets/Backgrounds/Other/bkgd_2.png"))
        std::cerr << "Error loading texture" <<std::endl;
    if (!_t_bgparallax_3.loadFromFile("Assets/Backgrounds/Other/bkgd_3.png"))
        std::cerr << "Error loading texture" <<std::endl;
    if (!_t_bgparallax_4.loadFromFile("Assets/Backgrounds/Other/bkgd_4.png"))
        std::cerr << "Error loading texture" <<std::endl;
    if (!_t_bgparallax_5.loadFromFile("Assets/Backgrounds/Other/bkgd_5.png"))
        std::cerr << "Error loading texture" <<std::endl;
    if (!_t_bgparallax_6.loadFromFile("Assets/Backgrounds/Other/bkgd_6.png"))
        std::cerr << "Error loading texture" <<std::endl;
    if (!_t_bgparallax_7.loadFromFile("Assets/Backgrounds/Other/bkgd_7.png"))
        std::cerr << "Error loading texture" <<std::endl;
}

///
/// Is in charge of loading every sprite from textures
///
void Assets::loadSprite()
{
    _s_background_L1.setTexture(_t_background_L1);
    _s_background_L2.setTexture(_t_background_L2);
    _s_background_L3.setTexture(_t_background_L3);
    
    _s_playerShip.setTexture(_t_playerShip);
    _s_bgButton.setTexture(_t_bgButton);
    _s_bgMenu.setTexture(_t_bgMenu);

    _s_playerLife.setTexture(_t_playerLife);
    _s_powerCharge.setTexture(_t_powerCharge);
    _s_powerChargeBar.setTexture(_t_powerChargeBar);

    loadBgParallaxSprite();
}

void Assets::loadBgParallaxSprite()
{
    _s_bgparallax_0.setTexture(_t_bgparallax_0);
    _s_bgparallax_1.setTexture(_t_bgparallax_1);
    _s_bgparallax_2.setTexture(_t_bgparallax_2);
    _s_bgparallax_3.setTexture(_t_bgparallax_3);
    _s_bgparallax_4.setTexture(_t_bgparallax_4);
    _s_bgparallax_5.setTexture(_t_bgparallax_5);
    _s_bgparallax_6.setTexture(_t_bgparallax_6);
    _s_bgparallax_7.setTexture(_t_bgparallax_7);
    
    _s_bgparallax_0_0.setTexture(_t_bgparallax_0);
    _s_bgparallax_0_1.setTexture(_t_bgparallax_1);
    _s_bgparallax_0_2.setTexture(_t_bgparallax_2);
    _s_bgparallax_0_3.setTexture(_t_bgparallax_3);
    _s_bgparallax_0_4.setTexture(_t_bgparallax_4);
    _s_bgparallax_0_5.setTexture(_t_bgparallax_5);
    _s_bgparallax_0_6.setTexture(_t_bgparallax_6);
    _s_bgparallax_0_7.setTexture(_t_bgparallax_7);
}

///
/// Set the rectangles for the sprites that need it\n 
/// For now : Lifebar, powerChargeBar, powerCharge
///
void Assets::setRects()
{
    //Height : 570 / 4 (143)
    _r_playerLife.left = 0;
    _r_playerLife.top = 0;
    _r_playerLife.width = 590;
    _r_playerLife.height = 143;
    _s_playerLife.setTextureRect(_r_playerLife);

    //108 aussi
    _r_powerCharge.left = 0;
    _r_powerCharge.top = 0;
    _r_powerCharge.width = 402;
    _r_powerCharge.height = 62;
    _s_powerCharge.setTextureRect(_r_powerCharge);

    //Height : 645 /  (108)
    _r_powerChargeBar.left = 0;
    _r_powerChargeBar.top = 0;
    _r_powerChargeBar.width = 450;
    _r_powerChargeBar.height = 108;
    _s_powerChargeBar.setTextureRect(_r_powerChargeBar);
}

void Assets::setScales()
{
    _s_playerLife.setScale(0.5, 0.5);
    _s_powerCharge.setScale(0.9, 0.9);
}