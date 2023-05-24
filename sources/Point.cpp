#include "Point.hpp"
#include "cmath"
using namespace ariel;
using namespace std;
Point::Point() : x_coor(0.0), y_coor(0.0) {}

Point::Point(double x_coor, double y_coor): x_coor(x_coor), y_coor(y_coor){}

double Point::distance(const Point& other) const{
    double dx = getX() - other.getX();
    double dy = getY() - other.getY();
    return sqrt(dx*dx + dy*dy);
}

string Point::print() const{
    string msg = "";
    msg = "(" + to_string(getX()) + ", " + to_string(getY()) + ")" ;
    return msg;
}

// this function get 2 points and distance and return the closet point to the destination point from the source point
Point Point::moveTowards(const Point& src, const Point& dst, double dist_src)
{
    if (dist_src < 0)
    {
        throw std::invalid_argument("Distance cannot be negative number");
    }
    // Check if the source point is already closer to the destination point than the given distance
    if(src.distance(dst) < dist_src){
        // Return the destination point as it is already closer
        return Point(dst.getX() , dst.getY());
    }
    // Calculate the distance between the source and destination points
    double dist = src.distance(dst);
    // Calculate the ratio to determine how much closer the point should move towards the destination
    double ratio = (dist <= 0) ? 0 : dist_src / dist;

    // Calculate the new coordinates of the point by applying the ratio
    double new_x = src.getX() + (dst.getX() - src.getX()) * ratio;
    double new_y = src.getY() + (dst.getY() - src.getY()) * ratio;

    return Point(new_x, new_y);
}

//get
double Point::getX() const{
    return this->x_coor;
}
double Point::getY() const{
    return this->y_coor;
}