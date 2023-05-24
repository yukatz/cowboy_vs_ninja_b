#include "Team2.hpp"

namespace ariel
{
    Team2::Team2(Character *leader) : Team(leader){}
    void Team2::attack(Team *enemy){
        if (enemy == nullptr)
            throw invalid_argument("Other team is null!");
    }
    void Team2::print()const{}

}