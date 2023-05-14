#ifndef OLD_NINJA_HPP
#define OLD_NINJA_HPP

#include "Ninja.hpp"
#include <iostream>

namespace ariel {
    class OldNinja : public Ninja{
        private:
        public:
            OldNinja(std::string name, Point location);
            ~OldNinja() = default;
            /*Prints the character's name and location to the console.*/
            std::string print() override;
            friend std::ostream& operator<<(std::ostream& ostream, const OldNinja& oldNinja); //TODO: check if really need (not work without)

    };
}

#endif
