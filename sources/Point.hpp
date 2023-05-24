#ifndef POINT_H
#define POINT_H
#include <string>
namespace ariel
{
    using namespace std;
    class Point{
      private:
         double x;
         double y;

      public:
        Point(double, double);//Construyctor
        double distance(Point Other)const;//distance between 2 points
        string print();//prints the point (x,y)
        static Point moveTowards(Point source, Point destenation, double distance);//move given distance from one point to another
        double getX();
        double getY();
        void setX(double);
        void setY(double);
    };
}
#endif