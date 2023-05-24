#include "SmartTeam.hpp"

namespace ariel
{
    SmartTeam::SmartTeam(Character *leader) : Team(leader) {}
    void SmartTeam::attack(Team *enemy) {}
    void SmartTeam::print() const {}

}