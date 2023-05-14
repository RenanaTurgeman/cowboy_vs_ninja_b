#include "Ninja.hpp"

using namespace ariel;
using namespace std;

Ninja::Ninja(string name, Point& location, int hit_point, int speed): Character(name, location, hit_point) , speed(speed){
    
}


void Ninja::move(const Character* enemy){

}

void Ninja::slash(const Character* enemy){

}

string Ninja::print() {
    return "hi";

}

ostream& ariel::operator<<(std::ostream& ostream, const Ninja& ninja){
    return  ostream;
}
