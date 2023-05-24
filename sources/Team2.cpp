#include "Team2.hpp"

namespace ariel
{
    Team2::Team2(Character *leader) : Team(leader) {}
    
    void Team2::attack(Team *other)
    {
        if (other == nullptr)
            throw invalid_argument("Other team is null!");

        else if (other == this)
            throw runtime_error("Cannot attack self team!");

        else if (other->stillAlive() == 0)
            throw runtime_error("Other team is dead!");

        else if (stillAlive() == 0)
            throw runtime_error("This team is dead!");

        if (!getLeader()->isAlive())
        {
            Character *newLeader = nullptr;

            double minDistance = numeric_limits<double>::max();

            for (Character *member : getWarriors())
            {
                if (member->isAlive() && member->distance(getLeader()) < minDistance)
                {
                    minDistance = member->distance(getLeader());
                    newLeader = member;
                }
            }

            cout << "Team leader " << getLeader()->getName() << " has died, new leader is " << newLeader->getName() << endl;

            setLeader(newLeader);
        }

        cout << "Team " << getLeader()->getName() << " is attacking team " << other->getLeader()->getName() << endl;

        Character *victim = chooseTarget(other);

        for (Character *member : getWarriors())
        {
            if (!victim->isAlive())
            {
                if (other->stillAlive() == 0)
                    break;

                victim = chooseTarget(other);
            }

            Cowboy *c = dynamic_cast<Cowboy *>(member);
            Ninja *n = dynamic_cast<Ninja *>(member);

            if (c != nullptr && c->isAlive())
            {
                if (c->hasboolets())
                    c->shoot(victim);

                else
                    c->reload();
            }

            else if (n != nullptr && n->isAlive())
            {
                if (n->getLocation().distance(victim->getLocation()) <= 1)
                    n->slash(victim);

                else
                    n->move(victim);
            }
        }
    }

    void Team2::print() const
    {
        cout << "Team Leader: " << getLeader()->getName() << endl;

        for (Character *member : getWarriors())
            cout << member->print() << endl;
    }

}