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
//            SmartTeam() : Team(){} //do it alone
            SmartTeam(Character* leader);
            ~SmartTeam() override = default;
            // member functions
            void attack(Team* enemyTeam) ;
            Character* findClosest(Character *ninja);

            //for tidy:
            SmartTeam(const SmartTeam&) = delete; // Copy constructor
            SmartTeam& operator=(const SmartTeam&) = delete; // Copy assignment operator
            SmartTeam(SmartTeam&&) = delete; // Move constructor
            SmartTeam& operator=(SmartTeam&&) = delete; // Move assignment operator
        };
}

#endif
