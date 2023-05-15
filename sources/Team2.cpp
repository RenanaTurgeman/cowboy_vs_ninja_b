#include "Team2.hpp"
using namespace ariel;
using namespace std;
Team2::Team2() :Team() {}
Team2::Team2(Character* leader): Team(leader) {}

//void Team2::attack(Team *enemyTeam){
//    if (!getLeader()) {
//        throw invalid_argument("ERROR: Leader is nullptr.");
//    }
//
//    if (!getLeader()->isAlive()) {
//        chose_leader();
//    }
//
//    if (getLeader()) {
//        Character* target = chose_target();
//
//        if (target) {
//            for (Character* fighter : fighters) {
//                if (fighter->isAlive()) {
//                    if (fighter->distance(target) < 1) {
//                        fighter->slash(target);
//                    } else {
//                        fighter->move(target);
//                    }
//                }
//            }
//
//            if (!target->isAlive()) {
//                Character* newTarget = chose_target();
//                if (newTarget) {
//                    target = newTarget;
//                } else {
//                    return;
//                }
//            }
//        }
//    }
//}

void Team2::attack(Team *enemyTeam){

}