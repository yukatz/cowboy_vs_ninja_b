#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include <sstream>
#include "Point.hpp"
//#include "Cowboy.hpp"
//#include "Ninja.hpp"

namespace ariel
{

  using namespace std;

  class Character
  {
  private:
    string name;
    Point location;
    int hits;

  public:
    Character(string, Point, int);
    bool isAlive();
    double distance(Character *other);
    void hit(int);
    string getName();
    Point getLocation();
    virtual void print();
    void setHits(int);
    int getHits();
  };

}
#endif
