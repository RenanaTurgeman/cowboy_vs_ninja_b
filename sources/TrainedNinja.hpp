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
            ~TrainedNinja() = default;
    };
}

#endif
