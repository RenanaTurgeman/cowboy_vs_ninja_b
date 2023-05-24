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
            ~Team2() override = default; //for tidy
            // member functions
            void add(Character* fighter) override;

            //for tidy:
            Team2(const Team2&) = delete; // Copy constructor
            Team2& operator=(const Team2&) = delete; // Copy assignment operator
            Team2(Team2&&) = delete; // Move constructor
            Team2& operator=(Team2&&) = delete; // Move assignment operator

    };
}

#endif
