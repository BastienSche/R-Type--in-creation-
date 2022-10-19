//
// Created by Gabriel de Taxis on 27/09/2022.
//

#ifndef B_CPP_500_MAR_5_1_RTYPE_GABRIEL_DE_TAXIS_DU_POET_GAME_H
#define B_CPP_500_MAR_5_1_RTYPE_GABRIEL_DE_TAXIS_DU_POET_GAME_H

// #include "WindowManaging.h"
#include "Graphics.h"
#include <chrono>


// enum enumInput { Z, Q, S, D, ESC };

class Game {

public:
    void Init();
    void gameLoop();

    void gameBackground();
    void drawMainMenu();
    void drawSettingsMenu();
    void drawRoom();
    void drawGame();

    void getWinSize();
    // void networkLoop();

    void doingAllTheTests();
private:
    Graphics _graphics;
    enumState _gameState;
    float _winWidth;
    float _winHeight;

    sf::Clock _clock;
    std::vector<enumInput> _inputs;
};

#endif //B_CPP_500_MAR_5_1_RTYPE_GABRIEL_DE_TAXIS_DU_POET_GAME_H
