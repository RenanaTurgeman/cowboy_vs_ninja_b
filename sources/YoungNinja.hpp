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
            ~YoungNinja() = default;
    };
}

#endif
