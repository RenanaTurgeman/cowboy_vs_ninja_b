#include "Team2.hpp"
using namespace ariel;
using namespace std;
Team2::Team2() :Team() {}
Team2::Team2(Character& leader): Team(leader) {}

void Team2::attack(Team2 *enemyTeam){
    if (!leader) {
        throw invalid_argument("ERROR: Leader is nullptr.");
    }

    if (!leader->isAlive()) {
        choose_leader();
    }

    if (leader) {
        Character* target = choose_target();

        if (target) {
            for (Character* fighter : fighters) {
                if (fighter->isAlive()) {
                    if (fighter->distance(target) < 1) {
                        fighter->slash(target);
                    } else {
                        fighter->move(target);
                    }
                }
            }

            if (!target->isAlive()) {
                Character* newTarget = choose_target();
                if (newTarget) {
                    target = newTarget;
                } else {
                    return;
                }
            }
        }
    }
}
