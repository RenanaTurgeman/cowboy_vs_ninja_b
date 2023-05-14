#ifndef TRAINED_NINJA_HPP
#define TRAINED_NINJA_HPP

#include "Ninja.hpp"
#include <iostream>

namespace ariel {
    class TrainedNinja : public Ninja{
        private:
        public:
            TrainedNinja(std::string name, Point location);
            ~TrainedNinja() = default;

            /*Prints the character's name and location to the console.*/
            std::string print() override;
            friend std::ostream& operator<<(std::ostream& ostream, const TrainedNinja& trainedNinja); //TODO: check if really need (not work without)

    };
}

#endif
