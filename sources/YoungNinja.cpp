#include "YoungNinja.hpp"

using namespace ariel;
using namespace std;

YoungNinja::YoungNinja(string name, Point location): Ninja(name,location,150,8){

}

string YoungNinja::print() {
    return "hi";
}

ostream& ariel::operator<<(std::ostream& ostream, const YoungNinja& youngNinja){
    return  ostream;
}