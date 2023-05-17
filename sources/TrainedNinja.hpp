#pragma once
#include <iostream>
#include <string>
#include "Ninja.hpp"
using namespace std;
     
namespace ariel {

    class TrainedNinja : public Ninja { 

        public:
            TrainedNinja(string name, Point location);

    };
}