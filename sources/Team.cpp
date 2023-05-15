#include "Team.hpp"

using namespace ariel;
using namespace std;
Team::Team() : leader(nullptr) {}
Team::Team(Character* leader) : leader(leader) {}
Team::~Team() {
    for (Character* fighter : fighters) {
        delete fighter;
    }
}

void Team::add(Character* fighter) {
    for (Character* other : fighters){
        if (other == fighter){
            throw runtime_error("ERROR: this fighter is in the team.");
        }
    }
    if(this->fighters.size() >= 10) //the team size cant be more than 10
    {
        throw runtime_error("ERROR: the time has already 10 fighters");
    }
    fighters.push_back(fighter);
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
    if (!leader){
        throw invalid_argument("ERROR: leader is nullptr");
    }

    if ( !leader->isAlive()) { //check if the leader is not alive
        chose_leader();
    }

    if (leader) {
        // Find the closest enemy to the attacking team's leader
        Character* target = nullptr;
        target = chose_target(enemyTeam);

        // Attack the target if it exists
        if (target) {
            for (Character* fighter : fighters) {
                if (fighter->isAlive()) { // all the lives fighters attack the target
                    if (Cowboy* cowboy = dynamic_cast<Cowboy*>(fighter)) {
                        if (cowboy->hasboolets()) { //cowboy that have bullets shoot the target
                            cowboy->shoot(target);
                        } else { //cowboy that not have bullets reload there guns
                            cowboy->reload();
                        }
                    } else if (Ninja* ninja = dynamic_cast<Ninja*>(fighter)) {
                        if (ninja->distance(target) < 1) { //ninja that in distance < 1 meter from target- slash him
                            ninja->slash(target);
                        } else { //ninja that are in distance > 1 move
                            ninja->move(target);
                        }
                    }
                }
            }

            // Check if the target is dead and find a new target if needed
            if (!target->isAlive()) {
                Character* newTarget = nullptr;
                newTarget = chose_target(enemyTeam);
                if (newTarget) {
                    target = newTarget;
                } else {
                    // No more alive enemies
                    return;
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