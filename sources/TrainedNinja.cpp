#include "TrainedNinja.hpp"

using namespace ariel;
using namespace std;
//speed:12 , hit points: 120
TrainedNinja::TrainedNinja():Ninja("trained", Point(), 120 , 12) {}
TrainedNinja::TrainedNinja(string name, const Point& location): Ninja(name,location,120,12){}
