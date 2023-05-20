#include "Cowboy.hpp"

namespace ariel
{

    Cowboy::Cowboy(string _name, Point _location)
        : Character(_name, _location, 110), numOfBullets(6) {}
    void Cowboy::shoot(Character *enemy)
    {
        // The cowvoy is alive, still have bulets.
        if (this->isAlive() && this->getBullets() > 0)
        {
            this->numOfBullets -= 1;
            enemy->hit(10);
        }
    }
    bool Cowboy::hasboolets()
    {
        if (this->numOfBullets > 0)
        {
            return true;
        }
        else
            return false;
    }
    string Cowboy::print()
    {
        return "C " + Character::print();

    }
    void Cowboy::reload()
    {
        if (this->numOfBullets == 0)
        {
            this->numOfBullets += 6;
        }
    }
    int Cowboy::getBullets()
    {
        return numOfBullets;
    }
}