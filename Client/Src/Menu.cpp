#include "../Includes/Menu.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}

///
/// Init menu
///
void Menu::initMenu(sf::RenderWindow* window, Assets assets, sf::Vector2i mousePos, bool mouseClick)
{
    _assets = assets;
    _window = window;
    _mousePos = mousePos;
    _mouseClick = mouseClick;
    //Load textures / sprites etc ..
    //Init pos for each buttons
    // _p_menuBackground = sf::Vector2f(0, 0);
    // _t_menuBackground.loadFromFile("Assets/menuBackground.png");
    // _s_menuBackground.setTexture(_t_menuBackground, false);
    // _s_menuBackground.setPosition(_p_menuBackground);
}

///
/// Draw menu BackGround
///
void Menu::drawMenuBackground()
{
    _assets._s_bgMenu.setPosition(0,0);
    _window->draw(_assets._s_bgMenu);
}

///
/// EnumStates MAIN MENU \n
/// Returns the gameState based on what is clicked
///
enumState Menu::mainMenu()
{
    Button playBtn;
    Button settingsBtn;
    Button exitBtn;

    // drawMenuBackground();

    playBtn.Init(_assets, sf::Vector2f(1920, 1080), _window ,"Play");
    playBtn.setBtnPos(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
    if (playBtn.onHover(_mousePos, _mouseClick)){
        return ROOM;
    }
    playBtn.drawBtn();

    settingsBtn.Init(_assets, sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT), _window, "Settings");
    settingsBtn.setBtnPos(sf::Vector2f(WINDOW_WIDTH / 2, (WINDOW_HEIGHT / 2 + 100)));
    if (settingsBtn.onHover(_mousePos, _mouseClick)){
        return SETTINGS;
    }
    settingsBtn.drawBtn();

    exitBtn.Init(_assets, sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT), _window, "Exit");
    exitBtn.setBtnPos(sf::Vector2f(WINDOW_WIDTH / 2, (WINDOW_HEIGHT / 2 + 200)));
    if (exitBtn.onHover(_mousePos, _mouseClick)){
        exit(0);
    }
    exitBtn.drawBtn();

    return MENU;
}

///
/// EnumStates SETTING MENU \n
/// Returns the gameState based on what is clicked
///
enumState Menu::settingsMenu()
{
    Button audioBtn;
    Button videoBtn;
    Button backbutton;

    drawMenuBackground();

    audioBtn.Init(_assets, sf::Vector2f(1920, 1080), _window ,"Audio settings");
    audioBtn.setBtnPos(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
    if (audioBtn.onHover(_mousePos, _mouseClick)){
        return MENU_AUDIO;
    }
    audioBtn.drawBtn();

    videoBtn.Init(_assets, sf::Vector2f(1920, 1080), _window ,"Video settings");
    videoBtn.setBtnPos(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
    if (videoBtn.onHover(_mousePos, _mouseClick)){
        return MENU_VIDEO;
    }
    videoBtn.drawBtn();

    backbutton.Init(_assets, sf::Vector2f(1920, 1080), _window ,"Audio");
    backbutton.setBtnPos(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
    if (backbutton.onHover(_mousePos, _mouseClick)){
        return MENU;
    }
    backbutton.drawBtn();

    return MENU_SETTINGS;
}

///
/// EnumStates ROOM menu \n
/// Returns the gameState based on what is clicked
///
enumState Menu::roomMenu()
{
    return GAME;
}
