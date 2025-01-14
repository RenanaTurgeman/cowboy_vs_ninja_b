#include "Ninja.hpp"

using namespace ariel;
using namespace std;
// Constructor & Destructor
Ninja::Ninja() : Character(), speed(0){}
Ninja::Ninja(string name, const Point& location, int hit_point, int speed): Character(name, location, hit_point) , speed(speed){}
Ninja::~Ninja(){}
/*get a pointer to the enemy and move towards the enemy. The ninja move a distance equal to its speed */
void Ninja::move(const Character* enemy){
    Point other = Point::moveTowards(getLocation(), enemy->getLocation(), getSpeed()); //find the closest point to the enemy
    setLocation(other); //set the location to be the new location
}

/*If the ninja is alive and the enemy is less than 1 meter away,
 * the ninja will deal 40 damage to the enemy. Otherwise, no damage will be done to the enemy. */
void Ninja::slash(Character* enemy) {
    if (!enemy->isAlive()) {
        throw runtime_error("ERROR: enemy is dead, can't slash");
    }
    if (!this->isAlive()) {
        throw runtime_error("ERROR: ninja is dead, can't slash");
    }
    if (this == enemy) {
        throw runtime_error("ERROR: enemy and ninja are the same person, can't slash");
    }

    if (this->isAlive()) {
        // Calculate the distance between the ninja and the enemy
        double distance = getLocation().distance(enemy->getLocation());

        // Slash if the distance is less than 1 meter
        if (distance <= 1.0) {
            // Hit the enemy with 40 points
            enemy->hit(40);
        }
    }
}

string Ninja::print() {
    string msg = "N: "; //indicate its a ninja
    msg += Character::print();
    return msg;
}

int Ninja::getSpeed() {
    return this->speed;
}
