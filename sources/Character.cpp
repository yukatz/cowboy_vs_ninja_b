#include "Character.hpp"

namespace ariel
{
    using namespace std;
    Character::Character(string _name, Point _location, int _hits)
        : name(_name), location(_location), hits(_hits) {}
    bool Character::isAlive()
    {
        if (this->hits > 0)
            return true;
        else
            return false;
    }
    double Character::distance(Character *other)
    {
        double distance = this->location.distance(other->location);
        return distance;
    }
    void Character::hit(int numOfHits)
    {
        if (numOfHits > 0)
        {
            if (numOfHits > this->hits) // Cant take more then exists
            {
                numOfHits = this->hits;
            }
            this->hits -= numOfHits;
        }
        else
        {
            throw std::invalid_argument("Number of hits can't be negative");
        }
    }
    string Character::getName()
    {
        return this->name;
    }
    Point Character::getLocation()
    {
        return this->location;
    }
    void Character::setLocation(Point newLocation){
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
            return + "Name: (" + this->name + ") location: " + locPrint;
        }
    }
    void Character::setHits(int newHits)
    {
        this->hits = newHits;
    }
    int Character::getHits()
    {
        return hits;
    }
    bool Character::isMember(){
        if(this->memOfTeam){
            return true;
        }
        else return false;

    }
    void Character::getInTeam(){
        this->memOfTeam = true;
    }

}