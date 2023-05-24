#ifndef OLD_NINJA_HPP
#define OLD_NINJA_HPP

#include "Ninja.hpp"
#include <iostream>

namespace ariel {
    class OldNinja : public Ninja{
        public:
            OldNinja();
            OldNinja(std::string name, const Point& location);
            ~OldNinja() override; //override for tidy

            //for tidy:
            OldNinja(const OldNinja &) = delete;
            OldNinja &operator=(const OldNinja &) = delete;
            OldNinja(OldNinja &&) = delete;
            OldNinja &operator=(OldNinja &&) = delete;
    };
}

#endif
