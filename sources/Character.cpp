#include "Character.hpp"

namespace ariel
{
    using namespace std;
    Character::Character(string _name, const Point &_location, int _hits)
        : name(_name), location(_location), hits(_hits) {}

    bool Character::isAlive() const
    {
        return (this->hits > 0);
    }

    double Character::distance(Character *other) const
    {
        double distance = this->location.distance(other->location);
        return distance;
    }
    void Character::hit(int numOfHits)
    {
        if (numOfHits < 0)
        {
            throw invalid_argument("Hits cant be less then 0");
        }
        else
        {
            if(numOfHits > this->hits){//to avoid more loose more hits than exists
                numOfHits = this -> hits;
            }
            this->hits -= numOfHits;
        }
    }
    string Character::getName() const
    {
        return this->name;
    }
    Point Character::getLocation() const
    {
        return this->location;
    }
    void Character::setLocation(Point &newLocation)
    {
        this->location = newLocation;
    }
    string Character::print()
    {
        stringstream output;
        streambuf *coutBuffer = std::cout.rdbuf();
        cout.rdbuf(output.rdbuf());
        this->location.print();
        cout.rdbuf(coutBuffer);
        string locPrint = output.str();
        if (this->isAlive())
        {
            return "Name: " + this->name + " hits: " + to_string(this->hits) + " location: " + this->getLocation().print();
        }
        else
        {
            return +"Name: (" + this->name + ") location: " + locPrint;
        }
    }
    void Character::setHits(int newHits)
    {
        this->hits = newHits;
    }
    int Character::getHits() const
    {
        return hits;
    }
    bool Character::isMember() const
    {
         return (this->memOfTeam);
    }
    void Character::getInTeam()
    {
        this->memOfTeam = true;
    }

}