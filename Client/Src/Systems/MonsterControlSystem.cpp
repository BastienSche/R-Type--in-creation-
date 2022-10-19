#include "../../Includes/MonsterControlSystem.hpp"

///
/// Constructeur de Monster
///
Monster::Monster(int level)
{
    _level = level;
    _Score = 0;
    _PlayerLife = 5;
    _UltiShootProgress = 0;
}

///
/// Destructeur de Monster
///
Monster::~Monster()
{
}

///
/// Constructeur de Mob
///
Mob1::Mob1(Position pos)
{
    _shapeMob1.setRadius(40.f);
    _shapeMob1.setFillColor(sf::Color::Green);
    _posMob1.x = pos.x;
    _posMob1.y = pos.y;
    _SpawnPos = pos;
}

///
/// Destructeur de Mob
///
Mob1::~Mob1()
{
}

///
/// Constructeur de Boss
///
Boss1::Boss1(Position pos)
{
    _shapeBoss1.setRadius(70.f);
    _shapeBoss1.setFillColor(sf::Color::Yellow);
    _posBoss1.x = pos.x;
    _posBoss1.y = pos.y;
    _SpawnPos = pos;
    _life = 5;
}

///
/// Destructeur de Boss
///
Boss1::~Boss1()
{
}

///
/// Set Position of Mob
///
void Mob1::setPosition()
{
    _shapeMob1.setPosition(_posMob1.x, _posMob1.y);
}

///
/// Set Position of Boss
///
void Boss1::setPosition()
{
    _shapeBoss1.setPosition(_posBoss1.x, _posBoss1.y);
}

///
/// Generate rand Pile or Face for boss
///
int Boss1::SetupPileOuFace()
{
    std::default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distrib(1,2);
    int nb = distrib(re);
    return (nb);
}

///
/// Generate rand Pile or Face for mob
///
int Mob1::SetupPileOuFace()
{
    std::default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distrib(1,2);
    int nb = distrib(re);
    return (nb);
}


///
/// Update Position of Mob
///
void Mob1::UpdateMob1()
{
    float LimPosMax = _SpawnPos.y + 150;
    float LimPosMin = _SpawnPos.y - 150;
    float SpeedY = SPEED_MOB1 / 2;
    // int Rand = SetupPileOuFace();


    _posMob1.x = _posMob1.x - SPEED_MOB1;

    if (_posMob1.y == _SpawnPos.y) {      //STARTER RAND TOP
        _posMob1.y = _posMob1.y - SpeedY;
        _dir = Bot;
    }

    // if (_posMob1.y == _SpawnPos.y && Rand == 2) {      //STARTER RAND BOT
    //     _posMob1.y = _posMob1.y + SpeedY;
    //     _dir = Top;
    // }

    if (LimPosMin < _posMob1.y < _SpawnPos.y && _dir == Bot)        // EN BAS AND GO TO BOT
        _posMob1.y = _posMob1.y - SpeedY;
    if (LimPosMin < _posMob1.y < _SpawnPos.y && _dir == Top)        // EN BAS AND GO TO TOP
        _posMob1.y = _posMob1.y + SpeedY;

    if (_posMob1.y < LimPosMin) {      //TOO BOT
        _posMob1.y = _posMob1.y + SpeedY;
        _dir = Top;
    }

    if (LimPosMax < _posMob1.y < _SpawnPos.y && _dir == Bot)        //EN HAUT ET GO TO BOT
        _posMob1.y = _posMob1.y - SpeedY;
    if (LimPosMax < _posMob1.y < _SpawnPos.y && _dir == Top)        // EN BAS ET GO TO TOP
        _posMob1.y = _posMob1.y + SpeedY;

    if (_posMob1.y > LimPosMax) {      //TOO TOP
        _posMob1.y = _posMob1.y - SpeedY;
        _dir = Bot;
    }
}

///
/// Update position of Boss
///
void Boss1::UpdateBoss1()
{

    float LimPosMax = _SpawnPos.y + 300;
    float LimPosMin = _SpawnPos.y - 200;
    float SpeedY = SPEED_BOSS1 / 2;
    // int Rand = SetupPileOuFace();


    _posBoss1.x = _posBoss1.x - SPEED_BOSS1;

    if (_posBoss1.y == _SpawnPos.y) {      //STARTER RAND TOP
        _posBoss1.y = _posBoss1.y - SpeedY;
        _dir = Bot;
    }

    // if (_posBoss1.y == _SpawnPos.y && Rand == 2) {      //STARTER RAND BOT
    //     _posBoss1.y = _posBoss1.y + SpeedY;
    //     _dir = Top;
    // }

    if (LimPosMin < _posBoss1.y < _SpawnPos.y && _dir == Bot)        // EN BAS AND GO TO BOT
        _posBoss1.y = _posBoss1.y - SpeedY;
    if (LimPosMin < _posBoss1.y < _SpawnPos.y && _dir == Top)        // EN BAS AND GO TO TOP
        _posBoss1.y = _posBoss1.y + SpeedY;

    if (_posBoss1.y < LimPosMin) {      //TOO BOT
        _posBoss1.y = _posBoss1.y + SpeedY;
        _dir = Top;
    }

    if (LimPosMax < _posBoss1.y < _SpawnPos.y && _dir == Bot)        //EN HAUT ET GO TO BOT
        _posBoss1.y = _posBoss1.y - SpeedY;
    if (LimPosMax < _posBoss1.y < _SpawnPos.y && _dir == Top)        // EN BAS ET GO TO TOP
        _posBoss1.y = _posBoss1.y + SpeedY;

    if (_posBoss1.y > LimPosMax) {      //TOO TOP
        _posBoss1.y = _posBoss1.y - SpeedY;
        _dir = Bot;
    }
}

///
/// Updtae monster
///
void Monster::UpdateMonster()
{
    for (int i = 0; i < _TabOfMob1.size(); i++)
        _TabOfMob1.at(i)->UpdateMob1();
    for (int i = 0; i < _TabOfBoss1.size(); i++)
        _TabOfBoss1.at(i)->UpdateBoss1();
}

///
/// Setup random in fonction of clock;
///
int Monster::SetupRand(int a, int b)
{
    std::default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distrib(a,b);
    int nb = distrib(re);
    // std::cout << "NOMBRE = " << nb << std::endl;
    return (nb);
}


///
/// Luncher of Wave. Manager of mob and boss
///
void Monster::WaveLunch(int nMob1, int nBoss1)
{
    _actifWave = true;
    Position posMob;
    Position posBoss;
    // if (nMob1 > 0) {
    //     for (int n = 0, x = WINDOW_WIDTH; n < nMob1; n++, x=x+500) { // FAire un rand pour la pos Y
    //         posMob.x = x;
    //         posMob.y = SetupRand((0.1 * WINDOW_HEIGHT),(0.9 * WINDOW_HEIGHT));
    //         _TabOfMob1.push_back(new Mob1(posMob));
    //     }
    // }
    // if (nBoss1 > 0) {
    //     for (int n = 0, x = WINDOW_WIDTH + ((nMob1-1) * 500); n < nBoss1; n++, x=x+500) { // FAIRE un rand pour la pos Y
    //         posBoss.x = x;
    //         posBoss.y = SetupRand((0.3 * WINDOW_HEIGHT),(0.7 * WINDOW_HEIGHT));
    //         _TabOfBoss1.push_back(new Boss1(posBoss));
    //     }
    // }
    if (nMob1 > 0) {
        for (int n = 0, x = WINDOW_WIDTH; n < nMob1; n++, x=x+500) { // FAire un rand pour la pos Y
            posMob.x = x;
            posMob.y = WINDOW_HEIGHT/2;
            _TabOfMob1.push_back(new Mob1(posMob));
        }
    }
    if (nBoss1 > 0) {
        for (int n = 0, x = WINDOW_WIDTH + ((nMob1-1) * 500); n < nBoss1; n++, x=x+500) { // FAIRE un rand pour la pos Y
            posBoss.x = x;
            posBoss.y = WINDOW_HEIGHT/2;
            _TabOfBoss1.push_back(new Boss1(posBoss));
        }
    }
}

///
/// Handle monster
///
void Monster::HandleMonster()
{
    if (_actifWave == false) {
        if (_level == 1)
            WaveLunch(2, 1);
        if (_level == 2)
            WaveLunch(4, 2);
        if (_level == 3)
            WaveLunch(6, 3);
    }
}

///
/// kill mob
///
void Monster::FinishMob1(int nb)
{
    delete _TabOfMob1.at(nb);
    _TabOfMob1.erase(_TabOfMob1.begin() + nb);
    _Score++;
    _UltiShootProgress++;
}

///
/// kill boss
///
void Monster::FinishBoss1(int nb)
{
    delete _TabOfBoss1.at(nb);
    _TabOfBoss1.erase(_TabOfBoss1.begin() + nb);
    _Score++;
    _Score++;
    _UltiShootProgress++;
    _UltiShootProgress++;
}

///
/// kill bullet
///
void Monster::FinishBullet(int nb, TypeOfBullet type)
{
    if (type == BasiqueBullet) {
        delete _TabOfBullets.at(nb);
        _TabOfBullets.erase(_TabOfBullets.begin() + nb);
    } else if (type == UltiBullet) {
        // delete _TabOfBulletsUlti.at(nb);
        // _TabOfBulletsUlti.erase(_TabOfBulletsUlti.begin() + nb);

        // _TabOfBulletsUlti.at(nb)->_shapeBullet.setFillColor(sf::Color::Transparent);
            _TabOfBulletsUlti.at(nb)->_Drawable = false;
    }
}

///
/// Check variables
///
int Monster::CheckStatus()
{
    if (_TabOfMob1.size() == 0 && _TabOfBoss1.size() == 0) {
        _actifWave = false;
        _level++;
        return (_level);
    }
    if (!_font.loadFromFile("Assets/arial.ttf"))
    {
        std::cerr << ".Error while loading font" << std::endl;
    }

    sf::String str("Score :");
    std::stringstream sstream;
    sstream << _Score;
    str = str + sstream.str();
    _textScore.setString(str);
    _textScore.setFont(_font); // font est un sf::Font
    _textScore.setCharacterSize(60); // exprimée en pixels, pas en points !
    _textScore.setFillColor(sf::Color::Red);
    _textScore.setOrigin(0, _textScore.getLocalBounds().height);

    sf::String strs("Level :");
    std::stringstream sstreams;
    sstreams << _level;
    strs = strs + sstreams.str();
    _textWaves.setString(strs);
    _textWaves.setFont(_font); // font est un sf::Font
    _textWaves.setCharacterSize(60); // exprimée en pixels, pas en points !
    _textWaves.setFillColor(sf::Color::Red);
    _textWaves.setOrigin(0, _textWaves.getLocalBounds().height);

    sf::String strss("Vie :");
    std::stringstream sstreamss;
    sstreamss << _PlayerLife;
    strss = strss + sstreamss.str();
    _textLife.setString(strss);
    _textLife.setFont(_font); // font est un sf::Font
    _textLife.setCharacterSize(60); // exprimée en pixels, pas en points !
    _textLife.setFillColor(sf::Color::Red);
    _textLife.setOrigin(0, _textLife.getLocalBounds().height);

    sf::String strsss("Ultimate Progress:");
    std::stringstream sstreamsss;
    sstreamsss << _UltiShootProgress;
    strsss = strsss + sstreamsss.str();
    _textShootProgress.setString(strsss);
    _textShootProgress.setFont(_font); // font est un sf::Font
    _textShootProgress.setCharacterSize(60); // exprimée en pixels, pas en points !
    if (_UltiShootProgress >= 5)
        _textShootProgress.setFillColor(sf::Color::Yellow);
    else
        _textShootProgress.setFillColor(sf::Color::Red);
    _textShootProgress.setOrigin(0, _textShootProgress.getLocalBounds().height);
}

///
/// Collision og bullets
///
bool Monster::collisionOfBullets(Bullet* bullets, int i, TypeOfBullet TypeBullet)
{
    // std::cout << "okok1" << std::endl;
    // if (bullets->_shapeBullet.getFillColor() != sf::Color::Transparent) {
    if (bullets->_Drawable == true) {
        for (int a = 0; a < _TabOfMob1.size(); a++) {
                if (_TabOfMob1.at(a)->_shapeMob1.getGlobalBounds().intersects(bullets->_shapeBullet.getGlobalBounds())) {
                    // std::cout << "a : " << a << std::endl;
                    FinishMob1(a);
                    FinishBullet(i, TypeBullet);
                    return true;
                }
        }
        // std::cout << "okok2" << std::endl;
        for (int b = 0; b < _TabOfBoss1.size(); b++) {
            if (_TabOfBoss1.at(b)->_shapeBoss1.getGlobalBounds().intersects(bullets->_shapeBullet.getGlobalBounds())) {
                if (_TabOfBoss1.at(b)->_life == 0) {
                    FinishBoss1(b);
                    FinishBullet(i, TypeBullet);
                    return true;
                }
                else
                    _TabOfBoss1.at(b)->_life--;
                    FinishBullet(i, TypeBullet);
                    return true;
            }
        }
    }
    // std::cout << "okok3" << std::endl;
    return false;
}

///
/// Check for collision
///
std::vector<Bullet*> Monster::CheckCollision(std::vector<Bullet*> TabOfBullets)
{
    _TabOfBullets = TabOfBullets;
    for (int i = 0; i < _TabOfBullets.size(); i++) {
        if(collisionOfBullets(_TabOfBullets.at(i),i, BasiqueBullet))
            i--;
    }
    for (int ii = 0; ii < _TabOfMob1.size(); ii++) {
        if (_TabOfMob1.at(ii)->_posMob1.x <= 200) {
                FinishMob1(ii);
                ii--;
                _PlayerLife--;
                _Score--;
        }
    }
    for (int iii = 0; iii < _TabOfBoss1.size(); iii++) {
        if (_TabOfBoss1.at(iii)->_posBoss1.x <= 200) {
                FinishBoss1(iii);
                iii--;
                _PlayerLife--;
                _Score--;
        }
    }
    return (_TabOfBullets);
}

///
/// Check for collision for ultimate
///
std::vector<Bullet*> Monster::CheckUltiCollision(std::vector<Bullet*> TabOfBullets)
{
    // std::cout << "OKOK" << std::endl;
    _TabOfBulletsUlti = TabOfBullets;
    for (int i = 0; i < _TabOfBulletsUlti.size(); i++) {
        collisionOfBullets(_TabOfBulletsUlti.at(i),i, UltiBullet);
            // i--;
    }

    for (int ii = 0; ii < _TabOfMob1.size(); ii++) {
        if (_TabOfMob1.at(ii)->_posMob1.x <= 200) {
                FinishMob1(ii);
                ii--;
                _PlayerLife--;
                _Score--;
        }
    }
    for (int iii = 0; iii < _TabOfBoss1.size(); iii++) {
        if (_TabOfBoss1.at(iii)->_posBoss1.x <= 200) {
                FinishBoss1(iii);
                iii--;
                _PlayerLife--;
                _Score--;
        }
    }
    return (_TabOfBulletsUlti);
}