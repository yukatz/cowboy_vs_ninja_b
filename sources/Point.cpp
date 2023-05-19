#include "Point.hpp"
#include <iostream>
#include <cmath>

namespace ariel
{
    using namespace std;
    Point::Point(double _x, double _y){
        x = _x;
        y = _y;
    } 
    double Point::distance(Point &other){
        double distX = this->x - other.x;
        double distY = this->y - other.y;
        double distance = sqrt(distX * distX + distY * distY);
        return distance;
    }
    void Point::print(){
        cout << "(" << this->x << "," << this->y << ")" << endl;
    }
    Point moveTowards(Point &source, Point &destenation, double distance){
        return Point(0,0);
    }
    double Point::getX(){
        return this->x;
    }
    double Point::getY(){
        return this->y;
    }
    void Point::setX(double newX){
        this->x = newX;
    }
    void Point::setY(double newY){
        this->y = newY;
    }



}