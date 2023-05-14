#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

namespace ariel {
    // This class represents a point 
    class Point {
    private:
        double x_coor; // The x-coordinate of the point.
        double y_coor; // The y-coordinate of the point.
    
    public:
        /*Constructor for creating a new point with the given x and y coordinates.*/
        Point();
        Point(double x_coor, double y_coor);
        ~Point() = default; 

        /*Calculates the Euclidean distance between this point and another point.
          The other point is passed as a parameter.*/
        double distance(Point other);
        
        /* Prints the coordinates of the given point to the console.*/
        std::string print();
        
        /*The function returns the closest point to the destination point,
         * - which is at most the given distance from the source point*/
        Point moveTowards(Point& source, Point& destination, double distance);
        friend std::ostream& operator<<(std::ostream& ostream, const Point& point); //TODO: check if really need (not work without)

    };
}

#endif
