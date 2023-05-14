#include "TrainedNinja.hpp"

using namespace ariel;
using namespace std;

TrainedNinja::TrainedNinja(string name, Point location): Ninja(name,location,150,8){

}

string TrainedNinja::print() {
    return "hi";
}

ostream& ariel::operator<<(std::ostream& ostream, const TrainedNinja& trainedNinja){
    return  ostream;
}