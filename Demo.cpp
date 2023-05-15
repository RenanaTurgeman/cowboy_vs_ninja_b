/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;


int main() {
    Point a(32.3,44),b(1.3,3.5);
    assert(a.distance(b) == b.distance(a));
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    tom->shoot(sushi);
    cout << tom->print() <<endl;

    sushi->move(tom);
    sushi->slash(tom);

    Team team_A(tom); 
    team_A.add(new YoungNinja("Yogi", Point(64,57)));

    // Team b(tom); should throw tom is already in team a

     Team team_B(sushi);
     team_B.add(new TrainedNinja("Hikari", Point(12,81)));


     while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
        team_A.attack(&team_B);
        team_B.attack(&team_A);
        team_A.print();
        team_B.print();
     }

     if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
     else cout << "winner is team_B" << endl;

     /*Point class*/
     //print a simple distance
     Point d(0,0), c(0,1);
    std::cout << "Point c coordinates: ";
    std::cout << c.print() << std::endl;
    std::cout << "Point d coordinates: ";
    std::cout << d.print() << std::endl;

    // Calculate distance between two points
    double dist = d.distance(c);
    cout << "Distance between points c and d: " << dist << endl;

    // Move point a towards point b by a distance of 1
    Point e = c.moveTowards(c,d,1);
    std::cout << "Point c moved towards point d: ";
    std::cout << e.print() << std::endl;
    /*end Point class*/



    /*Character class*/
    // Create a point for character locations
    Point p1(2.0, 3.0);
    Point p2(5.0, 7.0);

    // Create two characters
    Character character1("Alice", p1, 100);
    Character character2("Bob", p2, 80);

    // Print character details
    std::cout << character1.print() << std::endl;
    std::cout << character2.print() << std::endl;

    // Get the distance between characters
    double distance = character1.distance(&character2);
    std::cout << "Distance between characters: " << distance << std::endl;

    // Hit character2
    character2.hit(20);

    // Print updated character details
    std::cout << character1.print() << std::endl;
    std::cout << character2.print() << std::endl;
    /*end character class*/

    /*Cowboy class*/
    Cowboy cowboy1("John", Point(1, 1));
    Cowboy cowboy2("Bob", Point(2, 2));

    cout << cowboy1.print() << endl; // Output: C: Name: John. Hit points: 110. Location: (1, 1)
    cout << cowboy2.print() << endl; // Output: C: Name: Bob Hit points: 110. Location: (2, 2)

    try {
        cowboy1.shoot(&cowboy2);
        cout << "Cowboy1 shoots cowboy2!" << endl;
        cout << "Remaining bullets: " << cowboy1.getBullet() << endl; // Output: 5
        for (int i = 0; i <5 ; ++i) {
            cowboy1.shoot(&cowboy2);
        }
        cout << "Remaining bullets: " << cowboy1.getBullet() << endl; // Output: 0
        cout << "Bob hit points: " << cowboy2.getHitPoints() << endl; // Output: 0

        cout << cowboy2.print() << endl; // Output: (Bob)

        cowboy2.reload();
        cout << "Cowboy2 reloads!" << endl;
        cout << "Remaining bullets: " << cowboy2.getBullet() << endl; // Output: 6
    } catch (const runtime_error& error) {
        cout << "Error: " << error.what() << endl;
    }
    /*end cowboy class*/
    return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack.

}
