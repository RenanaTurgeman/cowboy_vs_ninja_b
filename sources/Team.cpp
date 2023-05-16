#include "Team.hpp"

using namespace ariel;
using namespace std;
Team::Team() : leader(nullptr) {}
Team::Team(Character* leader) : leader(leader) {
    if(leader->getIsLeader()){
        throw runtime_error("ERROR: already a leader");
    }
    leader->setIsLeader();
    this->fighters.push_back(leader);
}
Team::~Team() {
    for (Character* fighter : fighters) {
        delete fighter;
    }
}

void Team::add(Character* fighter) {
    if (fighter->getIsMember()) {
        throw runtime_error("ERROR: the fighter is a member in a different team.");
    }

    for (Character* other : fighters) {
        if (other == fighter) {
            throw runtime_error("ERROR: this fighter is already in the team.");
        }
    }

    if (this->fighters.size() >= 10) {
        throw runtime_error("ERROR: the team already has 10 fighters.");
    }

    fighters.push_back(fighter);
    fighter->setIsMember();
}

void Team::setLeader(Character* new_leader) {
    this->leader = new_leader;
}

Character* Team::getLeader() const {
    return this->leader;
}

void Team::chose_leader() {
    // search the closest fighter to the leader that alive
    Character* new_leader = nullptr;
    double min_distance = numeric_limits<int>::max();

    // over all fighters
    for (Character* other : fighters)
    {
        if(other->isAlive()) //fighter is alive
        {
            double temp_dist = other->distance(getLeader()); // calc the distance from the leader
            if (temp_dist < min_distance)
            {
                new_leader = other;
                min_distance = temp_dist;
            }
        }
    }
    setLeader(new_leader);
}

Character* Team::chose_target(Team* enemyTeam){
    Character* target = nullptr;
    double closestDistance = numeric_limits<double>::max();
    for (Character* enemy : enemyTeam->fighters) {
        if (enemy->isAlive()) {
            double distance = leader->distance(enemy);
            if (distance < closestDistance) {
                closestDistance = distance;
                target = enemy;
            }
        }
    }
    return target;
}

void Team::attack(Team* enemyTeam) {
    if(enemyTeam == nullptr){
        throw invalid_argument("ERROR: enemy team is nullptr");
    }
    if (!leader){
        throw invalid_argument("ERROR: leader is nullptr");
    }
    if(enemyTeam->stillAlive() == 0){
        throw runtime_error("ERROR: the team is dead");
    }
    if ( !(this->leader->isAlive())) { //check if the leader is not alive
        chose_leader();
    }

    if (leader) {
        // Find the closest enemy to the attacking team's leader
        Character* target = nullptr;
        target = chose_target(enemyTeam);

        // Attack the target if it exists
        if (target) {
            attack_target(target, enemyTeam);
        }
    }
}

void Team::attack_target(Character *target, Team *enemyTeam) {
    // ****first go over all the cowboys**** //
    for (Character* fighter : this->fighters) {
        if (fighter == NULL){ return;}
        if (fighter->isAlive()) { // all the lives fighters attack the target
            if (Cowboy* cowboy = dynamic_cast<Cowboy*>(fighter)) { //check if the to cowboy success
                if (cowboy->hasboolets()) { //cowboy that have bullets shoot the target
                    cowboy->shoot(target); //the cowboy shoot
                    if(!(target->isAlive())){
                        //in the case the target is dead - change to different cowboy
                        target = chose_target(enemyTeam);
                    }
                } else { //cowboy that not have bullets reload there guns
                    cowboy->reload();
                }
            }
        }
    }

    // ****second go over all the ninja**** //
    for (Character* fighter : this->fighters) {
        if (fighter == NULL){ return;}
        if (fighter->isAlive()) { // all the lives fighters attack the target
            if (Ninja* ninja = dynamic_cast<Ninja*>(fighter)) { //check if the cast to ninja success
                if (ninja->distance(target) < 1) { //ninja that in distance < 1 meter from target- slash him
                    ninja->slash(target); //the ninja slash
                    if(!(target->isAlive())){
                        //in the case the target is dead - change to different cowboy
                        target = chose_target(enemyTeam);
                    }
                } else { //ninja that are in distance > 1 move
                    ninja->move(target);
                }
            }
        }
    }

}

int Team::stillAlive() {
    int count = 0;
    for (Character* fighter : fighters) {
        if (fighter->isAlive()) {
            count++;
        }
    }
    return count;
}

string Team::print() {
    string result;
    for (Character* fighter : fighters) {
        result += fighter->print() + "\n";
    }
    return result;
}