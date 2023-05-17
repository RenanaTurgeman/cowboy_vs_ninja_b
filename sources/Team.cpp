#include "Team.hpp"

using namespace ariel;
using namespace std;
Team::Team() : leader(nullptr) {}
Team::Team(Character* leader) : leader(leader) {
    if(leader->getIsLeader()){
        throw runtime_error("ERROR: already a leader");
    }
    if(this->leader== nullptr){
        throw runtime_error("leader is nullptr");
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

    if (fighters.size() < 10) {
        if(Cowboy* cowboy = dynamic_cast<Cowboy*>(fighter)){
            fighters.insert(fighters.begin(),fighter);
        }else{
            fighters.push_back(fighter);
        }
    }
    fighter->setIsMember();
}

void Team::setLeader(Character* new_leader) {
    this->leader = new_leader;
}

Character* Team::getLeader() const {
    return this->leader;
}

// search the closest fighter to the leader that alive
void Team::chose_leader() {
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

// search the closest enemy to the leader that alive
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
    if (enemyTeam == nullptr) {
        throw std::invalid_argument("ERROR: enemy team is nullptr");
    }
    if (!leader) {
        throw std::invalid_argument("ERROR: leader is nullptr");
    }

    if (enemyTeam->stillAlive() == 0) {
        throw std::runtime_error("ERROR: the enemy team is already dead");
    }

    if(this->stillAlive() == 0){
        throw std::runtime_error("ERROR: the attacker team is already dead");
    }

    if (!leader->isAlive()) { // check if the leader is not alive
        chose_leader();
    }

    if (leader) {
        // Find the closest enemy to the attacking team's leader
        Character* target = chose_target(enemyTeam);

        if (target) {
            attack_target(target, enemyTeam);
        } else {
            // No alive enemies to attack
            return;
        }
    }
}

void Team::attack_target(Character *target, Team *enemyTeam) {
    for (Character* fighter : this->fighters) {
        if (fighter == NULL || target == NULL){ return;}
        if (fighter->isAlive() && target->isAlive()) { // all the lives fighters attack the target
            // ****first go over all the cowboys**** //
            if (Cowboy* cowboy = dynamic_cast<Cowboy*>(fighter)) { //check if the to cowboy success
                if (cowboy->hasboolets() && cowboy) { //cowboy that have bullets shoot the target
                    cowboy->shoot(target); //the cowboy shoot
                    if(!(target->isAlive())){
                        //in the case the target is dead - change to different cowboy
                        target = chose_target(enemyTeam);
                    }
                } else { //cowboy that not have bullets reload there guns
                    cowboy->reload();
                }
            }
            // ****second go over all the ninja**** //
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

void Team::print() {
    string result;
    for (Character* fighter : fighters) {
        result += fighter->print() + "\n";
    }
    cout << result <<endl;
}