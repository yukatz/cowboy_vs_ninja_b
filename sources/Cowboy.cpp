#include "Cowboy.hpp"

namespace ariel
{

    Cowboy::Cowboy(string _name, const Point &_location)
        : Character(_name, _location, 110), numOfBullets(6) {}

    Cowboy::~Cowboy() {}

    void Cowboy::shoot(Character *enemy)
    {
        if (enemy == nullptr)
            throw invalid_argument("Enemy doesnt exists");
        else if (!isAlive())
            throw runtime_error("Dead cowboy cant shoot");
        else if (!enemy->isAlive())
            throw runtime_error("Enemy alredy dead");
        else if (enemy == this)
            throw runtime_error("Same warrior");
        else if (this->numOfBullets > 0) // stack isnt empty
        {
            this->numOfBullets -= 1; // one bullet for shoot
            enemy->hit(10);          // takes 10 hits from enemy
        }
    }
    bool Cowboy::hasboolets() const
    {
        return this->numOfBullets > 0;
    }
    string Cowboy::print()
    {
        return "C " + Character::print(); // using the Character print and add C for cowboy
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