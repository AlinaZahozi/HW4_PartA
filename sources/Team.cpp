#include <iostream>
#include <string>
#include <stdio.h>
#include "Team.hpp"
#include "Team.hpp"
#include "vector"
#include <algorithm>
#include "typeinfo"
using namespace std;

namespace ariel{

    // Constructor
    Team::Team(Character *leader):
    leader(leader){
        if (leader == nullptr) throw invalid_argument("Error: Leader is null");
        team.fill(nullptr);
        add(leader);
    }

    // Copy constructor
    Team::Team(const Team &other) : leader(other.leader){
        int size = team.size();
        for (size_t i = 0; i < size ; i++){
            if (other.team[i] != nullptr) team[i] = other.team[i]->Copy();
        }
    }

    // Copy assignment operator
    Team &Team::operator=(const Team &other){
        return *this;
    }

    // Move constructor
    Team::Team(Team &&other) noexcept : leader(other.leader){
        team = std::move(other.team);
        other.team.fill(nullptr);
    }

    // Move assignment operator
    Team &Team::operator=(Team &&other) noexcept{
        return *this;
    }


    void Team::add(Character *player){
        return;
    }

    void Team::attack(Team *rival){
        return;
    }

    int Team::stillAlive(){
        return 0;
    }

    void Team::print(){
        return;
    }

    Team::~Team(){
        for (size_t i = 0; i < 10; i++){
            if (team[i]) delete team[i];
        }
    }
}