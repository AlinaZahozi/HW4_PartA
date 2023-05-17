#include <string>
#include <iostream>
#include "Ninja.hpp"
using namespace std;

namespace ariel {

    Ninja::Ninja(string name, Point location, int hit_points):
    Character(name, location, hit_points),
    speed(0){}

    int Ninja::getSpeed(){
        return speed;
    }

    void Ninja::setSpeed(int otherSpeed) {
        speed = otherSpeed;
    }

    const std::type_info& Ninja::getType() const {
        return typeid(Ninja);
    }

    void Ninja::move(Character* rival){}
    
    void Ninja::slash(Character* rival){}

    string Ninja::print() {
        //need to perform
        return "";
    }
}