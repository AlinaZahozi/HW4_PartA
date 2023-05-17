#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace ariel{

class Point {
    private:
        double x_cordinta;
        double y_cordinta;

    public:
        // Constructors:
        Point();
        Point(double x_cord ,double y_cord);

        // Getters:
        double getX();
        double getY();
        
        // Setters:
        void setX(double x_cord);
        void setY(double y_cord);


        // To string:
        string toString() const;

        double distance(Point other);

        void print();

        Point moveTowards(Point src , Point dst , double dist);
};

}