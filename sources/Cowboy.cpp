#include "Cowboy.hpp"

using namespace ariel;
using namespace std;

// Constructor & Destructor
//cowboy create with 6 bullets and 110 hit points
Cowboy::Cowboy() : Character("anonymous" , Point(), 110) , bullet(6){}
Cowboy::Cowboy(string name, const Point& location) : Character(name , location , 110) , bullet(6){ }
Cowboy::~Cowboy(){}

/*If the cowboy is not dead and has bullets left, the cowboy shoots the enemy,
 * subtracting 10 hit points from the enemy - and losing 1 bullet.
 * Otherwise, no damage will be done to the enemy.*/
void Cowboy::shoot(Character* enemy){
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

/*reloads the gun with six new bullets */
void Cowboy::reload(){
    if(!this->isAlive()){
        throw runtime_error("Error: cant reload, the cowboy is dead");
    }
    this->bullet =6;
}

/* returns whether there are any bullets left in this cowboy's gun.*/
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

//get
int Cowboy::getBullet() const {
    return this->bullet;
}

