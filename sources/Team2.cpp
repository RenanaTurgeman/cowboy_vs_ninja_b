#include "Team2.hpp"
using namespace ariel;
using namespace std;
Team2::Team2() :Team() {}
Team2::Team2(Character* leader): Team(leader) {}

void Team2::add(Character* fighter) {
    if (fighter->getIsMember()) {
        throw runtime_error("ERROR: the fighter is a member in a different team.");
    }

    for (Character* other : getFighters()) {
        if (other == fighter) {
            throw runtime_error("ERROR: this fighter is already in the team.");
        }
    }

    if (getFighters().size() >= 10) {
        throw runtime_error("ERROR: the team already has 10 fighters.");
    }

    if (getFighters().size() < 10) {
        getFighters().insert(getFighters().begin(),fighter);
    }
    fighter->setIsMember();
}
