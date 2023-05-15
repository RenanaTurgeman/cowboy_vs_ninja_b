#ifndef TEAM_HPP
#define TEAM_HPP

#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Cowboy.hpp"

#include <iostream>
#include <vector>
#include <limits>

namespace ariel {
    class Team{
        private:
            std::vector<Character *> fighters; // vector to hold the fighters in the team
            Character* leader; // pointer to the team leader
        protected:
            void chose_leader();
            Character* chose_target();

        public:
            // constructor and destructor
            Team();
            Team(Character* leader);
            virtual ~Team() ;
            // member functions
            void setLeader(Character* new_leader);
            Character* getLeader() const;
            void add(Character* fighter);
            virtual void attack(Team* enemyTeam);
            int stillAlive();
            std::string print();
    };
}

#endif
