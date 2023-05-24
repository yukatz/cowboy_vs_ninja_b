#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include <sstream>
#include "Point.hpp"
// #include "Cowboy.hpp"
// #include "Ninja.hpp"

namespace ariel
{

  using namespace std;

  class Character
  {
  private:
    string name;            // name of warrior
    Point location;         // warrior location
    int hits;               // number of hits
    bool memOfTeam = false; // flag = true if the warrior is belong to team

  public:
    // Must functions
    Character(string, const Point &location, int);
    bool isAlive() const;                    // if the warrior is alive (number of hits > 0)
    double distance(Character *other) const; // distance between 2 warriors, based on Point function distance
    void hit(int);//hits the warrior, take a number of hits from
    string getName() const;//returns the name of warrior
    Point getLocation() const;//returns the warrior location 
    virtual string print();//prints the warrior details

    // Help functions functions
    void setLocation(Point &newLocation);//change the warrior location, good for ninjas
    void setHits(int);
    int getHits() const;
    bool isMember() const;//check if the warrior belongs to team
    void getInTeam();//join team
  };

}
#endif
