#ifndef TEAM_HPP
#define TEAM_HPP

#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Cowboy.hpp"

#include <iostream>
#include <vector>
#include <memory>

namespace ariel {
    class Team{
        private:
            std::vector<std::unique_ptr<Character>> fighters; // vector to hold the fighters in the team
            Character* leader; // pointer to the team leader
        public:
            // constructor and destructor
            Team(Character* leader);
            ~Team() = default;
            // member functions
            void add(Character* fighter);
            void attack(Team* enemyTeam);
            int stillAlive();
            std::string print();
            friend std::ostream& operator<<(std::ostream& ostream, const Team& team); //TODO: check if really need (not work without)

    };
}

#endif
