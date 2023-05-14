#include "Point.hpp"

using namespace ariel;
using namespace std;
Point::Point() : x_coor(0.0), y_coor(0.0) {

}

Point::Point(double x_coor, double y_coor): x_coor(x_coor), y_coor(y_coor){

}

double Point::distance(Point other){
    return 0;
}

string Point::print(){
    return "hi";

}

Point Point::moveTowards(Point& source, Point& destination, double distance){
    return Point(1,1);
}

ostream& ariel::operator<<(std::ostream& ostream, const Point& point){
    return  ostream;
}