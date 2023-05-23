#include "Ninja.hpp"


namespace ariel{

    Ninja::Ninja(string _name, Point _location, int _hits, int _speed)
    : Character(_name, _location, _hits),speed(_speed){}
    void Ninja::move(const Character *enemy){
        

    }
    void Ninja::slash(Character *other){
        
        if(this->isAlive() && this->distance(other) < 1){
            other->setHits(40);
        }
    }
    string Ninja::print(){
        return "N " + Character::print();
        
    }
    int Ninja::getSpeed(){
        return speed;
    }
}
