#include "Point.hpp"
#include <iostream>
#include <cmath>

namespace ariel
{
    using namespace std;
    Point::Point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    double Point::distance(Point other) const
    {
        double distX = this->x - other.x;
        double distY = this->y - other.y;
        double distance = sqrt(distX * distX + distY * distY);
        return distance;
    }
    string Point::print()
    {
        return "(" + to_string(this->x) + "," + to_string(this->y) + ")";
    }
    Point Point::moveTowards(Point source, Point destenation, double distance)
    {
        if (distance < 0)
            throw invalid_argument("Distance cant be negative");

        double dest = source.distance(destenation);

        if (dest <= distance)
            return destenation;

        double newX = source.x + (distance * (destenation.x - source.x) /dest);
        double newY = source.y + (distance * (destenation.y - source.y) / dest);
        return Point(newX,newY);
    }

    double Point::getX()
    {
        return this->x;
    }
    double Point::getY()
    {
        return this->y;
    }
    void Point::setX(double newX)
    {
        this->x = newX;
    }
    void Point::setY(double newY)
    {
        this->y = newY;
    }

}