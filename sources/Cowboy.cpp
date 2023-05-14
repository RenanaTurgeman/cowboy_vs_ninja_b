#include "Cowboy.hpp"

using namespace ariel;
using namespace std;

Cowboy::Cowboy(string name, Point& location):Character(name , location , 11){ }

void Cowboy::shoot(Character* enemy){

}

void Cowboy::reload(){

}

bool Cowboy::hasboolets() const {
//    return bullet > 0;
    return false;
}

string Cowboy::print() {
    // cout << "Cowboy " << getName() << " is at location (" << getLocation().getX() << ", " << getLocation().getY() << ")" << endl;
    return "hi";

}

ostream& ariel::operator<<(std::ostream& ostream, const Cowboy& cowboy){
    return  ostream;
}
