#include "Character.hpp"
#include <iostream>

using namespace ariel;
using namespace std;

Character::Character():name("anonymous"), location(Point()), hit_point(0) {}
Character::Character(string name, const Point& location, int hit_point):name(name) , location(location), hit_point(hit_point){ }

int Character::getHitPoints() const {
    return this->hit_point;
}

/* Returns true if the character has more than 0 hit points, and false otherwise*/
 bool Character::isAlive() const{
    if(getHitPoints()>0)
        return true;
    return false;
 }

double Character::distance(Character* other){
    return getLocation().distance(other->getLocation());
}
            
void Character::hit(int num){
    if (num < 0) //this is error if this is negative number
    {
        throw invalid_argument("character cant hit with a negative hit points");
    }
    this->hit_point -= num;
}

string Character::getName() const{
    return this->name;
}

            
Point Character::getLocation() const{
    return this->location;
}

/*Prints the character's name, hit points and location to the console.
 * if the character is dead not print the hit points */
string Character::print(){
    string msg = "";
    if (this->isAlive()){ //character alive
        msg += "Name: " + this->getName() +". Hit points: " + to_string(this->getHitPoints()) + ". Location: " + this->getLocation().print();
    }else{
        msg += "(" + this->getName() + ")";
    }

    return msg;
}
