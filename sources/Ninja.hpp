#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"
#include <iostream>

namespace ariel {
    class Ninja : public Character{
        private:
            int speed; 
        public:
            Ninja(std::string name, Point& location, int hit_point, int speed);
            ~Ninja() = default; 

            void move(const Character* enemy);
            void slash(const Character* enemy);

            /*Prints the character's name and location to the console.*/
            std::string print() override;

            friend std::ostream& operator<<(std::ostream& ostream, const Ninja& ninja); //TODO: check if really need (not work without)

    };
}

#endif
