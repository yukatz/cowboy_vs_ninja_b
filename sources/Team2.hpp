#include <limits>
#include "Team.hpp"
// The same as team, but the transition to the characters will be according to the order
// of addition without distinguishing cowboys or ninjas.
//Need to override attack and print, functions based on order

namespace ariel
{
	class Team2 : public Team
	{
	public:
		Team2(Character *leader);		   // Constructor
		void attack(Team *other) override; // Overloaded attack method
		void cowboyShoot(Cowboy *cowboy, Character *target);
		void ninjaSlash(Ninja *ninja, Character *target);
		void print() const override; // Overloaded print method
	};
}