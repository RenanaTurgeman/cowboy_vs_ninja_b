#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"
#include <iostream>
/*Cowboy has 6 bullets and 11 hit points*/

namespace ariel {
    class Cowboy : public Character{
        private:
            int bullet; //amount of the bullets
        public:
            Cowboy(); // default constructor
            Cowboy(std::string name, const Point& location);
            ~Cowboy();
            int getBullet() const;
            void shoot(Character* enemy);
            bool hasboolets() const;
            void reload();

            /*Prints the character's name and location to the console.*/
            std::string print() override;

    };
}

#endif
