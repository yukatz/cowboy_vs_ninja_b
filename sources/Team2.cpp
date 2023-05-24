#include "Team2.hpp"

namespace ariel
{
    Team2::Team2(Character *leader) : Team(leader) {}

    void Team2::attack(Team *enemy)
    {
        if (enemy == nullptr)
            throw invalid_argument("Enemy team doesnt exists");
        else if (enemy->stillAlive() == 0)
            throw runtime_error("Enemy team is dead");
        else if (stillAlive() == 0)
            throw runtime_error("Attack team is dead!");
        else if (enemy == this)
            throw runtime_error("Same team");

        if (!getLeader()->isAlive())
        {
            chooseNewLeader();
        }
        Character *target = chooseTarget(enemy);

        for (Character *member : getWarriors())
        {
            if (!target->isAlive())
            {
                if (enemy->stillAlive() == 0)
                    break;
                target = chooseTarget(enemy);
            }
            Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
            Ninja *ninja = dynamic_cast<Ninja *>(member);
            if (cowboy != nullptr && cowboy->isAlive())
            {
                cowboyShoot(cowboy, target);
            }
            else if (ninja != nullptr && ninja->isAlive())
            {
                ninjaSlash(ninja, target);
            }
        }
    }

    void Team2::cowboyShoot(Cowboy *cowboy, Character *target)
    {
        if (cowboy->hasboolets())
            cowboy->shoot(target);

        else
            cowboy->reload();
    }

    void Team2::ninjaSlash(Ninja *ninja, Character *target)
    {
        if (ninja->getLocation().distance(target->getLocation()) <= 1)
            ninja->slash(target);

        else
            ninja->move(target);
    }

    void Team2::print() const
    {
        for (Character *member : getWarriors())
            cout << member->print() << endl;
    }

}