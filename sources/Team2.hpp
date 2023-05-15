#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Cowboy.hpp"
#include "Team.hpp"

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

namespace ariel {
    class Team2 : public Team{
        private:
        public:
            // constructor and destructor
            Team2();
            Team2(Character* leader);
            ~Team2() = default;
            // member functions
//            void attack(Team* enemyTeam) override;
    };
}

#endif
