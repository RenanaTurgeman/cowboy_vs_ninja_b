#ifndef SMART_TEAM_HPP
#define SMART_TEAM_HPP

#include "Team.hpp"

#include <iostream>
#include <vector>

namespace ariel {
    class SmartTeam: public Team{
        private:
        public:
            // constructor and destructor
            SmartTeam();
            SmartTeam(Character* leader);
            ~SmartTeam() = default;
            // member functions
            void attack(Team* enemyTeam) ;
    };
}

#endif
