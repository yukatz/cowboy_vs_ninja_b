#ifndef TRAINEDNINJA_H
#define TRAINEDNINJA_H
#include "Ninja.hpp"

namespace ariel
{

    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(string, const Point &location); // Constructor created with speed = 12, 120 hits.
    };
}
#endif