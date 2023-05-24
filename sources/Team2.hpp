#ifndef TEAM2_H
#define TEAM2_H
#include "Team.hpp"
// The same as Team, But the transition to the characters will be in the
// order of addition without distinguishing cowboys or ninjas.
namespace ariel
{

  using namespace std;

  class Team2 : public Team
  {

  public:
    Team2(Character *leader);
    void attack(Team *enemy) override; // Overiding the attac rules
    void print()const override;
  };
}
#endif