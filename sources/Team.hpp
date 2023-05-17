#pragma once
#include <iostream>
#include <string>
#include <array>
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
using namespace std;

namespace ariel {

    constexpr int MAXIMUM_PLAYERS = 10;

    class Team {

    private:
        std::array<Character*, MAXIMUM_PLAYERS> team;
        Character* leader;

    public:
        Team(Character* leader);
        Team(const Team& other);
        Team(Team&& other) noexcept;

        virtual ~Team();

        Team& operator=(const Team& other);
        Team& operator=(Team&& other) noexcept;

        virtual void add(Character* warrior);
        //std::array<Character*, MAXIMUM_PLAYERS>& getMembers();
        //void sortByType();
        void attack(Team* enemies);
       // size_t findClosestLivingMemberIndex();
       // Character* getTeamLeader();
       // Character* findClosestLivingMember();
       /// int didNotAttacked();
       // void setAttackedParam();
       // Character* findClosestVictim(Team* enemies);
        //void killVictim(Team* enemies);
       //// bool isCowboy(Character* warrior);
       // bool isNinja(Character* warrior);
        virtual int stillAlive();
        virtual void print();
    };
}