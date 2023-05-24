#ifndef YOUNG_NINJA_HPP
#define YOUNG_NINJA_HPP

#include "Ninja.hpp"
#include <iostream>

namespace ariel {
    class YoungNinja : public Ninja{
        private:
        public:
            YoungNinja();
            YoungNinja(std::string name, Point location);
            ~YoungNinja() override = default; //for tidy

            //for tidy:
            YoungNinja(const YoungNinja&) = delete; // Copy constructor
            YoungNinja& operator=(const YoungNinja&) = delete; // Copy assignment operator
            YoungNinja(YoungNinja&&) = delete; // Move constructor
            YoungNinja& operator=(YoungNinja&&) = delete; // Move assignment operator

    };
}

#endif
