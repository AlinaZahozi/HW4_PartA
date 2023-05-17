#include <iostream>
#include <string>
#include <stdio.h>
#include "Cowboy.hpp"


namespace ariel{

    // Constructor:
    Cowboy::Cowboy(string name, Point location): 
    Character(name, location, 110),
    bullets(6){}


    int Cowboy::getBullets() {
        if(isAlive()== false) throw("This cowboy is already dead");
        return bullets;
    }

    void Cowboy::setBullets(int bullet){
        if(isAlive() == false) throw("This cowboy is already dead");
        bullets = bullet;
    }

    void Cowboy::shoot(Character * rival) {
        if(isAlive() == false) throw("This cowboy is already dead");
        else if(bullets <= 0) throw("Run out of bullets");
        else{
            double dist = distance(rival);
            rival->hit(10);
            bullets--;
        }
    }

    bool Cowboy::hasboolets() {
        if(isAlive() == false) throw("This cowboy is already dead");
        return (bullets > 0);
    }

    void Cowboy::reload() {
        if(isAlive() == false) throw("This cowboy is already dead");
        bullets = 6;
    }

    string Cowboy::print() {
        //need to perform
        return "";
    }
}