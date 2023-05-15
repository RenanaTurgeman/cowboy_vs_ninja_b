#include "Point.hpp"
#include "cmath"
using namespace ariel;
using namespace std;
Point::Point() : x_coor(0.0), y_coor(0.0) {

}

Point::Point(double x_coor, double y_coor): x_coor(x_coor), y_coor(y_coor){

}
double Point::getX() const{
    return this->x_coor;
}
double Point::getY() const{
    return this->y_coor;
}
double Point::distance(const Point& other) const{
    double dx = getX() - other.getX();
    double dy = getY() - other.getY();
    return sqrt(dx*dx + dy*dy);
}

void Point::print() const{
    std::cout << "(" << getX() << ", " << getY() << ")" << std::endl;
}

// this function get 2 points and distance and return the closet point to the destination point from the source point
Point Point::moveTowards(const Point &src, const Point &dst, double distance)
{
    if (distance < 0) //distance mast be a positive number or 0
    {
        throw std::invalid_argument("cant have negative distance");
    }

    // if distance from source longer than the distance between 2 points return the value of dst points
    if(src.distance(dst) < distance)
    {
        return dst;
    }
    double my_distance = src.distance(dst); // calculate the distance between src and dst points

    // Calculate the direction vector between the two points
    double dx = (dst.getX() - src.getX()) / my_distance;
    double dy = (dst.getY() - src.getY()) / my_distance;

    double new_x = src.getX() + dx * dist_src;
    double new_y = src.getY() + dy * dist_src;

    return Point (new_x, new_y);
}


    std::ostream& operator<<(std::ostream& ostream, const Point& point) {
        ostream << "(" << point.getX() << ", " << point.getY() << ")";
        return ostream;
    }
