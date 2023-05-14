#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"
#include <iostream>
/*Cowboy has 6 bullets and 11 hit points*/

namespace ariel {
    class Cowboy : public Character{
        private:
            int bullet = 6; //amount
        public:
            Cowboy(std::string name, Point& location);
            ~Cowboy()= default;
            void shoot(Character* enemy);
            bool hasboolets() const;
            void reload();

            /*Prints the character's name and location to the console.*/
            std::string print() override;

            friend std::ostream& operator<<(std::ostream& ostream, const Cowboy& cowboy); //TODO: check if really need (not work without)

    };
}

#endif
