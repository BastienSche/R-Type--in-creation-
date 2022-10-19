#ifndef R_TYPE_MonsterControlSystem_H
#define R_TYPE_MonsterControlSystem_H

#include "BulletControlSystem.hpp"

#define SPEED_MOB1 5
#define SPEED_BOSS1 3

enum TypeOfBullet {BasiqueBullet = 0, UltiBullet = 1};

class Mob1
{
    public:
        Mob1(Position);
        ~Mob1();
        sf::CircleShape _shapeMob1; // Shape du mob1
        Position _SpawnPos; //Pos de depart
        Position _posMob1; //pos du mob1
        Direction _dir;

        int SetupPileOuFace(); // Setup 1 ou 2
        void UpdateMob1(); //Update pos du mob1
        void setPosition(); //Set la pos sur la shape
    private:
};

class Boss1
{
    public:
        Boss1(Position);
        ~Boss1();
        sf::CircleShape _shapeBoss1; // Shape du boss1
        Position _SpawnPos; //Pos de depart
        Position _posBoss1; //pos du Boss1
        Direction _dir;
        int _life;
        
        int SetupPileOuFace(); // Setup 1 ou 2
        void UpdateBoss1(); //Update pos du boss1
        void setPosition(); // Set la pos sur la Shape
    private:
};

class Monster
{
public:
    Monster(int);
    ~Monster();
    int _level; //Level en cours
    void HandleMonster(); //Gestion de Monstre en fonction du niveau
    void WaveLunch(int, int); //void WaveLunch(nombre de mob1, nombre de boss2); 
    void UpdateMonster(); //Update la pos des monstres
    int SetupRand(int, int); //Setup la pos Aleatoire Y du monstre
    std::vector<Bullet*> CheckCollision(std::vector<Bullet*>); // Check Collision manager
    bool collisionOfBullets(Bullet*, int, TypeOfBullet); // Check collision Bullet / MONSTRE
    void FinishMob1(int); //TUe le mob
    void FinishBoss1(int); //TUe le boss
    void FinishBullet(int, TypeOfBullet);
    int CheckStatus();

    std::vector<Bullet*> CheckUltiCollision(std::vector<Bullet*>);

    std::vector<Mob1 *> _TabOfMob1; //Vector de Mob1 (tous les mobs actifs)
    std::vector<Boss1 *> _TabOfBoss1; //Vector de Boss1 (tous les mobs actifs)
    bool _actifWave; //Vague en cour ?
    std::vector<Bullet*> _TabOfBullets;
    sf::Font _font;
    sf::Text _textScore;
    sf::Text _textWaves;
    sf::Text _textLife;
    sf::Text _textShootProgress;
    int _Score;
    int _PlayerLife;

    std::vector<Bullet*> _TabOfBulletsUlti;
    int _UltiShootProgress;
private:

};

#endif //R_TYPE_MonsterControlSystem_H