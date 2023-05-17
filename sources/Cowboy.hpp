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
            /*the cowboy shoots the enemy by subtracting 10 hit points from the enemy - and losing 1 bullet*/
            void shoot(Character* enemy);
            /* returns whether there are any bullets left in this cowboy's gun.*/
            bool hasboolets() const;
            /*reloads the gun with six new bullets */
            void reload();

            /*Prints the character's name and location to the console.*/
            std::string print() override;

    };
}

#endif
