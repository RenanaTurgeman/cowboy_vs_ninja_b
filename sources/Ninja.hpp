#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"
#include <iostream>

namespace ariel {
    class Ninja : public Character{
        private:
            int speed; 
        public:
            Ninja();
            Ninja(std::string name, const Point& location, int hit_point, int speed);
            ~Ninja();
            int getSpeed();
            void move(const Character* enemy);
            void slash(Character* enemy);

            /*Prints the character's name and location to the console.*/
            std::string print() override;

    };
}

#endif
