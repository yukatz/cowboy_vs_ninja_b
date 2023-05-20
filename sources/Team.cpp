#include "Team.hpp"

namespace ariel
{
    using namespace std;
    Team::Team(Character *leader):leader(leader){
        add(leader);
    }
    void Team::add(Character *member){
        if(this->warriors.size() == 10){
            throw runtime_error ("The team can't include more then 10 members");
        }
        this->warriors.push_back(member);
    }
    void Team::attack(Team *enemy){

    }
    int  Team::stillAlive(){
        int count;
        for(Character *member : this->warriors){
            if(member->isAlive()){
                count++;
            }
        }
        return count;
    }
    void Team::print(){
        for(Character *member : this->warriors){
            if(member->isAlive()){
                member->print();
            }
        }
    }

}