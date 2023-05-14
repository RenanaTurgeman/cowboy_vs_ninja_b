#include "Team2.hpp"
using namespace ariel;
using namespace std;
Team2::Team2(Character& leader): leader(leader), fighters(){
//    fighters.push_back(leader);
}

void Team2::add(Character& fighter){

}

void Team2::attack(Team2 *enemyTeam){

}

int Team2::stillAlive(){
    return 0;
}

string Team2::print(){
    return "hi";

}
ostream& ariel::operator<<(std::ostream& ostream, const Team2& team2){
    return  ostream;
}