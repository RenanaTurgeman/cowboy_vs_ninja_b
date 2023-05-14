#include "Point.hpp"
#include "cmath"
using namespace ariel;
using namespace std;
Point::Point() : x_coor(0.0), y_coor(0.0) {

}

Point::Point(double x_coor, double y_coor): x_coor(x_coor), y_coor(y_coor){

}

double Point::distance(const Point& other) const{
    double dx = x_coor - other.x_coor;
    double dy = y_coor - other.y_coor;
    return sqrt(dx*dx + dy*dy);
}

void Point::print() const{
    std::cout << "(" << x_coor << ", " << y_coor << ")" << std::endl;
}

//Point Point::moveTowards(Point& source, Point& destination, double distance) {
//    //calculate the current distance between the source and destination
//    double currentDistance = source.distance(destination);
//    if (currentDistance <= distance) {
//        return destination;
//    }
//    // calculate the ratio between the distance parameter and the current distance
//    double ratio = distance / currentDistance;
//    //calculate the new x and y coordinates of the point that is distance away from the source
//    // point in the direction of the destination point.
//    double newX = source.x_coor + ratio * (destination.x_coor - source.x_coor);
//    double newY = source.y_coor + ratio * (destination.y_coor - source.y_coor);
//    return Point(newX, newY);
//}
static Point moveTowards(const Point& source, const Point& destination, double distance) {
    double currentDistance = source.distance(destination);
    if (currentDistance < distance) {
        return destination;
    }
    if (distance < 0) {
        throw std::invalid_argument("distance must be non-negative");
    }
    double ratio = distance / currentDistance;
    double newX = source.x_coor + ratio * (destination.x_coor - source.x_coor);
    double newY = source.y_coor + ratio * (destination.y_coor - source.y_coor);
    return Point(newX, newY);
}

    std::ostream& operator<<(std::ostream& ostream, const Point& point) {
        ostream << "(" << point.x_coor << ", " << point.y_coor << ")";
        return ostream;
    }
