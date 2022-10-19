//
// Created by Gabriel de Taxis on 27/09/2022.
//

#ifndef B_CPP_500_MAR_5_1_RTYPE_GABRIEL_DE_TAXIS_DU_POET_WINDOWMANAGING_H
#define B_CPP_500_MAR_5_1_RTYPE_GABRIEL_DE_TAXIS_DU_POET_WINDOWMANAGING_H

#include <string>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


#include "PlayerControlSystem.hpp"


class Network{
    public:
    Network();
    ~Network();
    bool ConnexionReady(enumState);
    void Send_Udp_Paquet(Position, int, bool, ManagerAction);


    std::string _host;
    std::string _port;
    asio::io_context _io_context;

    asio::ip::udp::socket *_socket;

    asio::ip::udp::resolver *_resolver;
    asio::ip::udp::resolver::results_type _endpoints;
    // void networkLoop(void *);
};

class WindowManaging {

public:
   
    WindowManaging();
    ~WindowManaging();
    void initWindow(std::string const& windowTitle, int windowWidth, int windowHeight);
    bool isRunning();
    void pollEvent();
    void doingAllTheTests();
    void gameBackground();

    sf::RenderWindow _window;
    // bool _Z;
    // bool _Q;
    // bool _S;
    // bool _D;
    bool _mouseClick;
    sf::Vector2i _mousePos;
    int _nbPlayer;
    sf::Event event;
    int _nbAction;
    int _NumberYouAre;


    void Update();
    Bullet initBulletShape(Position);
    int UpdateBullet(int);
    void finishBullet(int);
    void bulletManager();

    int UpdateUltiBullet(int, int);
    // void finishUltiBullet(int);
    void UltiBulletManager();

    Player *_player;
    Monster *_monster;
    Network *_network;
    Position _pos;
    std::bitset<8> mButtons;
    bool _action;
    Direction _direction;
    ManagerAction _ManagerAction;
    sf::CircleShape _shape;
    std::vector<Bullet*> _tabOfBullet;
    std::vector<UltimateBullets*> _TabOfUltimateBullets;

    int _level;
    sf::Clock Clock;
    WindowManaging &operator=(const WindowManaging &);
private:

};


#endif //B_CPP_500_MAR_5_1_RTYPE_GABRIEL_DE_TAXIS_DU_POET_WINDOWMANAGING_H
