#ifndef TRAINED_NINJA_HPP
#define TRAINED_NINJA_HPP

#include "Ninja.hpp"
#include <iostream>

namespace ariel {
    class TrainedNinja : public Ninja{
        private:
        public:
            TrainedNinja();
            TrainedNinja(std::string name, const Point& location);
            ~TrainedNinja() override = default; //for tidy

            //for tidy:
            TrainedNinja(const TrainedNinja&) = delete; // Copy constructor
            TrainedNinja& operator=(const TrainedNinja&) = delete; // Copy assignment operator
            TrainedNinja(TrainedNinja&&) = delete; // Move constructor
            TrainedNinja& operator=(TrainedNinja&&) = delete; // Move assignment operator

    };
}

#endif
