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
            virtual ~Character();
            /*getters*/
            virtual int getHitPoints() const;
            virtual void setHitPoints(int num);
            /* Returns true if the character has more than 0 hit points, and false otherwise*/
            virtual bool isAlive() const;
            /*Calculates the distance between this character and another character.*/
            virtual double distance(Character* other);
            /* Decreases the character's hit points by the given number.*/
            virtual void hit(int num);
            /*Returns the character's name*/
            virtual std::string getName() const;
            /*Returns the character's current location.*/
            virtual const Point& getLocation() const;
            void setLocation(Point other);
            /*Prints the character's name, hit points and location to the console.*/
            virtual std::string print();
            virtual bool getIsMember();
            virtual void setIsMember();
            virtual bool getIsLeader() const;
            virtual void setIsLeader();

            //for tidy:
            Character(const Character&) = delete; // delete copy constructor
            Character& operator=(const Character&) = delete; // delete copy assignment operator
            Character(Character&&) = delete; // delete move constructor
            Character& operator=(Character&&) = delete; // delete move assignment operator
    };
}

#endif
