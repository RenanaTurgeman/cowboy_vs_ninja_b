#include "Character.hpp"

using namespace ariel;
using namespace std;
// Constructor & Destructor
Character::Character():name("anonymous"), location(Point()), hit_point(0) {}
Character::Character(string name, const Point& location, int hit_point):name(name) , location(location), hit_point(hit_point){ }
Character::~Character() {}

/* Returns true if the character has more than 0 hit points, and false otherwise*/
 bool Character::isAlive() const{
    return getHitPoints() > 0;
 }

double Character::distance(Character* other){
    return this->getLocation().distance(other->getLocation());
}

/* Decreases the character's hit points by the given number.*/
void Character::hit(int num){
    if (num < 0) //this is error if this is negative number
    {
        throw invalid_argument("character cant hit with a negative hit points");
    }
    this->hit_point -= num;
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

/*getters & setters */

int Character::getHitPoints() const {
    return this->hit_point;
}

string Character::getName() const{
    return this->name;
}


const Point& Character::getLocation() const{
    return this->location;
}

void Character::setLocation(Point other) {
    this->location= other;
}

bool Character::getIsMember() {
    return this->is_member;
}

void Character::setIsMember() {
    this->is_member = true;
}

bool Character::getIsLeader() const {
    return this->is_leader;
}

void Character::setIsLeader() {
    this->is_leader = true;
}

void Character::setHitPoints(int num) {
    this->hit_point = num;
}