#include "Team.hpp"

namespace ariel
{
    using namespace std;
    Team::Team(Character *leader):leader(leader){
        add(leader);
    }
    void Team::add(Character *member){

    }
    void Team::attack(Team *enemy){}
    int  Team::stillAlive(){
        return 0;
    }
    void Team::print(){
        
    }

}