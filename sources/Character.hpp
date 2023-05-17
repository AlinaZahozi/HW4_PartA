#pragma once
#include <iostream>
#include <string>
#include "Point.hpp"
using namespace std;

namespace ariel{

class Character {
    private:

        string name;
        Point location;
        int hit_points;
        bool is_alive;

    public:
        // Constructors:
        Character();
        Character(string name, Point location, int hit_points);
        Character(const Character &other);
        Character(Character &&other) noexcept;

        Character &operator=(const Character &other);
        Character &operator=(Character &&other) noexcept;

        virtual Character* Copy() const = 0;
        
        // distructor:
        virtual ~Character();

        // Getters:
        string getName();
        Point getLocation();
        int getHit_points();

        // Setters:
        void setName(string);
        void setLocation(Point);
        void setHit_points(int);


        // To string:
        string toString() const;

        bool isAlive();
        double distance(Character *other);
        void hit(int points);
        virtual string print();

        virtual const std::type_info& getType() const;
};
}