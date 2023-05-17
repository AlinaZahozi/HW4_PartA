#pragma once
#include <iostream>
#include <string>
#include "Character.hpp"
using namespace std;

namespace ariel {

    class Cowboy : public Character {

        private:
            int bullets;

        public:

            // Constructor:
            Cowboy(string name, Point location);

            Character* Copy() const override {
            return new Cowboy(*this);
            }

            // Getter:
            int getBullets();

            // Setter:
            void setBullets(int bul);

            void shoot(Character *rival);
            bool hasboolets();
            void reload();
            string print() override;
    };
}