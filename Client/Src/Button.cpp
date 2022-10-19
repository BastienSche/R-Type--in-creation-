//
// Created by Gabriel de Taxis on 27/09/2022.
//

#include "../Includes/Button.h"

void Button::Init(Assets assets, sf::Vector2f winSize,sf::RenderWindow* window, std::string text)
{
    if (!_font.loadFromFile("Assets/arial.ttf"))
    {
        std::cerr << "Error loading font" << std::endl;
    }
    if (!_t_btnBg.loadFromFile("Assets/raft/btnBG.png"))
    {
        std::cerr << "Error loading texture" <<std::endl;
    }

    _text.setString(text);
    _text.setFont(_font);
    _text.setCharacterSize(36);
    _text.setFillColor(sf::Color::Red);
    _text.setStyle(sf::Text::Bold);

    _assets = assets;
    _window = window;
    _winWidth = winSize.x;
    _winHeight = winSize.y;

    _s_btnBg.setTexture(_t_btnBg);

    sf::Vector2f spriteOrigin = sf::Vector2f(_s_btnBg.getGlobalBounds().width/2, _s_btnBg.getGlobalBounds().height/2);
    sf::Vector2f textOrigin = sf::Vector2f(_text.getGlobalBounds().width/2, _text.getGlobalBounds().height/2);

    _s_btnBg.setOrigin(spriteOrigin);
    _text.setOrigin(textOrigin);


    // createButton();
}

///
/// Sets the position of a button.
///
void Button::setBtnPos(sf::Vector2f pos)
{
    _text.setPosition(pos);
    _s_btnBg.setPosition(pos);
}

///
/// Draws button.
///
void Button::drawBtn()
{
    _window->draw(_s_btnBg);
    _window->draw(_text);
}

///
/// Returns true if button is clicked.\n
/// Can modify the appearance of a button on hover and on click.
///
bool Button::onHover(sf::Vector2i mousePos, bool mouseClick)
{
    //Test
    sf::Text mouseX;
    sf::Text mouseY;
    mouseX.setPosition(300, 100);
    mouseY.setPosition(500, 100);
    mouseX.setFont(_font);
    mouseY.setFont(_font);
    mouseX.setCharacterSize(24);
    mouseY.setCharacterSize(24);
    mouseX.setString("X = " + std::to_string(mousePos.x));
    mouseY.setString("Y = " + std::to_string(mousePos.y));
    _window->draw(mouseY);
    _window->draw(mouseX);
    //Test

    if (mousePos.x >= _s_btnBg.getPosition().x - (_s_btnBg.getGlobalBounds().width / 2)
    && mousePos.x <= ((_s_btnBg.getPosition().x - (_s_btnBg.getGlobalBounds().width / 2)) + _s_btnBg.getGlobalBounds().width)
    && mousePos.y >= _s_btnBg.getPosition().y - (_s_btnBg.getGlobalBounds().height / 2)
    && mousePos.y <= ((_s_btnBg.getPosition().y - (_s_btnBg.getGlobalBounds().height / 2))+ _s_btnBg.getGlobalBounds().height)) {
        _text.setFillColor(sf::Color::White);
        if (mouseClick) {
            _text.setFillColor(sf::Color::Green);
            return true;
        }
    } else {
        _text.setFillColor(sf::Color::Red);
    }
    return false;
}