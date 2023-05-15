#include "SmartTeam.hpp"
using namespace ariel;
using namespace std;
SmartTeam::SmartTeam() : Team(){}
SmartTeam::SmartTeam(Character* leader): Team(leader){
}

//void SmartTeam::attack(Team* enemyTeam){
//
//}
//void SmartTeam::attack(Team *enemyTeam){
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
//                        fighter->Ninja::slash(target);
//                    } else {
//                        fighter->Ninja::move(target);
//                    }
//                }
//            }
//
//            if (!target->isAlive()) {
//                Character* newTarget =  chose_target();
//                if (newTarget) {
//                    target = newTarget;
//                } else {
//                    return;
//                }
//            }
//        }
//    }
//}
void SmartTeam::attack(Team *enemyTeam) {
}