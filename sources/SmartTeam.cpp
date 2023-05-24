#include "SmartTeam.hpp"
using namespace ariel;
using namespace std;
SmartTeam::SmartTeam(Character* leader): Team(leader){
}

void SmartTeam::attack(Team *enemyTeam) {
    this-> chose_leader(); // here is mt strategy to choose a leader based on the proximity counts of the living ninjas to other characters
    Team::attack(enemyTeam);
}

Character* SmartTeam::findClosest(Character *ninja) {
    Character* closestChar = nullptr;
    double minDistance = std::numeric_limits<double>::max();

    for (Character* fighter : getFighters()) {
        if (fighter->isAlive()) {
            double distance = fighter->distance(ninja);
            if (distance < minDistance) {
                closestChar = fighter;
                minDistance = distance;
            }
        }
    }

    return closestChar;
}
//the function tries to find a suitable leader for the SmartTeam based on proximity counts and,
// if that fails, selects a random living character as the leader.
void SmartTeam::chose_leader() {
    // Create a map to store the count of proximity for each character
    std::unordered_map<Character*, int> proximityCounts;

    // Iterate over the fighters to find the closest character to each living ninja
    for (Character* fighter : getFighters()) {
        // Check if the fighter is a ninja and is alive
        Ninja* ninja = dynamic_cast<Ninja*>(fighter);
        if (ninja != nullptr && ninja->isAlive()) {
            // Find the closest character to the ninja
            Character* closestChar = findClosest(ninja);
            if (closestChar != nullptr) {
                // Increment the count of proximity for the closest character
                proximityCounts[closestChar]++;
            }
        }
    }

    Character* nextLeader = nullptr;
    int maxCount = 0;

    // Find the character with the highest count of proximity
    for (const auto& pair : proximityCounts) {
        if (pair.second > maxCount) {
            nextLeader = pair.first;
            maxCount = pair.second;
        }
    }

    // If no suitable leader is found among characters that are closest to the most ninjas,
    // pick a random living character as the leader.
    if (nextLeader == nullptr) {
        vector<Character*> livingFighters;
        for (Character* fighter : getFighters()) {
            if (fighter->isAlive()) {
                livingFighters.push_back(fighter);
            }
        }

        if (!livingFighters.empty()) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<std::vector<Character*>::size_type> distrib(0, livingFighters.size() - 1);

            nextLeader = livingFighters[distrib(gen)];
        }
    }

    // If there are no living characters in the team, the team has lost.
    if (nextLeader == nullptr) {
        throw runtime_error("No suitable leader could be found");
    }

    setLeader(nextLeader);
}
