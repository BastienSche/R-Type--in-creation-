//
// Created by Gabriel de Taxis on 27/09/2022.
//

#ifndef B_CPP_500_MAR_5_1_RTYPE_GABRIEL_DE_TAXIS_DU_POET_BUTTON_H
#define B_CPP_500_MAR_5_1_RTYPE_GABRIEL_DE_TAXIS_DU_POET_BUTTON_H

#include "WindowManaging.h"

class Button {
public:
    void Init(Assets assets, sf::Vector2f winSize,sf::RenderWindow* window, std::string text);
    bool onHover(sf::Vector2i mousePos, bool mouseClick);


    void setBtnPos(sf::Vector2f pos);
    void drawBtn();
    
private:
    Assets _assets;
    sf::RenderWindow* _window;
    sf::Font _font;
    sf::Text _text;
    sf::Vector2f _pos;

    sf::Texture _t_btnBg;
    sf::Sprite _s_btnBg;
    sf::IntRect _r_btnBg;

    int _xSize;
    int _ySize;
    float _winWidth;
    float _winHeight;
    float _scaleX;
    float _scaleY;
};


#endif //B_CPP_500_MAR_5_1_RTYPE_GABRIEL_DE_TAXIS_DU_POET_BUTTON_H
