#ifndef YOUNGNINJA_H
#define YOUNGNINJA_H
#include "Ninja.hpp"

namespace ariel
{

    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(string, const Point &location); // Constructor created with speed = 14, 100 hits.
    };
}
#endif