#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <iostream>

namespace ariel {
    // This class represents a character in a game world. 
    class Character {
        // protected:
        private:
            // The character's location in the game world.
            Point location;
            // The character's name.
            std::string name;
            // The character's current hit points.
            int hit_point;
            //for character to be only once in team
            bool is_member = false;
            //to indicate who is the leader
            bool is_leader= false;

        public:
            /* Constructor for creating a new character with the given name, location, and hit points.*/
            Character(std::string name, const Point& location, int hit_point);
            Character();
//            virtual ~Character() = default;
            /*getters*/
            int getHitPoints() const;
            void setHitPoints(int num);
            /* Returns true if the character has more than 0 hit points, and false otherwise*/
            bool isAlive() const;
            /*Calculates the distance between this character and another character.*/
            double distance(Character* other);
            /* Decreases the character's hit points by the given number.*/
            void hit(int num);
            /*Returns the character's name*/
            std::string getName() const;
            /*Returns the character's current location.*/
            const Point& getLocation() const;
            void setLocation(Point other);
            /*Prints the character's name, hit points and location to the console.*/
            virtual std::string print();
            virtual bool getIsMember();
            virtual void setIsMember();
            virtual bool getIsLeader() const;
            virtual void setIsLeader();
        };
}

#endif
