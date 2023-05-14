#include "OldNinja.hpp"

using namespace ariel;
using namespace std;

OldNinja::OldNinja(string name, Point location) : Ninja(name, location, 150, 8){

}

string OldNinja::print() {
    return "hi";

}

ostream& ariel::operator<<(ostream& ostream, const OldNinja& oldNinja){
    return  ostream;
}