#pragma once
#include <iostream>
#include <string>
#include "Character.hpp"
using namespace std;
     

namespace ariel {

    class Ninja : public Character {

        private:

            int speed;
            
        public:

            Ninja(string name,Point location,int hit_points);

            Character* Copy() const override {
                return new Ninja(*this);
            }

            int getSpeed();
            void setSpeed(int speed);
            void move(Character* enemy);
            void slash(Character* enemy);
            string print() override;
            const std::type_info& getType() const override;

    };
}