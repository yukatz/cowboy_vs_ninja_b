#include <limits>
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
    Team::~Team()
    {
        for (Character *member : this->warriors)
            delete member;
        warriors.clear();
    }

    void Team::add(Character *member)
    {
        if (member == nullptr)
            throw invalid_argument("Member not exists");
        else if (member->isMember())
            throw runtime_error("Already belongs to team");
        else if (this->warriors.size() == 10)
            throw runtime_error("Team can include at most 10 members");
        this->warriors.push_back(member);
        member->getInTeam();
    }

    void Team::attack(Team *enemy)
    {
        if (enemy == nullptr)
            throw invalid_argument("Enemy team doesnt exists");
        else if (enemy->stillAlive() == 0)
            throw runtime_error("Enemy team is dead");
        else if (stillAlive() == 0)
            throw runtime_error("Attack team is dead!");
        else if (enemy == this)
            throw runtime_error("Same team");

        // If the attack team leader is dead, choose new one
        if (!this->leader->isAlive())
        {
            this->chooseNewLeader();
        }
        Character *target = chooseTarget(enemy);
        cowboysAttack(target, enemy);
        ninjaAttack(target, enemy);

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
    Character *Team::chooseTarget(Team *enemy) const
    {
        Character *target = nullptr;

        double minDistance = 10000000;

        for (Character *member : enemy->warriors)
        {
            if (member->isAlive() && this->leader->distance(member) < minDistance)
            {
                minDistance = this->leader->distance(member);
                target = member;
            }
        }
        return target;
    }
    Character *Team::getLeader() const
    {
        return this->leader;
    }

    void Team::setLeader(Character *leader)
    {
        this->leader = leader;
    }
    const vector<Character *> &Team::getWarriors() const
    {
        return this->warriors;
    }

    void Team::chooseNewLeader()
    {
        Character *newLeader = nullptr;
        double minDistance = numeric_limits<double>::max();
        for (Character *member : this->warriors)
        {
            if (member->isAlive() && member->distance(this->leader) < minDistance)
            {
                minDistance = member->distance(this->leader);
                newLeader = member;
            }
        }
        this->setLeader(newLeader);
    }

    void Team::cowboysAttack(Character *target, Team *enemy)
    {
        for (Character *member : this->warriors)
        {
            if (!target->isAlive())
            {
                if (enemy->stillAlive() == 0)
                    break;

                target = chooseTarget(enemy);
            }

            Cowboy *c = dynamic_cast<Cowboy *>(member);

            if (c != nullptr && c->isAlive())
            {
                if (c->hasboolets())
                    c->shoot(target);

                else
                    c->reload();
            }
        }
    }
    void Team::ninjaAttack(Character *target, Team *enemy)
    {

        for (Character *member : warriors)
        {
            if (!target->isAlive())
            {
                if (enemy->stillAlive() == 0)
                    break;

                target = chooseTarget(enemy);
            }

            Ninja *n = dynamic_cast<Ninja *>(member);

            if (n != nullptr && n->isAlive())
            {
                if (n->getLocation().distance(target->getLocation()) <= 1)
                    n->slash(target);

                else
                    n->move(target);
            }
        }
    }
}