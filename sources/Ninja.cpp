#include "Ninja.hpp"

namespace ariel
{

    Ninja::Ninja(string _name, Point _location, int _hits, int _speed)
        : Character(_name, _location, _hits), speed(_speed) {}
    void Ninja::move(const Character *enemy)
    {

        if (enemy == nullptr)
            throw invalid_argument("Other character is null!");

        else if (enemy == this)
            throw invalid_argument("Cannot move to yourself!");

        else if (!isAlive())
            throw runtime_error("Cannot move while dead!");

        Point newLocation = Point::moveTowards(getLocation(), enemy->getLocation(), this->speed);
        setLocation(newLocation);
    }
    void Ninja::slash(Character *other)
    {
        if (other == nullptr)
            throw invalid_argument("Other character is null!");

        else if (other == this)
            throw runtime_error("Cannot slash yourself!");

        else if (!isAlive())
            throw runtime_error("Cannot slash while dead!");

        else if (!other->isAlive())
            throw runtime_error("Cannot slash a dead character!");

        if (getLocation().distance(other->getLocation()) <= 1)
        {
            other->hit(40);
        }
    }
    string Ninja::print()
    {
        return "N " + Character::print();
    }
    int Ninja::getSpeed()
    {
        return speed;
    }
}
