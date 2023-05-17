#include "doctest.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include "sources/Team.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("Test 1 - Test Point class"){
   Point p(32.3,864.9);
   CHECK(p.getX() == 32.3);
   CHECK(p.getY() == 864.9);

   p.setX(-6.4);
   p.setY(0);

   CHECK(p.getX() == -6.4);
   CHECK(p.getY() == 0);

   Point p2(2.6,-3);
   CHECK(p.distance(p2) == 9.486832981);
   CHECK(p.distance(p2) == p2.distance(p));

   Point p3(30.321,864.9);
   Point p4 = p.moveTowards(p,p2,5.0);

   CHECK(p4.getX() == 30.321);
   CHECK(p4.getY() == 864.9);

   CHECK_THROWS(p.moveTowards(p,p2,1.0));
}

TEST_CASE("Test 2 - Test character classes"){

    Point p1(1,2) , p2(-3,4) , p3(-5,-6) , p4(7,-8);

    Cowboy *yen = new Cowboy("Yen", p1);

    CHECK(yen->getName() == "Yen");
    Point ans = yen->getLocation();
    CHECK(ans.getX() == p1.getX());
    CHECK(ans.getY() == p1.getY());
    CHECK(yen->getHit_points() == 110);
    CHECK(yen->getBullets() == 6);
    CHECK(yen->isAlive());

    OldNinja *yon = new OldNinja("Yon", p2);
    CHECK(yon->getName() == "Yon");
    ans = yon->getLocation();
    CHECK(ans.getX() == p2.getX());
    CHECK(ans.getY() == p2.getY());
    CHECK(yon->getHit_points() == 150);
    CHECK(yon->getSpeed() == 8);
    CHECK(yon->isAlive());
    CHECK_NOTHROW(yon->hit(10));
    
    YoungNinja *yan = new YoungNinja("Yan", p3);
    CHECK(yan->getName() == "Yan");
    ans = yan->getLocation();
    CHECK(ans.getX() == p3.getX());
    CHECK(ans.getY() == p3.getY());
    CHECK(yan->getHit_points() == 100);
    CHECK(yan->getSpeed() == 14);
    CHECK(yan->isAlive());
    CHECK_NOTHROW(yon->hit(10));

    TrainedNinja*yin = new TrainedNinja("Yin", p4);
    CHECK(yin->getName() == "Yin");
    ans = yin->getLocation();
    CHECK(ans.getX() == p4.getX());
    CHECK(ans.getY() == p4.getY());
    CHECK(yin->getHit_points() == 120);
    CHECK(yin->getSpeed() == 12);
    CHECK(yin->isAlive());
    CHECK_NOTHROW(yon->hit(10));

    CHECK(yen->distance(yon) == 4.47);
    CHECK(yen->distance(yan) == 10);
    CHECK(yen->distance(yin) == 11.66);
    CHECK(yon->distance(yen) == 4.47);
    CHECK(yon->distance(yan) == 10.2);
    CHECK(yon->distance(yin) == 15.62);
    CHECK(yan->distance(yen) == 10);
    CHECK(yan->distance(yon) == 10.2);
    CHECK(yan->distance(yin) == 12.17);
    CHECK(yin->distance(yen) == 11.66);
    CHECK(yin->distance(yon) == 15.62);
    CHECK(yin->distance(yan) == 12.17);

    bool ans1 = yen->hasboolets();
    CHECK(ans1);

    for(int i = 0 ; i < 6 ; i++){
        yen->shoot(yon);
    }

    bool ans2 = yen->hasboolets();
    CHECK_FALSE(ans2);
    CHECK_THROWS(yen->shoot(yon));
    CHECK_NOTHROW(yen->reload());
    CHECK(yen->getBullets() == 6);

    CHECK_NOTHROW(yon->move(yen));
    CHECK_NOTHROW(yan->move(yen));
    CHECK_NOTHROW(yin->move(yen));

    CHECK_NOTHROW(yon->slash(yan));
    CHECK_NOTHROW(yan->slash(yen));
    CHECK_NOTHROW(yin->slash(yan));
}

TEST_CASE("Test 3 - Test team classes"){

    Point p1(1,2) , p2(-3,4) , p3(-5,-6) , p4(7,-8);

    Cowboy *yen = new Cowboy("Yen", p1);
    OldNinja *yon = new OldNinja("Yon", p2);
    YoungNinja *yan = new YoungNinja("Yan", p3);
    TrainedNinja*yin = new TrainedNinja("Yin", p4);

    Team team1(yen);
    team1.add(yan);
    Team team2(yon);
    team2.add(yin);

    CHECK(team1.stillAlive() > 0);
    CHECK(team2.stillAlive()> 0);

    while((team1.stillAlive() > 0) && (team2.stillAlive()> 0)){
        CHECK_NOTHROW(team1.attack(&team2));
        CHECK_NOTHROW(team2.attack(&team1));
    }
    CHECK_THROWS(team1.attack(&team2));
    CHECK_THROWS(team2.attack(&team1));
    
}