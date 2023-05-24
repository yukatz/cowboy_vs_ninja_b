#include "Cowboy.hpp"

namespace ariel
{

    Cowboy::Cowboy(string _name, Point _location)
        : Character(_name, _location, 110), numOfBullets(6) {}
    void Cowboy::shoot(Character *enemy)
    {
        if (enemy == nullptr)
            throw invalid_argument("Other character is null!");

        else if (enemy == this)
            throw runtime_error("Cannot shoot yourself!");

        else if (!isAlive())
            throw runtime_error("Cannot shoot while dead!");

        else if (!enemy->isAlive())
            throw runtime_error("Cannot shoot a dead character!");

        else

            if (this->numOfBullets > 0)
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
        if (this->isAlive())
        {
            this->numOfBullets = 6;
        }
        else
            throw runtime_error("Dead cowbowboy don't need bullets");
    }
    int Cowboy::getBullets()
    {
        return numOfBullets;
    }
}