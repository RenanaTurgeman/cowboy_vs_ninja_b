#ifndef SMART_TEAM_HPP
#define SMART_TEAM_HPP

#include "Team.hpp"

#include <iostream>
#include <vector>

namespace ariel {
    class SmartTeam{
        private:
            std::vector<std::unique_ptr<Character>> fighters; // vector to hold the fighters in the team
            Character& leader; // pointer to the team leader
        public:
            // constructor and destructor
            SmartTeam(Character& leader);
            ~SmartTeam() = default;
            // member functions
            void add(Character& fighter);
            void attack(Team* enemyTeam);
            int stillAlive() const;
            std::string print();
            friend std::ostream& operator<<(std::ostream& ostream, const SmartTeam& smartTeam); //TODO: check if really need (not work without)

    };
}

#endif
