#include "Ninja.hpp"

namespace ariel
{

    Ninja::Ninja(string _name, const Point &_location, int _hits, int _speed)
        : Character(_name, _location, _hits), speed(_speed) {}
    Ninja::~Ninja() {}

    void Ninja::move(Character *enemy)
    {

        if (enemy == nullptr)
            throw invalid_argument("Enemy doesnt exists");
        else if (!isAlive())
            throw runtime_error("Dead ninja cant move");
        else if (enemy == this)
            throw invalid_argument("Same warrior");
        Point newLocation = Point::moveTowards(getLocation(), enemy->getLocation(), this->speed);
        setLocation(newLocation);
    }

    void Ninja::slash(Character *other)
    {
        if (other == nullptr)
            throw invalid_argument("Enemy doesnt exists");
        else if (!isAlive())
            throw runtime_error("Dead cowboy cant slash");
        else if (!other->isAlive())
            throw runtime_error("Enemy alredy dead");
        else if (other == this)
            throw runtime_error("Same warrior");

        if (getLocation().distance(other->getLocation()) <= 1) // slash when close to enemy
        {
            other->hit(40); // takes 40 hits from enemy
        }
    }
    string Ninja::print()
    {
        return "N " + Character::print(); // using the Character print and add N for ninja
    }
    int Ninja::getSpeed()
    {
        return speed;
    }
}
