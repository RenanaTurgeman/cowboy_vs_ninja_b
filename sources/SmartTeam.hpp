#ifndef SMART_TEAM_HPP
#define SMART_TEAM_HPP

#include "Team.hpp"

#include <iostream>
#include <vector>
#include <random>
#include <unordered_map>
#include <stdexcept>
namespace ariel {
    class SmartTeam: public Team{
        private:
    protected:
        void chose_leader() override;
        public:
            // constructor and destructor
            SmartTeam();
            SmartTeam(Character* leader);
            ~SmartTeam() = default;
            // member functions
            void attack(Team* enemyTeam) ;
            Character* findClosest(Character *ninja);
        };
}

#endif
