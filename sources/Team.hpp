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
            Character* leader; // pointer to the team leader
            std::vector<Character *> fighters; // vector to hold the fighters in the team

        public:
            // constructor and destructor
            Team();
            Team(Character* leader);
            virtual ~Team();
            // member functions
            void setLeader(Character* new_leader);
            Character* getLeader() const;
            /*get ninja or cowboy and add them to the group*/
            virtual void add(Character* fighter);
            void attack(Team* enemyTeam);
            int stillAlive();
            void print();
            std::vector<Character*>& getFighters() ;
            void setFighters(const std::vector<Character*>& newFighters) ;

            virtual void chose_leader();     // search the closest fighter to the leader that alive
            virtual Character* chose_target(Team* enemyTeam); // search the closest enemy to the leader that alive
            void attack_target(Character* target, Team* enemyTeam);


            //for tidy:
            Team(const Team&) = delete; // Disable copy constructor
            Team& operator=(const Team&) = delete; // Disable copy assignment operator
            Team(Team&&) = delete; // Disable move constructor
            Team& operator=(Team&&) = delete; // Disable move assignment operator

    };
}

#endif
