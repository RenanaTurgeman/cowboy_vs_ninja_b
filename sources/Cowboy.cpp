#include "Cowboy.hpp"

using namespace ariel;
using namespace std;
//cowboy create with 6 bullets and 110 hit points
Cowboy::Cowboy() : Character("anonymous" , Point(), 110) , bullet(6){}
Cowboy::Cowboy(string name, const Point& location) : Character(name , location , 110) , bullet(6){ }

int Cowboy::getBullet() const {
    return this->bullet;
}

/*If the cowboy is not dead and has bullets left, the cowboy shoots the enemy,
 * subtracting 10 hit points from the enemy - and losing 1 bullet.
 * Otherwise, no damage will be done to the enemy.*/
void Cowboy::shoot(Character* enemy){
    if (!enemy) {
        throw invalid_argument("ERROR: enemy is nullptr");
    }
    if(!enemy->isAlive()){ //if the enemy dead - error
        throw runtime_error("ERROR: the enemy is dead. cant shoot");
    }
    if(!this->isAlive()){ //if the cowboy dead - error
        throw runtime_error("ERROR: the cowboy is dead. cant shoot");
    }
    if(this == enemy){ //if the cowboy and the enemy is the same person
        throw runtime_error("ERROR: cowboy cant attack it self");
    }

    //if we got here its main the cowboy is alive
    if(this->isAlive()) {
        if (this->hasboolets()) { //if there are bullets left
            enemy->hit(10); //subtracting 10 hit points from the enemy
            --this->bullet; // cowboy losing 1 bullet
        }
    }
}

void Cowboy::reload(){
    if(!this->isAlive()){
        throw runtime_error("Error: cant reload, the cowboy is dead");
    }
    this->bullet =6; //TODO: check if it nedd to be +=
}

bool Cowboy::hasboolets() const {
    if (this->bullet >0)
        return true;
    return false;
}

string Cowboy::print() {
    string msg = "C: "; //before the name print C to indicate that is cowboy
    msg += Character::print();
    return msg;
}

