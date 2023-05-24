#include "Team.hpp"

namespace ariel
{
    using namespace std;
    Team::Team(Character *leader) : leader(leader)
    {
        if (!leader->isMember())
        {
            this->add(leader);
        }
        else
        {
            throw runtime_error("Already belongs to team");
        }
    }

    void Team::add(Character *member)
    {
        if (member == nullptr)
            throw invalid_argument("Member not exists");

        else if (member->isMember())
            throw runtime_error("Already belongs to team");

        else if (this->warriors.size() == 10)
            throw runtime_error("Team is full!");

        this->warriors.push_back(member);
        member->getInTeam();
    }

    void Team::attack(Team *enemy)
    {
        // Basic shecks
        if (enemy == nullptr)
            throw invalid_argument("Other team not exists");

        else if (enemy->stillAlive() == 0)
            throw runtime_error("There is no one alive in the enemy team");

       // else if (stillAlive() == 0)
            //throw runtime_error("No one alive in attack team");

        // If the leader is dead, chosing a new leader
        if (!(this->leader->isAlive()))
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

        // Choose the victim
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
            if (!closestEnemy->isAlive())
            {
                if (enemy->stillAlive() == 0)
                    break;

                for (Character *member : enemy->warriors)
                {
                    if (member->distance(this->leader) < distEnemy && member->isAlive())
                    {
                        distEnemy = member->distance(this->leader);
                        closestEnemy = member;
                    }
                }
            }

            Cowboy *cowboy = dynamic_cast<Cowboy *>(member);

            if (cowboy != nullptr && cowboy->isAlive())
            {
                if (cowboy->hasboolets())
                    cowboy->shoot(closestEnemy);

                else
                    cowboy->reload();
            }
        }

        for (Character *member : this->warriors)
        {
            if (!closestEnemy->isAlive())
            {
                if (enemy->stillAlive() == 0)
                    break;

                for (Character *member : enemy->warriors)
                {
                    if (member->distance(this->leader) < distEnemy && member->isAlive())
                    {
                        distEnemy = member->distance(this->leader);
                        closestEnemy = member;
                    }
                }
            }

            Ninja *ninja = dynamic_cast<Ninja *>(member);

            if (ninja != nullptr && ninja->isAlive())
            {
                if (ninja->getLocation().distance(closestEnemy->getLocation()) <= 1)
                    ninja->slash(closestEnemy);

                else
                    ninja->move(closestEnemy);
            }
        }
    }

    int Team::stillAlive() const
    {
        int count = 0;
        for (Character *member : this->warriors)
        {
            if (member->isAlive())
            {
                count++;
            }
        }
        return count;
    }

    void Team::print() const
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