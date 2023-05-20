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
    void Ninja::print(){
        stringstream output;
        streambuf *coutBuffer = std::cout.rdbuf();
        cout.rdbuf(output.rdbuf());
        Character::print();
        cout.rdbuf(coutBuffer);
        string characterPrint = output.str();
        cout << "N" << characterPrint << endl;
        
    }
    int Ninja::getSpeed(){
        return speed;
    }
}
