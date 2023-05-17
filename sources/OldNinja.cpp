#include "OldNinja.hpp"

using namespace ariel;
using namespace std;
//speed:8 , hit points: 150
OldNinja::OldNinja() :Ninja("Old", Point(), 150, 8){}
OldNinja::OldNinja(string name, const Point& location) : Ninja(name, location, 150, 8){}
OldNinja::~OldNinja(){}