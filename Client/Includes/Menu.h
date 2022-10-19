#include "Button.h"

class Menu
{
    private:
        sf::Texture _t_menuBackground;

        sf::Sprite _s_menuBackground;

        sf::Vector2f _p_menuBackground;
        

    public:
        Assets _assets;
        sf::RenderWindow* _window;
        sf::Vector2i _mousePos;
        bool _mouseClick;
        enumState _gameState;

        Menu();
        ~Menu();
        void initMenu(sf::RenderWindow* window, Assets assets, sf::Vector2i mousePos, bool mouseClick);

        enumState mainMenu();
        enumState settingsMenu();
        enumState roomMenu();

        void drawMenuBackground();
};