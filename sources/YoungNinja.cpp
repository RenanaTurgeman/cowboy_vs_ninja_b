#include "YoungNinja.hpp"

using namespace ariel;
using namespace std;
//speed:14, hit points:100
YoungNinja::YoungNinja() : Ninja("young", Point(), 100, 14){}
YoungNinja::YoungNinja(string name, Point location): Ninja(name,location,100,14){
}
