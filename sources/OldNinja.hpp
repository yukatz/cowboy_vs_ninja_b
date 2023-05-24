#ifndef OLDNINJA_H
#define OLDNINJA_H
#include "Ninja.hpp"

namespace ariel
{
    class OldNinja : public Ninja
    {
    public:
        OldNinja(string, const Point &location );//Constructor created with speed = 8, 150 hits.
    };
}
#endif