#ifndef YOUNG_NINJA_HPP
#define YOUNG_NINJA_HPP

#include "Ninja.hpp"
#include <iostream>

namespace ariel {
    class YoungNinja : public Ninja{
        private:
        public:
            YoungNinja(std::string name, Point location);
            ~YoungNinja() = default;
            /*Prints the character's name and location to the console.*/
            std::string print() override;
            friend std::ostream& operator<<(std::ostream& ostream, const YoungNinja& youngNinja); //TODO: check if really need (not work without)

    };
}

#endif
