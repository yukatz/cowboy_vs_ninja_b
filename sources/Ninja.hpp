#ifndef NINJA_H
#define NINJA_H
#include "Character.hpp"

namespace ariel
{

    class Ninja : public Character
    {
        int speed;

    public:
        Ninja(string, const Point &location, int, int);    // Constructor
        void move(Character *enemy); // moves the dustanse of its speed
        void slash(Character *other);// if the ninja is alive and the enemy is at most 1 meter,takes 40 hits from enemy.
        virtual string print() override;
        int getSpeed();
    };
}
#endif
// For nunjas: int speed, there is 3 types of nunjas:
// Functions:
// void move(Caracter &enemy) - moves the dustanse of its speed.
// slash(Character &enemy) - if the ninja is alive and the enemy is at most 1 meter,
//  takes 40 hits from enemy.