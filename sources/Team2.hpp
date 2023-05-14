#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Cowboy.hpp"

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

namespace ariel {
    class Team2{
        private:
            std::vector<std::unique_ptr<Character>> fighters; // vector to hold the fighters in the team
            Character& leader; // pointer to the team leader
        public:
            // constructor and destructor
            Team2(Character& leader);
            ~Team2() = default;
            // member functions
            void add(Character& fighter);
            void attack(Team2* enemyTeam);
            int stillAlive();
            std::string print();
            friend std::ostream& operator<<(std::ostream& ostream, const Team2& team2); //TODO: check if really need (not work without)

    };
}

#endif
