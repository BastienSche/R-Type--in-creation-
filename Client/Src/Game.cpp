// //
// // Created by Gabriel de Taxis on 27/09/2022.
// //

// #include "../Includes/Game.h"

// using asio::ip::udp;

// ///
// /// Init Game
// ///
// void Game::Init()
// {
//     _graphics.initGraphics();
//     _gameState = MENU;
//     _winWidth = _graphics._windowManager._window.getSize().x;
//     _winHeight = _graphics._windowManager._window.getSize().y;
//     //This will move to SoundManager class
//     // sf::Music music;
//     // if (!music.openFromFile("Assets/Music/DOS2_EraOfGlory.ogg"))
//     //     std::cerr << "Error loading music" <<std::endl;
//     // music.play();
//     gameLoop();
// }

// ///
// /// Draws the game.\n
// ///
// void Game::drawGame()
// {
//     if (_graphics._windowManager._nbPlayer == 2 && _graphics._windowManager._NumberYouAre == 1) {
//         _graphics._shapePlayer2.setRadius(40.f);
//         _graphics._shapePlayer2.setFillColor(sf::Color::White);
//         _graphics._shapePlayer2.setPosition(_graphics._posPlayer2.x, _graphics._posPlayer2.y);
//         _graphics._windowManager._window.draw(_graphics._shapePlayer2);
//         // std::cout << "Draw OKOOKOKOKOKOKOKOKOKOKOKOKOOKOKOKOKOKOKOKOK" << std::endl;
//     } else if (_graphics._windowManager._nbPlayer == 2 && _graphics._windowManager._NumberYouAre == 2) {
//         _graphics._shapePlayer1.setRadius(40.f);
//         _graphics._shapePlayer1.setFillColor(sf::Color::White);
//         _graphics._shapePlayer1.setPosition(_graphics._posPlayer1.x, _graphics._posPlayer1.y);
//         _graphics._windowManager._window.draw(_graphics._shapePlayer1);
//         // std::cout << "Draw OKOOKOKOKOKOKOKOKOKOKOKOKOOKOKOKOKOKOKOKOK" << std::endl;
//     } else if (_graphics._windowManager._nbPlayer == 3 && _graphics._windowManager._NumberYouAre == 1) {
//         _graphics._shapePlayer2.setRadius(40.f);
//         _graphics._shapePlayer2.setFillColor(sf::Color::White);
//         _graphics._shapePlayer2.setPosition(_graphics._posPlayer2.x, _graphics._posPlayer2.y);
//         _graphics._windowManager._window.draw(_graphics._shapePlayer2);
        
//         _graphics._shapePlayer3.setRadius(40.f);
//         _graphics._shapePlayer3.setFillColor(sf::Color::Green);
//         _graphics._shapePlayer3.setPosition(_graphics._posPlayer3.x, _graphics._posPlayer3.y);
//         _graphics._windowManager._window.draw(_graphics._shapePlayer3);
//         // std::cout << "Draw OKOOKOKOKOKOKOKOKOKOKOKOKOOKOKOKOKOKOKOKOK" << std::endl;
//     } else if (_graphics._windowManager._nbPlayer == 3 && _graphics._windowManager._NumberYouAre == 2) {
//         _graphics._shapePlayer1.setRadius(40.f);
//         _graphics._shapePlayer1.setFillColor(sf::Color::White);
//         _graphics._shapePlayer1.setPosition(_graphics._posPlayer1.x, _graphics._posPlayer1.y);
//         _graphics._windowManager._window.draw(_graphics._shapePlayer1);
        
//         _graphics._shapePlayer3.setRadius(40.f);
//         _graphics._shapePlayer3.setFillColor(sf::Color::Green);
//         _graphics._shapePlayer3.setPosition(_graphics._posPlayer3.x, _graphics._posPlayer3.y);
//         _graphics._windowManager._window.draw(_graphics._shapePlayer3);
//         // std::cout << "Draw OKOOKOKOKOKOKOKOKOKOKOKOKOOKOKOKOKOKOKOKOK" << std::endl;
//     }  else if (_graphics._windowManager._nbPlayer == 3 && _graphics._windowManager._NumberYouAre == 3) {
//         _graphics._shapePlayer1.setRadius(40.f);
//         _graphics._shapePlayer1.setFillColor(sf::Color::White);
//         _graphics._shapePlayer1.setPosition(_graphics._posPlayer1.x, _graphics._posPlayer1.y);
//         _graphics._windowManager._window.draw(_graphics._shapePlayer1);
        
//         _graphics._shapePlayer2.setRadius(40.f);
//         _graphics._shapePlayer2.setFillColor(sf::Color::Green);
//         _graphics._shapePlayer2.setPosition(_graphics._posPlayer2.x, _graphics._posPlayer2.y);
//         _graphics._windowManager._window.draw(_graphics._shapePlayer2);
//         // std::cout << "Draw OKOOKOKOKOKOKOKOKOKOKOKOKOOKOKOKOKOKOKOKOK" << std::endl;
//     }
//     _graphics._windowManager._player->UpdatePLayer(_graphics._windowManager._action, _graphics._windowManager._direction);
//     _graphics._windowManager._monster->HandleMonster();
//     _graphics._windowManager._monster->UpdateMonster();
//     _graphics._windowManager._tabOfBullet = _graphics._windowManager._monster->CheckCollision(_graphics._windowManager._tabOfBullet);
//     for (int i = 0; i < _graphics._windowManager._TabOfUltimateBullets.size(); i++) {
//         _graphics._windowManager._TabOfUltimateBullets.at(i)->_TabOfUltimateBullet = _graphics._windowManager._monster->CheckUltiCollision(_graphics._windowManager._TabOfUltimateBullets.at(i)->_TabOfUltimateBullet);
//         // std::cout << "i : " << i << std::endl;
//     }
//     _graphics._windowManager._level = _graphics._windowManager._monster->CheckStatus();
//     _graphics._windowManager.Update();
// }

// Graphics &Graphics::operator=(const Graphics &source)
// {
//     _windowManager = source._windowManager;
//     return *this;
// }


// bool Network::ConnexionReady(enumState gameState)
// {
//     std::cout << "Waiting..." << std::endl;
//     std::cout << "GameState2 : " <<gameState<< std::endl;
//     if (gameState == ROOM){
//         char *request = "Connexion::Ready::2";
//         size_t request_length = std::strlen(request);
//         _socket->send_to(asio::buffer(request, request_length), *_endpoints.begin());
//         return false;
//     }
//     return true;
// }

// void Network::Send_Udp_Paquet(Position posPlayer, int numberYouAre, bool action, ManagerAction managerAction)
// {
//     // char Sender[max_length];
//     // char PosX[max_length];
//     // char PosY[max_length];
//     // char numberAre[max_length];

//     // snprintf(PosX, max_length, "%.2f", posPlayer.x);
//     // snprintf(PosY, max_length, "%.2f", posPlayer.y);
//     // snprintf(numberAre, max_length, "%d", numberYouAre);

//     // std::strcat(Sender, "Pos(");
//     // std::strcat(Sender, numberAre);
//     // std::strcat(Sender, ")::");
//     // std::strcat(Sender, PosX);
//     // std::strcat(Sender, ";");
//     // std::strcat(Sender, PosY);
//     // std::strcat(Sender, "|");
//     // if (action == true && managerAction == Shoot) {
//     //     std::strcat(Sender, "Act(");
//     //     std::strcat(Sender, numberAre);
//     //     std::strcat(Sender, ")::Space");
//     //     // graphics->_windowManager._nbAction--;
//     // } else {
//     //     std::strcat(Sender, "Act(");
//     //     std::strcat(Sender, numberAre);
//     //     std::strcat(Sender, ")::Nothing");
//     // }
//     // _socket->send_to(asio::buffer(Sender, std::strlen(Sender)), *_endpoints.begin());   
//     // std::memset(&Sender, '\0', max_length);
//     // std::memset(&PosX, '\0', max_length);
//     // std::memset(&PosY, '\0', max_length);
// }

// ///
// /// Network Loop
// ///
// void networkLoop(void *UserData)
// {
//     Graphics* graphics = static_cast<Graphics*>(UserData);
//     int LIFE = 10;
//         std::cout << "Waiting..." << std::endl;
//         while (graphics->_windowManager._network->ConnexionReady(graphics->_gameState)){
//         }
//         char reply[max_length];
//         udp::endpoint sender_endpoint;
//         size_t reply_length;
//         sf::Clock clockshooting;
//         for(;reply_length = graphics->_windowManager._network->_socket->receive_from(asio::buffer(reply, max_length), sender_endpoint);) {
        
//         char request2[max_length];
        
//         std::cout << "Reply is " << reply << std::endl;

//         std::string o, tmp; 
//         std::stringstream ss(reply);
//         std::vector<std::string> TabOfCommande;

//         std::string reply_string(reply);

//         while(getline(ss, tmp, '|')){
//             TabOfCommande.push_back(tmp);
//         }
        
//         for (int aa=0; aa < TabOfCommande.size(); aa++) {
//             std::cout << "TAB " << aa << " :" << TabOfCommande.at(aa) << std::endl;
//         }

//         for (int number = 0; number < TabOfCommande.size(); number++) {
//             std::string temp(TabOfCommande.at(number));
//             std::string _commande;
//             std::string NumberYouAre;
//             std::string _pos;
//             int l = 0;
//             int mob = 0;
//             for (size_t i = 0; i < temp.size(); i++) {
//                 if (temp.at(i) ==  ':') {
//                     l++;
//                 } else if (temp.at(i) != ':' && l == 0) {
//                     _commande.push_back(temp.at(i));
//                 } else if (temp.at(i) != ':' && l == 2) {
//                     _pos.push_back(temp.at(i));
//                 } else if (temp.at(i) != ':' && l == 4) {
//                     NumberYouAre.push_back(temp.at(i));
//                 }
//             }
//             std::cout << "Pos : " << _pos << std::endl;
//             size_t found = _pos.find("Space");
//             if (_commande == "Connexion") {
//                 int iter;
//                 std::string arg(_pos);
//                 std::cout << "ARG : " << arg << std::endl;
//                 if (arg == "1") {
//                     graphics->_waiting = false;
//                     graphics->_windowManager._nbPlayer = 1;
//                 } else if (arg == "2") {
//                     graphics->_waiting = false;
//                     graphics->_windowManager._nbPlayer = 2;
//                 } else if (arg == "3") {
//                     graphics->_waiting = false;
//                     graphics->_windowManager._nbPlayer = 3;
//                 }
//                 std::cout << "NB YOU ARE : "<<NumberYouAre << std::endl;
//                 if (NumberYouAre == "1") {
//                     graphics->_windowManager._NumberYouAre = 1;
//                 } else if (NumberYouAre == "2") {
//                     graphics->_windowManager._NumberYouAre = 2;
//                 } else if (NumberYouAre == "3") {
//                     graphics->_windowManager._NumberYouAre = 3;
//                 }
//             } else if (_commande == "Pos(2)" && graphics->_windowManager._NumberYouAre == 1 ||_commande == "Pos(2)" && graphics->_windowManager._NumberYouAre == 3 ) {
//                 std::string _posX;
//                 std::string _posY;
//                 int nbb = 0;
//                 for (size_t ll = 0;ll < _pos.size(); ll++) {
//                     if (_pos.at(ll) == ';') {
//                         nbb++;
//                     } else if (_pos.at(ll) != ';' && nbb == 0) {
//                         _posX.push_back(_pos.at(ll));
//                     } else if (_pos.at(ll) != ';' && nbb == 1) {
//                         _posY.push_back(_pos.at(ll));
//                     }
//                 }
//                 graphics->_posPlayer2.x = std::atof(_posX.c_str());
//                 graphics->_posPlayer2.y = std::atof(_posY.c_str());
//             } else if (_commande == "Pos(3)" && graphics->_windowManager._NumberYouAre == 1 || _commande == "Pos(3)" && graphics->_windowManager._NumberYouAre == 2 ) {
//                 std::string _posX;
//                 std::string _posY;
//                 int nbb = 0;
//                 for (size_t ll = 0;ll < _pos.size(); ll++) {
//                     if (_pos.at(ll) == ';') {
//                         nbb++;
//                     } else if (_pos.at(ll) != ';' && nbb == 0) {
//                         _posX.push_back(_pos.at(ll));
//                     } else if (_pos.at(ll) != ';' && nbb == 1) {
//                         _posY.push_back(_pos.at(ll));
//                     }
//                 }
//                 graphics->_posPlayer3.x = std::atof(_posX.c_str());
//                 graphics->_posPlayer3.y = std::atof(_posY.c_str());
//             } else if (_commande == "Pos(1)" && graphics->_windowManager._NumberYouAre == 2 || _commande == "Pos(1)" && graphics->_windowManager._NumberYouAre == 3 ) {
//                 std::string _posX;
//                 std::string _posY;
//                 int nbb = 0;
//                 for (size_t ll = 0;ll < _pos.size(); ll++) {
//                     if (_pos.at(ll) == ';') {
//                         nbb++;
//                     } else if (_pos.at(ll) != ';' && nbb == 0) {
//                         _posX.push_back(_pos.at(ll));
//                     } else if (_pos.at(ll) != ';' && nbb == 1) {
//                         _posY.push_back(_pos.at(ll));
//                     }
//                 }
//                 graphics->_posPlayer1.x = std::atof(_posX.c_str());
//                 graphics->_posPlayer1.y = std::atof(_posY.c_str());
//             } else if (_commande == "Act(1)" && graphics->_windowManager._NumberYouAre == 1 && (found!=std::string::npos) && clockshooting.getElapsedTime().asMilliseconds() >= 200) {
//             } else if (_commande == "Act(2)" && graphics->_windowManager._NumberYouAre == 1 && (found!=std::string::npos) && clockshooting.getElapsedTime().asMilliseconds() >= 200) {
//                 // graphics->_windowManager.

//                 std::cout << "the Space key was pressed" << std::endl;
//                 clockshooting.restart();
//                 Bullet *bullet = new Bullet(graphics->_posPlayer2);
//                 graphics->_windowManager._tabOfBullet.push_back(bullet);
//             } else if (_commande == "Act(3)" && graphics->_windowManager._NumberYouAre == 1 && (found!=std::string::npos) && clockshooting.getElapsedTime().asMilliseconds() >= 200) {
//                 // graphics->_windowManager.

//                 std::cout << "the Space key was pressed" << std::endl;
//                 clockshooting.restart();
//                 Bullet *bullet = new Bullet(graphics->_posPlayer3);
//                 graphics->_windowManager._tabOfBullet.push_back(bullet);
//             } else if (_commande == "Act(1)" && graphics->_windowManager._NumberYouAre == 2 && (found!=std::string::npos) && clockshooting.getElapsedTime().asMilliseconds() >= 200) {
//                 // graphics->_windowManager.

//                 std::cout << "the Space key was pressed" << std::endl;
//                 clockshooting.restart();
//                 Bullet *bullet = new Bullet(graphics->_posPlayer1);
//                 graphics->_windowManager._tabOfBullet.push_back(bullet);
//             } else if (_commande == "Act(2)" && graphics->_windowManager._NumberYouAre == 2 && (found!=std::string::npos) && clockshooting.getElapsedTime().asMilliseconds() >= 200) {
//             } else if (_commande == "Act(3)" && graphics->_windowManager._NumberYouAre == 2 && (found!=std::string::npos) && clockshooting.getElapsedTime().asMilliseconds() >= 200) {
//                 // graphics->_windowManager.

//                 std::cout << "the Space key was pressed" << std::endl;
//                 clockshooting.restart();
//                 Bullet *bullet = new Bullet(graphics->_posPlayer3);
//                 graphics->_windowManager._tabOfBullet.push_back(bullet);
//             } else if (_commande == "Act(1)" && graphics->_windowManager._NumberYouAre == 3 && (found!=std::string::npos) && clockshooting.getElapsedTime().asMilliseconds() >= 200) {
//                 // graphics->_windowManager.

//                 std::cout << "the Space key was pressed" << std::endl;
//                 clockshooting.restart();
//                 Bullet *bullet = new Bullet(graphics->_posPlayer1);
//                 graphics->_windowManager._tabOfBullet.push_back(bullet);
//             } else if (_commande == "Act(2)" && graphics->_windowManager._NumberYouAre == 3 && (found!=std::string::npos) && clockshooting.getElapsedTime().asMilliseconds() >= 200) {
//                 // graphics->_windowManager.

//                 std::cout << "the Space key was pressed" << std::endl;
//                 clockshooting.restart();
//                 Bullet *bullet = new Bullet(graphics->_posPlayer2);
//                 graphics->_windowManager._tabOfBullet.push_back(bullet);
//             } else if (_commande == "Act(3)" && graphics->_windowManager._NumberYouAre == 3 && (found!=std::string::npos) && clockshooting.getElapsedTime().asMilliseconds() >= 200) {
//             }
//         //-----------------------------------------
//         // graphics->_windowManager._network->Send_Udp_Paquet(graphics->_windowManager._player->_posPlayer, graphics->_windowManager._NumberYouAre, graphics->_windowManager._action, graphics->_windowManager._ManagerAction);
//             char Sender[max_length];
//             char PosX[max_length];
//             char PosY[max_length];
//             char numberAre[max_length];

//             snprintf(PosX, max_length, "%.2f", graphics->_windowManager._player->_posPlayer.x);
//             snprintf(PosY, max_length, "%.2f", graphics->_windowManager._player->_posPlayer.y);
//             snprintf(numberAre, max_length, "%d", graphics->_windowManager._NumberYouAre);

//             std::strcat(Sender, "Pos(");
//             std::strcat(Sender, numberAre);
//             std::strcat(Sender, ")::");
//             std::strcat(Sender, PosX);
//             std::strcat(Sender, ";");
//             std::strcat(Sender, PosY);
//             std::strcat(Sender, "|");
//             if (graphics->_windowManager._action == true && graphics->_windowManager._ManagerAction == Shoot) {
//                 std::strcat(Sender, "Act(");
//                 std::strcat(Sender, numberAre);
//                 std::strcat(Sender, ")::Space");
//                 // graphics->_windowManager._nbAction--;
//             } else {
//                 std::strcat(Sender, "Act(");
//                 std::strcat(Sender, numberAre);
//                 std::strcat(Sender, ")::Nothing");
//             }
//             graphics->_windowManager._network->_socket->send_to(asio::buffer(Sender, std::strlen(Sender)), *graphics->_windowManager._network->_endpoints.begin());   
//             std::memset(&Sender, '\0', max_length);
//             std::memset(&PosX, '\0', max_length);
//             std::memset(&PosY, '\0', max_length);
//             //-----------------------------------------
//             TabOfCommande.clear();
//         }
//     }
// }


// ///
// /// Main loop for the game.\n
// /// Clears screen, draws everything.
// ///
// void Game::gameLoop()
// {
//     // Network *network = new Network(&_graphics);
//     sf::Thread thread(&networkLoop, &_graphics);
//     thread.launch();
//     float dt = 0.0f;
//     while (_graphics._windowManager.isRunning()) {
//     // std::cout << "LIFE NO" << _graphics._windowManager._monster->_PlayerLife << std::endl;
//         _graphics._windowManager._window.setFramerateLimit(40);
//         auto startTime = std::chrono::high_resolution_clock::now();
//         _graphics._windowManager.pollEvent(); // A FINIR

//         _graphics._gameState = _gameState;

//         _graphics._windowManager._window.clear();


//         if (_gameState == MENU){
//             _graphics.drawParallaxBgOne();
//             drawMainMenu();
//             _graphics._waiting = true;

//         } else if (_gameState == MENU_SETTINGS){
//             drawSettingsMenu();
//         } else if (_gameState == MENU_AUDIO){

//         } else if (_gameState == MENU_VIDEO){


//         } else if (_gameState == ROOM){
//             _graphics.drawParallaxBgOne();
//             if (_graphics._waiting == false){
//                 _gameState = GAME;
//             }
//         } else if (_gameState == GAME){
//             drawGame();
//         }

//         // sf::Time elapsed1 = _clock.getElapsedTime();
//         // std::cout << elapsed1.asSeconds() << std::endl;

//         _graphics._windowManager._window.display();
//         auto stopTime = std::chrono::high_resolution_clock::now();
//         dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
//     }
// }

// ///
// /// Draws game background.
// ///
// void Game::gameBackground()
// {
//     _graphics.drawBackground();
// }

// ///
// /// Draws main menu.
// ///
// void Game::drawMainMenu()
// {
//     Menu mainMenu;
//     mainMenu.initMenu(&_graphics._windowManager._window, _graphics._assets, _graphics._windowManager._mousePos, _graphics._windowManager._mouseClick);
//     _gameState = mainMenu.mainMenu();
// }

// void Game::drawRoom()
// {
//     Menu roomMenu;
//     roomMenu.initMenu(&_graphics._windowManager._window, _graphics._assets, _graphics._windowManager._mousePos, _graphics._windowManager._mouseClick);
//     _gameState = roomMenu.roomMenu();
// }

// ///
// /// Draws settings menu.
// ///
// void Game::drawSettingsMenu()
// {
//     Menu settingsMenu;
//     settingsMenu.initMenu(&_graphics._windowManager._window, _graphics._assets, _graphics._windowManager._mousePos, _graphics._windowManager._mouseClick);
//     // _gameState = settingsMenu
// }

// ///
// /// Stores current window size in _winWidth and _winHeight from Game class.
// ///
// void Game::getWinSize()
// {
//     _winWidth = _graphics._windowManager._window.getSize().x;
//     _winHeight = _graphics._windowManager._window.getSize().y;
// }
//
// Created by Gabriel de Taxis on 27/09/2022.
//

#include "../Includes/Game.h"

using asio::ip::udp;

///
/// Init Game
///
void Game::Init()
{
    _graphics.initGraphics();
    _gameState = MENU;
    _winWidth = _graphics._windowManager._window.getSize().x;
    _winHeight = _graphics._windowManager._window.getSize().y;
    //This will move to SoundManager class
    // sf::Music music;
    // if (!music.openFromFile("Assets/Music/DOS2_EraOfGlory.ogg"))
    //     std::cerr << "Error loading music" <<std::endl;
    // music.play();
    gameLoop();
}

///
/// Draws the game.\n
///
void Game::drawGame()
{
    if (_graphics._windowManager._nbPlayer == 2 && _graphics._windowManager._NumberYouAre == 1) {
        _graphics._shapePlayer2.setRadius(40.f);
        _graphics._shapePlayer2.setFillColor(sf::Color::White);
        _graphics._shapePlayer2.setPosition(_graphics._posPlayer2.x, _graphics._posPlayer2.y);
        _graphics._windowManager._window.draw(_graphics._shapePlayer2);
        // std::cout << "Draw OKOOKOKOKOKOKOKOKOKOKOKOKOOKOKOKOKOKOKOKOK" << std::endl;
    } else if (_graphics._windowManager._nbPlayer == 2 && _graphics._windowManager._NumberYouAre == 2) {
        _graphics._shapePlayer1.setRadius(40.f);
        _graphics._shapePlayer1.setFillColor(sf::Color::White);
        _graphics._shapePlayer1.setPosition(_graphics._posPlayer1.x, _graphics._posPlayer1.y);
        _graphics._windowManager._window.draw(_graphics._shapePlayer1);
        // std::cout << "Draw OKOOKOKOKOKOKOKOKOKOKOKOKOOKOKOKOKOKOKOKOK" << std::endl;
    } else if (_graphics._windowManager._nbPlayer == 3 && _graphics._windowManager._NumberYouAre == 1) {
        _graphics._shapePlayer2.setRadius(40.f);
        _graphics._shapePlayer2.setFillColor(sf::Color::White);
        _graphics._shapePlayer2.setPosition(_graphics._posPlayer2.x, _graphics._posPlayer2.y);
        _graphics._windowManager._window.draw(_graphics._shapePlayer2);
        
        _graphics._shapePlayer3.setRadius(40.f);
        _graphics._shapePlayer3.setFillColor(sf::Color::Green);
        _graphics._shapePlayer3.setPosition(_graphics._posPlayer3.x, _graphics._posPlayer3.y);
        _graphics._windowManager._window.draw(_graphics._shapePlayer3);
        // std::cout << "Draw OKOOKOKOKOKOKOKOKOKOKOKOKOOKOKOKOKOKOKOKOK" << std::endl;
    } else if (_graphics._windowManager._nbPlayer == 3 && _graphics._windowManager._NumberYouAre == 2) {
        _graphics._shapePlayer1.setRadius(40.f);
        _graphics._shapePlayer1.setFillColor(sf::Color::White);
        _graphics._shapePlayer1.setPosition(_graphics._posPlayer1.x, _graphics._posPlayer1.y);
        _graphics._windowManager._window.draw(_graphics._shapePlayer1);
        
        _graphics._shapePlayer3.setRadius(40.f);
        _graphics._shapePlayer3.setFillColor(sf::Color::Green);
        _graphics._shapePlayer3.setPosition(_graphics._posPlayer3.x, _graphics._posPlayer3.y);
        _graphics._windowManager._window.draw(_graphics._shapePlayer3);
        // std::cout << "Draw OKOOKOKOKOKOKOKOKOKOKOKOKOOKOKOKOKOKOKOKOK" << std::endl;
    }  else if (_graphics._windowManager._nbPlayer == 3 && _graphics._windowManager._NumberYouAre == 3) {
        _graphics._shapePlayer1.setRadius(40.f);
        _graphics._shapePlayer1.setFillColor(sf::Color::White);
        _graphics._shapePlayer1.setPosition(_graphics._posPlayer1.x, _graphics._posPlayer1.y);
        _graphics._windowManager._window.draw(_graphics._shapePlayer1);
        
        _graphics._shapePlayer2.setRadius(40.f);
        _graphics._shapePlayer2.setFillColor(sf::Color::Green);
        _graphics._shapePlayer2.setPosition(_graphics._posPlayer2.x, _graphics._posPlayer2.y);
        _graphics._windowManager._window.draw(_graphics._shapePlayer2);
        // std::cout << "Draw OKOOKOKOKOKOKOKOKOKOKOKOKOOKOKOKOKOKOKOKOK" << std::endl;
    }
    _graphics._windowManager._player->UpdatePLayer(_graphics._windowManager._action, _graphics._windowManager._direction);
    _graphics._windowManager._monster->HandleMonster();
    _graphics._windowManager._monster->UpdateMonster();
    _graphics._windowManager._tabOfBullet = _graphics._windowManager._monster->CheckCollision(_graphics._windowManager._tabOfBullet);
    for (int i = 0; i < _graphics._windowManager._TabOfUltimateBullets.size(); i++) {
        _graphics._windowManager._TabOfUltimateBullets.at(i)->_TabOfUltimateBullet = _graphics._windowManager._monster->CheckUltiCollision(_graphics._windowManager._TabOfUltimateBullets.at(i)->_TabOfUltimateBullet);
        // std::cout << "i : " << i << std::endl;
    }
    _graphics._windowManager._level = _graphics._windowManager._monster->CheckStatus();
    _graphics._windowManager.Update();
}

Graphics &Graphics::operator=(const Graphics &source)
{
    _windowManager = source._windowManager;
    return *this;
}


///
/// Network Loop
///
void networkLoop(void *UserData)
{
    Graphics* graphics = static_cast<Graphics*>(UserData);
    int LIFE = 10;

        std::cout << "Waiting..." << std::endl;
        while (1){
            if (graphics->_gameState == ROOM){
                char *request = "Connexion::Ready::2";
                size_t request_length = std::strlen(request);
                graphics->_windowManager._network->_socket->send_to(asio::buffer(request, request_length), *graphics->_windowManager._network->_endpoints.begin());
                break;
            }
        }
        char reply[max_length];
        udp::endpoint sender_endpoint;
        size_t reply_length;

    sf::Clock clockshooting;
    for(;reply_length = graphics->_windowManager._network->_socket->receive_from(asio::buffer(reply, max_length), sender_endpoint);) {

        char request2[max_length];
        // std::cout << "Reply is: ";
        // std::cout.write(reply, reply_length);
        // std::cout << "\n";
        
        // std::cout << "Reply is " << reply << std::endl;

        std::string o, tmp; 
        std::stringstream ss(reply);
        std::vector<std::string> TabOfCommande;

        std::string reply_string(reply);

        while(getline(ss, tmp, '|')){
            TabOfCommande.push_back(tmp);
        }
        
        for (int aa=0; aa < TabOfCommande.size(); aa++) {
            // std::cout << "TAB " << aa << " :" << TabOfCommande.at(aa) << std::endl;
        }
        // std::string delimiter = "::";
        // std::string commande = reply_string.substr(0, reply_string.find(delimiter)); // token is "scott"
        // std::cout << std::endl;
        // std::cout << "Commande : " << commande << std::endl;
        // std::cout << std::endl;
        // std::cout << "RESTE : " << reply_string << std::endl;
        // std::cout << std::endl;
        // std::cout << "String cut : " << reply_string << " Commande : " << commande << std::endl;

        for (int number = 0; number < TabOfCommande.size(); number++) {
            std::string temp(TabOfCommande.at(number));
            std::string _commande;
            std::string NumberYouAre;
            std::string _pos;
            int l = 0;
            int mob = 0;
            for (size_t i = 0; i < temp.size(); i++) {
                if (temp.at(i) ==  ':') {
                    l++;
                } else if (temp.at(i) != ':' && l == 0) {
                    _commande.push_back(temp.at(i));
                } else if (temp.at(i) != ':' && l == 2) {
                    _pos.push_back(temp.at(i));
                } else if (temp.at(i) != ':' && l == 4) {
                    NumberYouAre.push_back(temp.at(i));
                }
            }
            // std::cout << "Pos : " << _pos << std::endl;
            size_t found = _pos.find("Space");
            if (_commande == "Connexion") {
                int iter;
                std::string arg(_pos);
                // for (size_t ll = 0;ll < _pos.size(); ll++) {
                //     arg.push_back(_pos.at(ll));
                // }
                // for (size_t ll = 0;ll < _pos.size(); ll++) {
                //     if (_pos.at(ll) == ':') {
                //         iter++;
                //     } else if (_pos.at(ll) != ':' && iter == 0) {
                //         arg.push_back(_pos.at(ll));
                //     } else if (_pos.at(ll) != ':' && iter == 2) {
                //         NumberYouAre.push_back(_pos.at(ll));
                //     }
                // }
                // std::cout << "ARG : " << arg << std::endl;
                if (arg == "1") {
                    graphics->_waiting = false;
                    graphics->_windowManager._nbPlayer = 1;
                } else if (arg == "2") {
                    graphics->_waiting = false;
                    graphics->_windowManager._nbPlayer = 2;
                } else if (arg == "3") {
                    graphics->_waiting = false;
                    graphics->_windowManager._nbPlayer = 3;
                }
                // std::cout << "NB YOU ARE : "<<NumberYouAre << std::endl;
                if (NumberYouAre == "1") {
                    graphics->_windowManager._NumberYouAre = 1;
                } else if (NumberYouAre == "2") {
                    graphics->_windowManager._NumberYouAre = 2;
                } else if (NumberYouAre == "3") {
                    graphics->_windowManager._NumberYouAre = 3;
                }
            } else if (_commande == "Pos(1)" && graphics->_windowManager._NumberYouAre == 1 ) { 
            } else if (_commande == "Pos(2)" && graphics->_windowManager._NumberYouAre == 1 ) {
                std::string _posX;
                std::string _posY;
                int nbb = 0;
                for (size_t ll = 0;ll < _pos.size(); ll++) {
                    if (_pos.at(ll) == ';') {
                        nbb++;
                    } else if (_pos.at(ll) != ';' && nbb == 0) {
                        _posX.push_back(_pos.at(ll));
                    } else if (_pos.at(ll) != ';' && nbb == 1) {
                        _posY.push_back(_pos.at(ll));
                    }
                }
                graphics->_posPlayer2.x = std::atof(_posX.c_str());
                graphics->_posPlayer2.y = std::atof(_posY.c_str());
            } else if (_commande == "Pos(3)" && graphics->_windowManager._NumberYouAre == 1 ) {
                std::string _posX;
                std::string _posY;
                int nbb = 0;
                for (size_t ll = 0;ll < _pos.size(); ll++) {
                    if (_pos.at(ll) == ';') {
                        nbb++;
                    } else if (_pos.at(ll) != ';' && nbb == 0) {
                        _posX.push_back(_pos.at(ll));
                    } else if (_pos.at(ll) != ';' && nbb == 1) {
                        _posY.push_back(_pos.at(ll));
                    }
                }
                graphics->_posPlayer3.x = std::atof(_posX.c_str());
                graphics->_posPlayer3.y = std::atof(_posY.c_str());
            } else if (_commande == "Pos(1)" && graphics->_windowManager._NumberYouAre == 2 ) {
                std::string _posX;
                std::string _posY;
                int nbb = 0;
                for (size_t ll = 0;ll < _pos.size(); ll++) {
                    if (_pos.at(ll) == ';') {
                        nbb++;
                    } else if (_pos.at(ll) != ';' && nbb == 0) {
                        _posX.push_back(_pos.at(ll));
                    } else if (_pos.at(ll) != ';' && nbb == 1) {
                        _posY.push_back(_pos.at(ll));
                    }
                }
                graphics->_posPlayer1.x = std::atof(_posX.c_str());
                graphics->_posPlayer1.y = std::atof(_posY.c_str());
            } else if (_commande == "Pos(2)" && graphics->_windowManager._NumberYouAre == 2 ) {
            } else if (_commande == "Pos(3)" && graphics->_windowManager._NumberYouAre == 2 ) {
                std::string _posX;
                std::string _posY;
                int nbb = 0;
                for (size_t ll = 0;ll < _pos.size(); ll++) {
                    if (_pos.at(ll) == ';') {
                        nbb++;
                    } else if (_pos.at(ll) != ';' && nbb == 0) {
                        _posX.push_back(_pos.at(ll));
                    } else if (_pos.at(ll) != ';' && nbb == 1) {
                        _posY.push_back(_pos.at(ll));
                    }
                }
                graphics->_posPlayer3.x = std::atof(_posX.c_str());
                graphics->_posPlayer3.y = std::atof(_posY.c_str());
            } else if (_commande == "Pos(1)" && graphics->_windowManager._NumberYouAre == 3 ) {
                std::string _posX;
                std::string _posY;
                int nbb = 0;
                for (size_t ll = 0;ll < _pos.size(); ll++) {
                    if (_pos.at(ll) == ';') {
                        nbb++;
                    } else if (_pos.at(ll) != ';' && nbb == 0) {
                        _posX.push_back(_pos.at(ll));
                    } else if (_pos.at(ll) != ';' && nbb == 1) {
                        _posY.push_back(_pos.at(ll));
                    }
                }
                graphics->_posPlayer1.x = std::atof(_posX.c_str());
                graphics->_posPlayer1.y = std::atof(_posY.c_str());
            } else if (_commande == "Pos(2)" && graphics->_windowManager._NumberYouAre == 3 ) {
                std::string _posX;
                std::string _posY;
                int nbb = 0;
                for (size_t ll = 0;ll < _pos.size(); ll++) {
                    if (_pos.at(ll) == ';') {
                        nbb++;
                    } else if (_pos.at(ll) != ';' && nbb == 0) {
                        _posX.push_back(_pos.at(ll));
                    } else if (_pos.at(ll) != ';' && nbb == 1) {
                        _posY.push_back(_pos.at(ll));
                    }
                }
                graphics->_posPlayer2.x = std::atof(_posX.c_str());
                graphics->_posPlayer2.y = std::atof(_posY.c_str());
            } else if (_commande == "Pos(3)" && graphics->_windowManager._NumberYouAre == 3 ) {
            } else if (_commande == "Act(1)" && graphics->_windowManager._NumberYouAre == 1 && (found!=std::string::npos) && clockshooting.getElapsedTime().asMilliseconds() >= 200) {
            } else if (_commande == "Act(2)" && graphics->_windowManager._NumberYouAre == 1 && (found!=std::string::npos) && clockshooting.getElapsedTime().asMilliseconds() >= 200) {
                // graphics->_windowManager.

                std::cout << "the Space key was pressed" << std::endl;
                clockshooting.restart();
                Bullet *bullet = new Bullet(graphics->_posPlayer2);
                graphics->_windowManager._tabOfBullet.push_back(bullet);
            } else if (_commande == "Act(3)" && graphics->_windowManager._NumberYouAre == 1 && (found!=std::string::npos) && clockshooting.getElapsedTime().asMilliseconds() >= 200) {
                // graphics->_windowManager.

                std::cout << "the Space key was pressed" << std::endl;
                clockshooting.restart();
                Bullet *bullet = new Bullet(graphics->_posPlayer3);
                graphics->_windowManager._tabOfBullet.push_back(bullet);
            } else if (_commande == "Act(1)" && graphics->_windowManager._NumberYouAre == 2 && (found!=std::string::npos) && clockshooting.getElapsedTime().asMilliseconds() >= 200) {
                // graphics->_windowManager.

                std::cout << "the Space key was pressed" << std::endl;
                clockshooting.restart();
                Bullet *bullet = new Bullet(graphics->_posPlayer1);
                graphics->_windowManager._tabOfBullet.push_back(bullet);
            } else if (_commande == "Act(2)" && graphics->_windowManager._NumberYouAre == 2 && (found!=std::string::npos) && clockshooting.getElapsedTime().asMilliseconds() >= 200) {
            } else if (_commande == "Act(3)" && graphics->_windowManager._NumberYouAre == 2 && (found!=std::string::npos) && clockshooting.getElapsedTime().asMilliseconds() >= 200) {
                // graphics->_windowManager.

                std::cout << "the Space key was pressed" << std::endl;
                clockshooting.restart();
                Bullet *bullet = new Bullet(graphics->_posPlayer3);
                graphics->_windowManager._tabOfBullet.push_back(bullet);
            } else if (_commande == "Act(1)" && graphics->_windowManager._NumberYouAre == 3 && (found!=std::string::npos) && clockshooting.getElapsedTime().asMilliseconds() >= 200) {
                // graphics->_windowManager.

                std::cout << "the Space key was pressed" << std::endl;
                clockshooting.restart();
                Bullet *bullet = new Bullet(graphics->_posPlayer1);
                graphics->_windowManager._tabOfBullet.push_back(bullet);
            } else if (_commande == "Act(2)" && graphics->_windowManager._NumberYouAre == 3 && (found!=std::string::npos) && clockshooting.getElapsedTime().asMilliseconds() >= 200) {
                // graphics->_windowManager.

                std::cout << "the Space key was pressed" << std::endl;
                clockshooting.restart();
                Bullet *bullet = new Bullet(graphics->_posPlayer2);
                graphics->_windowManager._tabOfBullet.push_back(bullet);
            } else if (_commande == "Act(3)" && graphics->_windowManager._NumberYouAre == 3 && (found!=std::string::npos) && clockshooting.getElapsedTime().asMilliseconds() >= 200) {
            }
            // std::cout << "ARG : " << arg <<  " NUMBER ARE : " << graphics->_windowManager._NumberYouAre << std::endl;
            // } else if (_commande == "Pos3" && graphics->_windowManager._nbPlayer == 3) {
            //     std::string _posX;
            //     std::string _posY;
            //     int nbb = 0;
            //     for (size_t ll = 0;ll < _pos.size(); ll++) {
            //         if (_pos.at(ll) == ';') {
            //             nbb++;
            //         } else if (_pos.at(ll) != ';' && nbb == 0) {
            //             _posX.push_back(_pos.at(ll));
            //         } else if (_pos.at(ll) != ';' && nbb == 1) {
            //             _posY.push_back(_pos.at(ll));
            //         }
            //     }
            //     graphics->_posPlayer2.x = std::atof(_posX.c_str());
            //     graphics->_posPlayer2.y = std::atof(_posY.c_str());
            // } else if (_commande == "Action3" && (found!=std::string::npos) && clockshooting.getElapsedTime().asMilliseconds() >= 200&& graphics->_windowManager._nbPlayer == 3) {
            //     // graphics->_windowManager.

            //     std::cout << "the Space key was pressed" << std::endl;
            //     clockshooting.restart();
            //     Bullet *bullet = new Bullet(graphics->_posPlayer2);
            //     graphics->_windowManager._tabOfBullet.push_back(bullet);
            // }
        }
            // } else if (_commande == "Action") {
            //     // graphics->_windowManager.

            //     std::cout << "the Space key was pressed" << std::endl;
            //     Bullet *bullet = new Bullet(graphics->_posPlayer2);
            //     graphics->_windowManager._tabOfBullet.push_back(bullet);
            // }
            // } else if (_commande == "Mob") {
            //     std::string _posXMob;
            //     std::string _posYMob;
            //     int nbb = 0;
            //     for (size_t ll = 0;ll < _pos.size(); ll++) {
            //         if (_pos.at(ll) == ';') {
            //             nbb++;
            //         } else if (_pos.at(ll) != ';' && nbb == 0) {
            //             _posXMob.push_back(_pos.at(ll));
            //         } else if (_pos.at(ll) != ';' && nbb == 1) {
            //             _posYMob.push_back(_pos.at(ll));
            //         }
            //     }
            //     graphics->_windowManager._monster->_TabOfMob1.at(number-1)->_posMob1.x = std::atof(_posXMob.c_str());
            //     graphics->_windowManager._monster->_TabOfMob1.at(number-1)->_posMob1.y = std::atof(_posYMob.c_str());
            // }


        // std::cout << std::endl;
        // std::cout << "Commande : " << _commande << std::endl;
        // std::cout << std::endl;
        // std::cout << "Pos  : " << _pos << std::endl;
        // std::cout << std::endl;
        // std::cout << "PosX  : " << _posX << " et PosY : " <<_posY<< std::endl;
        // std::cout << std::endl;

        //-----------------------------------------

            char Sender[max_length];
            char PosX[max_length];
            char PosY[max_length];
            char numberAre[max_length];

            snprintf(PosX, max_length, "%.2f", graphics->_windowManager._player->_posPlayer.x);
            snprintf(PosY, max_length, "%.2f", graphics->_windowManager._player->_posPlayer.y);
            snprintf(numberAre, max_length, "%d", graphics->_windowManager._NumberYouAre);

            std::strcat(Sender, "Pos(");
            std::strcat(Sender, numberAre);
            std::strcat(Sender, ")::");
            std::strcat(Sender, PosX);
            std::strcat(Sender, ";");
            std::strcat(Sender, PosY);
            std::strcat(Sender, "|");
            if (graphics->_windowManager._action == true && graphics->_windowManager._ManagerAction == Shoot) {
                std::strcat(Sender, "Act(");
                std::strcat(Sender, numberAre);
                std::strcat(Sender, ")::Space");
                // graphics->_windowManager._nbAction--;
            } else {
                std::strcat(Sender, "Act(");
                std::strcat(Sender, numberAre);
                std::strcat(Sender, ")::Nothing");
            }
            graphics->_windowManager._network->_socket->send_to(asio::buffer(Sender, std::strlen(Sender)), *graphics->_windowManager._network->_endpoints.begin());   
            std::memset(&Sender, '\0', max_length);
            std::memset(&PosX, '\0', max_length);
            std::memset(&PosY, '\0', max_length);
            //-----------------------------------------
            TabOfCommande.clear();
    }
}

///
/// Main loop for the game.\n
/// Clears screen, draws everything.
///
void Game::gameLoop()
{
    // Network *network = new Network(&_graphics);
    sf::Thread thread(&networkLoop, &_graphics);
    thread.launch();
    float dt = 0.0f;
    while (_graphics._windowManager.isRunning()) {
    // std::cout << "LIFE NO" << _graphics._windowManager._monster->_PlayerLife << std::endl;
        _graphics._windowManager._window.setFramerateLimit(40);
        auto startTime = std::chrono::high_resolution_clock::now();
        _graphics._windowManager.pollEvent(); // A FINIR

        _graphics._gameState = _gameState;

        _graphics._windowManager._window.clear();


        if (_gameState == MENU){
            _graphics.drawParallaxBgOne();
            drawMainMenu();
            _graphics._waiting = true;

        } else if (_gameState == MENU_SETTINGS){
            drawSettingsMenu();
        } else if (_gameState == MENU_AUDIO){

        } else if (_gameState == MENU_VIDEO){


        } else if (_gameState == ROOM){
            _graphics.drawParallaxBgOne();
            if (_graphics._waiting == false){
                _gameState = GAME;
            }
        } else if (_gameState == GAME){
            _graphics.drawParallaxBgOne();
            drawGame();
            _graphics.drawUi();
        }

        // sf::Time elapsed1 = _clock.getElapsedTime();
        // std::cout << elapsed1.asSeconds() << std::endl;

        _graphics._windowManager._window.display();
        auto stopTime = std::chrono::high_resolution_clock::now();
        dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
    }
}

///
/// Draws game background.
///
void Game::gameBackground()
{
    _graphics.drawBackground();
}

///
/// Draws main menu.
///
void Game::drawMainMenu()
{
    Menu mainMenu;
    mainMenu.initMenu(&_graphics._windowManager._window, _graphics._assets, _graphics._windowManager._mousePos, _graphics._windowManager._mouseClick);
    _gameState = mainMenu.mainMenu();
}

void Game::drawRoom()
{
    Menu roomMenu;
    roomMenu.initMenu(&_graphics._windowManager._window, _graphics._assets, _graphics._windowManager._mousePos, _graphics._windowManager._mouseClick);
    _gameState = roomMenu.roomMenu();
}

///
/// Draws settings menu.
///
void Game::drawSettingsMenu()
{
    Menu settingsMenu;
    settingsMenu.initMenu(&_graphics._windowManager._window, _graphics._assets, _graphics._windowManager._mousePos, _graphics._windowManager._mouseClick);
    // _gameState = settingsMenu
}

///
/// Stores current window size in _winWidth and _winHeight from Game class.
///
void Game::getWinSize()
{
    _winWidth = _graphics._windowManager._window.getSize().x;
    _winHeight = _graphics._windowManager._window.getSize().y;
}