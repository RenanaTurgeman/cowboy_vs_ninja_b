#include "SmartTeam.hpp"
using namespace ariel;
using namespace std;
SmartTeam::SmartTeam(Character& leader): leader(leader), fighters(){
//    fighters.push_back(leader);
}

void SmartTeam::add(Character& fighter){

}

void SmartTeam::attack(Team* enemyTeam){

}

int SmartTeam::stillAlive() const{
    return 0;
}

string SmartTeam::print(){
    return "hi";

}
ostream& ariel::operator<<(std::ostream& ostream, const SmartTeam& smartTeam){
    return  ostream;
}