#ifndef OLD_NINJA_HPP
#define OLD_NINJA_HPP

#include "Ninja.hpp"
#include <iostream>

namespace ariel {
    class OldNinja : public Ninja{
//        private:
        public:
            OldNinja();
            OldNinja(std::string name, const Point& location);
            ~OldNinja();
    };
}

#endif
