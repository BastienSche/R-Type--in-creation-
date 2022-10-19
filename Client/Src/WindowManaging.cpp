//
// Created by Gabriel de Taxis on 27/09/2022.
//

#include "../Includes/WindowManaging.h"

///
/// Constructeur Network
///
Network::Network()
{
    // networkLoop();
    _host = "127.0.0.1";
    _port = "3335";
    _socket = new asio::ip::udp::socket(_io_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), 0));
    _resolver = new asio::ip::udp::resolver(_io_context);
    _endpoints = _resolver->resolve(asio::ip::udp::v4(), _host, _port);

    //_io_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), 0))

}

///
/// Destructeur bullet
///
Network::~Network()
{

}

WindowManaging::WindowManaging()
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

WindowManaging::~WindowManaging()
{

}

///
/// Init Window
///
void WindowManaging::initWindow(std::string const& windowTitle, int windowWidth, int windowHeight)
{
    _window.create(sf::VideoMode(windowWidth, windowHeight), windowTitle, sf::Style::Default);
    _window.setKeyRepeatEnabled( true );
    _level = 1;
    _player = new Player();
    _monster = new Monster(_level);
    _nbPlayer = 1;
    _nbAction = 0;
    _network = new Network();
}

///
/// Check if is Running
///
bool WindowManaging::isRunning()
{
    if (_window.isOpen()){
        return true;
    }
    return false;
}

///
/// Handle for Event
///
void WindowManaging::pollEvent()
{
    _mousePos = sf::Mouse::getPosition(_window);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        _mouseClick = true;
    } else {
        _mouseClick = false;
    }
    while(_window.pollEvent(event)){
        if (event.type == sf::Event::Closed){
            _window.close();
        }
        if (event.type == sf::Event::KeyPressed){
            bool buttonStateChanged = true;
            _action = true;
            if (event.key.code == sf::Keyboard::Escape)
            {
                std::cout << "the escape key was pressed" << std::endl;
//                gCoordinator.SendEvent()
            } else if (event.key.code == sf::Keyboard::Z){
                std::cout << "the Z key was pressed" << std::endl;
                _direction = Top;
                _ManagerAction = Move;
            } else if (event.key.code == sf::Keyboard::Q){
                std::cout << "the Q key was pressed" << std::endl;
                _direction = Left;
                _ManagerAction = Move;
            } else if (event.key.code == sf::Keyboard::S){
                std::cout << "the S key was pressed" << std::endl;
                _direction = Bot;
                _ManagerAction = Move;
            } else if (event.key.code == sf::Keyboard::D){
                std::cout << "the D key was pressed" << std::endl;
                _direction = Right;
                _ManagerAction = Move;
            } else if (event.key.code == sf::Keyboard::R){
                std::cout << "the R key was pressed" << std::endl;
                _direction = Nop;
                _ManagerAction = Ulti;
                if (_monster->_UltiShootProgress >= 5) {
                    UltimateBullets *UltiBullets = new UltimateBullets(_player->_posPlayer);
                    _TabOfUltimateBullets.push_back(UltiBullets);
                    _monster->_UltiShootProgress = _monster->_UltiShootProgress - 5;
                }
            } else if (event.key.code == sf::Keyboard::Space){
                std::cout << "the Space key was pressed" << std::endl;
                _ManagerAction = Shoot;
                _direction = Nop;
                Bullet *bullet = new Bullet(_player->_posPlayer);
                _tabOfBullet.push_back(bullet);
            } else {
                _direction = Nop;
                std::cout << "a key was pressed" << std::endl;
            }

        }
        if (event.type == sf::Event::KeyReleased) {
            _action = false;
        }
            // char Sender[max_length];
            // char PosX[max_length];
            // char PosY[max_length];
            // char numberAre[max_length];

            // snprintf(PosX, max_length, "%.2f", _player->_posPlayer.x);
            // snprintf(PosY, max_length, "%.2f", _player->_posPlayer.y);
            // snprintf(numberAre, max_length, "%d", _NumberYouAre);

            // std::strcat(Sender, "Pos(");
            // std::strcat(Sender, numberAre);
            // std::strcat(Sender, ")::");
            // std::strcat(Sender, PosX);
            // std::strcat(Sender, ";");
            // std::strcat(Sender, PosY);
            // std::strcat(Sender, "|");
            // if (_ManagerAction == Shoot) {
            //     std::strcat(Sender, "Act(");
            //     std::strcat(Sender, numberAre);
            //     std::strcat(Sender, ")::Space");
            //     // graphics->_windowManager._nbAction--;
            // } else {
            //     std::strcat(Sender, "Act(");
            //     std::strcat(Sender, numberAre);
            //     std::strcat(Sender, ")::Nothing");
            // }
            // _network->_socket->send_to(asio::buffer(Sender, std::strlen(Sender)), *_network->_endpoints.begin());   
            // std::memset(&Sender, '\0', max_length);
            // std::memset(&PosX, '\0', max_length);
            // std::memset(&PosY, '\0', max_length);
    }
}

///
/// Test unitaire
///
void WindowManaging::doingAllTheTests()
{
    // sf::Vector2f size(50,50);

    // sf::RectangleShape rectZ(size);
    // sf::RectangleShape rectQ(size);
    // sf::RectangleShape rectS(size);
    // sf::RectangleShape rectD(size);

    // rectZ.setFillColor(sf::Color::White);
    // if (_Z){
    //     rectZ.setFillColor(sf::Color::Red);
    // }
    // rectQ.setFillColor(sf::Color::White);
    // if (_Q){
    //     rectQ.setFillColor(sf::Color::Red);
    // }
    // rectS.setFillColor(sf::Color::White);
    // if (_S){
    //     rectS.setFillColor(sf::Color::Red);
    // }
    // rectD.setFillColor(sf::Color::White);
    // if (_D){
    //     rectD.setFillColor(sf::Color::Red);
    // }


    // rectZ.setPosition(400.f, 400.f);
    // rectQ.setPosition(348.f, 452.f);
    // rectS.setPosition(400.f, 452.f);
    // rectD.setPosition(452.f, 452.f);

    // _window.draw(rectZ);
    // _window.draw(rectQ);
    // _window.draw(rectS);
    // _window.draw(rectD);
}


void WindowManaging::gameBackground()
{
    // _window.draw(_s_background);
}


///
/// Update bullet
///
int WindowManaging::UpdateBullet(int nb)
{
    if (_tabOfBullet.at(nb)->_posBullet.x >= 2000) {
        return (nb);
    }
    // HITBOX
    _tabOfBullet.at(nb)->_shapeBullet.setPosition(_tabOfBullet.at(nb)->_posBullet.x, _tabOfBullet.at(nb)->_posBullet.y);
    _window.draw(_tabOfBullet.at(nb)->_shapeBullet);
    _tabOfBullet.at(nb)->_posBullet.x = _tabOfBullet.at(nb)->_posBullet.x + 30.f;
    // std::cout << "pos n°" << nb << " : " << _tabOfBullet.at(nb)->_posBullet.x << std::endl;
    return (-1);
}

///
/// kill bulet
///
void WindowManaging::finishBullet(int nb)
{
    delete _tabOfBullet.at(nb);
    _tabOfBullet.erase(_tabOfBullet.begin() + nb);
}

//Window
///
/// Bullet Manager
///
void WindowManaging::bulletManager()
{
    std::vector<int> Remover;
    for(size_t nb = 0; nb < _tabOfBullet.size(); nb++) {
        // std::cout << "Bullet" << "nb :" << nb << std::endl;
        Remover.push_back(UpdateBullet(nb));
    }
    for(size_t nbRemover = 0; nbRemover < Remover.size(); nbRemover++) {
        if (Remover.at(nbRemover) != -1) {
            finishBullet(Remover.at(nbRemover));
        }
    }
}

///
/// Update Ultimate bullet
///
int WindowManaging::UpdateUltiBullet(int nb, int n)
{
    int ret = _TabOfUltimateBullets.at(nb)->_TabOfUltimateBullet.at(n)->CheckColissionsWall(); //Check Collision x>2000 et 0 < y < 1000

    _TabOfUltimateBullets.at(nb)->_TabOfUltimateBullet.at(n)->_shapeBullet.setPosition(_TabOfUltimateBullets.at(nb)->_TabOfUltimateBullet.at(n)->_posBullet.x \
    + _TabOfUltimateBullets.at(nb)->_TabOfUltimateBullet.at(n)->_shapeBullet.getGlobalBounds().width, _TabOfUltimateBullets.at(nb)->_TabOfUltimateBullet.at(n)->_posBullet.y \
    + _TabOfUltimateBullets.at(nb)->_TabOfUltimateBullet.at(n)->_shapeBullet.getGlobalBounds().height); //Set position

    if (_TabOfUltimateBullets.at(nb)->_TabOfUltimateBullet.at(n)->_Drawable == true) //Check si on doit draw le Bullet
        _window.draw(_TabOfUltimateBullets.at(nb)->_TabOfUltimateBullet.at(n)->_shapeBullet); //Draw le bullet

    _TabOfUltimateBullets.at(nb)->_TabOfUltimateBullet.at(n)->ManageDirectionBullet(n); // Redirection
    _TabOfUltimateBullets.at(nb)->_TabOfUltimateBullet.at(n)->UpdateDirectionBullet(); // Avance en fonction de direction
    return (ret);
}

///
/// Ultimate bullet Manager
///
void WindowManaging::UltiBulletManager()
{
    struct Gestion {size_t x; size_t y;};
    std::vector<Gestion> Remover;
    for(size_t nb = 0; nb < _TabOfUltimateBullets.size(); nb++) {
        for(size_t n = 0; n < _TabOfUltimateBullets.at(nb)->_TabOfUltimateBullet.size(); n++) {
            int a;
            if ((a = UpdateUltiBullet(nb, n)) != -1) {
                _TabOfUltimateBullets.at(nb)->_TabOfUltimateBullet.at(n)->_Drawable = false;
            }
        }
    }
    for(size_t nb = 0, l = 0; nb < _TabOfUltimateBullets.size(); nb++) {
        for(size_t n = 0; n < _TabOfUltimateBullets.at(nb)->_TabOfUltimateBullet.size(); n++) {
            if (_TabOfUltimateBullets.at(nb)->_TabOfUltimateBullet.at(n)->_Drawable == false)
                l++;
        }
        if (l == 7) {
            delete _TabOfUltimateBullets.at(nb);
            _TabOfUltimateBullets.erase(_TabOfUltimateBullets.begin() + nb);
            nb--;
        }
    }
}

///
/// Update total
///
void WindowManaging::Update()
{
    _player->setPosition(); //SET POSITION _player
    for (int a = 0; a < _monster->_TabOfMob1.size(); a++) //TAb des mob1
        _monster->_TabOfMob1.at(a)->setPosition();  //SET position par position
    for (int n = 0; n < _monster->_TabOfBoss1.size(); n++)
        _monster->_TabOfBoss1.at(n)->setPosition();

    _monster->_textScore.setPosition(_window.getSize().x - _monster->_textScore.getLocalBounds().width - 50, _monster->_textScore.getLocalBounds().height);
    _window.draw(_monster->_textScore);

    _monster->_textWaves.setPosition(_window.getSize().x - _monster->_textWaves.getLocalBounds().width - 50, _monster->_textWaves.getLocalBounds().height + _monster->_textScore.getLocalBounds().height + 50);
    _window.draw(_monster->_textWaves);

    _monster->_textLife.setPosition(_window.getSize().x - _monster->_textLife.getLocalBounds().width - 50, _monster->_textLife.getLocalBounds().height + _monster->_textScore.getLocalBounds().height + _monster->_textWaves.getLocalBounds().height + 100);
    _window.draw(_monster->_textLife);

    _monster->_textShootProgress.setPosition(_window.getSize().x - _monster->_textShootProgress.getLocalBounds().width - 50, _monster->_textScore.getLocalBounds().height + _monster->_textWaves.getLocalBounds().height + _monster->_textLife.getLocalBounds().height + _monster->_textShootProgress.getGlobalBounds().height +  100);
    _window.draw(_monster->_textShootProgress);

    _window.draw(_player->_shapePlayer);

    for (int e = 0; e < _monster->_TabOfMob1.size(); e++)
        _window.draw(_monster->_TabOfMob1.at(e)->_shapeMob1);
    for (int b = 0; b < _monster->_TabOfBoss1.size(); b++)
        _window.draw(_monster->_TabOfBoss1.at(b)->_shapeBoss1);

    bulletManager();
    UltiBulletManager();
}

WindowManaging &WindowManaging::operator=(const WindowManaging &source)
{
    // _window = source._window;
    _mouseClick = source._mouseClick;
    _mousePos = source._mousePos;

    _player = source._player;
    _monster = source._monster;
    _pos = source._pos;
    mButtons = source.mButtons;
    _action = source._action;
    _direction = source._direction;
    _shape = source._shape;
    _tabOfBullet = source._tabOfBullet;
    _TabOfUltimateBullets = source._TabOfUltimateBullets;

    _level = source._level;
    Clock = source.Clock;
    return *this;
}