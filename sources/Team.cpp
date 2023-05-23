#include "Team.hpp"

namespace ariel
{
    using namespace std;
    Team::Team(Character *leader) : leader(leader)
    {
        add(leader);
    }
    void Team::add(Character *member)
    {
        if (this->warriors.size() == 10)
        {
            throw runtime_error("The team can't include more then 10 members");
        }
        this->warriors.push_back(member);
    }
    void Team::attack(Team *enemy)
    {
        if (!(this->leader->isAlive())) // Chosing a new leader
        {
            Character *closest;
            double dist = 10000;
            for (Character *member : this->warriors)
            {
                if (member->distance(this->leader) < dist && member->isAlive())
                {
                    dist = member->distance(this->leader);
                    closest = member;
                }
            }
        }
        // Choose the victim (closest to the attac team leader)
        Character *closestEnemy;
        double distEnemy = 10000;
        for (Character *member : enemy->warriors)
        {
            if (member->distance(this->leader) < distEnemy && member->isAlive())
            {
                distEnemy = member->distance(this->leader);
                closestEnemy = member;
            }
        }
       for (Character *member : this->warriors)
        {
            if ( member->isAlive())
            {
                
            }
        }





    }
    int Team::stillAlive()
    {
        int count;
        for (Character *member : this->warriors)
        {
            if (member->isAlive())
            {
                count++;
            }
        }
        return count;
    }
    void Team::print()
    {
        for (Character *member : this->warriors)
        {
            if (member->isAlive() && dynamic_cast<Ninja *>(member))
            {
                cout << member->print() << endl;
            }
        }
        for (Character *member : this->warriors)
        {
            if (member->isAlive() && dynamic_cast<Cowboy *>(member))
            {
                cout << member->print() << endl;
            }
        }
    }
}