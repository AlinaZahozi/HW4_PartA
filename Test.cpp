// Include necessary libraries and namespaces
#include "doctest.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include "sources/Team.hpp"
using namespace std;
using namespace ariel;

// Test case for Point class
TEST_CASE("Test 1 - Test Point class"){
   // Create a point at given coordinates
   Point p(32.3,864.9);
   // Test that the X and Y coordinates are correctly assigned
   CHECK(p.getX() == 32.3);
   CHECK(p.getY() == 864.9);

   // Change the X and Y coordinates of the point
   p.setX(-6.4);
   p.setY(0);

   // Test that the new X and Y coordinates are correctly assigned
   CHECK(p.getX() == -6.4);
   CHECK(p.getY() == 0);

   // Create another point at new coordinates
   Point p2(2.6,-3);
   // Test the distance calculation between the two points
   CHECK(p.distance(p2) == 9.486832981);
   // Check that the distance from p to p2 is the same as from p2 to p
   CHECK(p.distance(p2) == p2.distance(p));

   // Create a new point
   Point p3(30.321,864.9);
   // Create a new point that moves towards a target point
   Point p4 = p.moveTowards(p,p2,5.0);

   // Test that the X and Y coordinates of the new point are correct
   CHECK(p4.getX() == 30.321);
   CHECK(p4.getY() == 864.9);

   // Test that an exception is thrown when trying to move towards a point at an invalid distance
   CHECK_THROWS(p.moveTowards(p,p2,1.0));
}


// Test case for character classes
TEST_CASE("Test 2 - Test character classes"){

    // Create points for initial locations of characters
    Point p1(1,2) , p2(-3,4) , p3(-5,-6) , p4(7,-8);

    // Create a Cowboy character at location p1
    Cowboy *yen = new Cowboy("Yen", p1);
    
    // Check the properties of the Cowboy character
    CHECK(yen->getName() == "Yen");
    Point ans = yen->getLocation();
    CHECK(ans.getX() == p1.getX());
    CHECK(ans.getY() == p1.getY());
    CHECK(yen->getHit_points() == 110);
    CHECK(yen->getBullets() == 6);
    CHECK(yen->isAlive());

    // Create an OldNinja character at location p2
    OldNinja *yon = new OldNinja("Yon", p2);
    
    // Check the properties of the OldNinja character
    CHECK(yon->getName() == "Yon");
    ans = yon->getLocation();
    CHECK(ans.getX() == p2.getX());
    CHECK(ans.getY() == p2.getY());
    CHECK(yon->getHit_points() == 150);
    CHECK(yon->getSpeed() == 8);
    CHECK(yon->isAlive());
    // Test if hit operation does not throw an exception
    CHECK_NOTHROW(yon->hit(10));
    
    // Create a YoungNinja character at location p3
    YoungNinja *yan = new YoungNinja("Yan", p3);
    
    // Check the properties of the YoungNinja character
    CHECK(yan->getName() == "Yan");
    ans = yan->getLocation();
    CHECK(ans.getX() == p3.getX());
    CHECK(ans.getY() == p3.getY());
    CHECK(yan->getHit_points() == 100);
    CHECK(yan->getSpeed() == 14);
    CHECK(yan->isAlive());
    // Test if hit operation does not throw an exception
    CHECK_NOTHROW(yon->hit(10));

    // Create a TrainedNinja character at location p4
    TrainedNinja*yin = new TrainedNinja("Yin", p4);
    
    // Check the properties of the TrainedNinja character
    CHECK(yin->getName() == "Yin");
    ans = yin->getLocation();
    CHECK(ans.getX() == p4.getX());
    CHECK(ans.getY() == p4.getY());
    CHECK(yin->getHit_points() == 120);
    CHECK(yin->getSpeed() == 12);
    CHECK(yin->isAlive());
    // Test if hit operation does not throw an exception
    CHECK_NOTHROW(yon->hit(10));

    // Check the distance between different characters
    CHECK(yen->distance(yon) == 4.47);  // Distance between yen (Cowboy) and yon (OldNinja)
    CHECK(yen->distance(yan) == 10);     // Distance between yen (Cowboy) and yan (YoungNinja)
    CHECK(yen->distance(yin) == 11.66);  // Distance between yen (Cowboy) and yin (TrainedNinja)
    // Repeat for other characters
    CHECK(yon->distance(yen) == 4.47);
    CHECK(yon->distance(yan) == 10.2);
    CHECK(yon->distance(yin) == 15.62);
    CHECK(yan->distance(yen) == 10);
    CHECK(yan->distance(yon) == 10.2);
    CHECK(yan->distance(yin) == 12.17);
    CHECK(yin->distance(yen) == 11.66);
    CHECK(yin->distance(yon) == 15.62);
    CHECK(yin->distance(yan) == 12.17);

    // Check if Cowboy character yen has bullets
    bool ans1 = yen->hasboolets();
    CHECK(ans1);

    // Simulate Cowboy yen shooting at OldNinja yon 6 times (the amount of bullets yen has)
    for(int i = 0 ; i < 6 ; i++){
        yen->shoot(yon);
    }

    // Check if yen has bullets after shooting, it should be false
    bool ans2 = yen->hasboolets();
    CHECK_FALSE(ans2);

    // Check if yen can shoot without bullets, this should throw an exception
    CHECK_THROWS(yen->shoot(yon));

    // Check if yen can reload without throwing an exception
    CHECK_NOTHROW(yen->reload());

    // Check if yen has 6 bullets after reloading
    CHECK(yen->getBullets() == 6);

    // Check if yon, yan and yin can move towards yen without throwing an exception
    CHECK_NOTHROW(yon->move(yen));
    CHECK_NOTHROW(yan->move(yen));
    CHECK_NOTHROW(yin->move(yen));

    // Check if yon, yan and yin can slash other characters without throwing an exception
    CHECK_NOTHROW(yon->slash(yan));
    CHECK_NOTHROW(yan->slash(yen));
    CHECK_NOTHROW(yin->slash(yan));

}

// Test Case 3: Team classes
TEST_CASE("Test 3 - Test team classes"){

    // Create points for the characters' initial locations
    Point p1(1,2), p2(-3,4), p3(-5,-6), p4(7,-8);

    // Create different character types at their initial locations
    Cowboy *yen = new Cowboy("Yen", p1);
    OldNinja *yon = new OldNinja("Yon", p2);
    YoungNinja *yan = new YoungNinja("Yan", p3);
    TrainedNinja*yin = new TrainedNinja("Yin", p4);

    // Create Team 1 and add character yen and yan to it
    Team team1(yen);
    team1.add(yan);

    // Create Team 2 and add character yon and yin to it
    Team team2(yon);
    team2.add(yin);

    // Check if both teams have members that are still alive
    CHECK(team1.stillAlive() > 0);
    CHECK(team2.stillAlive() > 0);

    // Keep attacking each other's team until one of them has no members left alive
    while((team1.stillAlive() > 0) && (team2.stillAlive() > 0)){
        CHECK_NOTHROW(team1.attack(&team2));
        CHECK_NOTHROW(team2.attack(&team1));
    }

    // At this point one of the teams should have no members left alive
    // So, attacking the defeated team should throw an exception
    CHECK_THROWS(team1.attack(&team2));
    CHECK_THROWS(team2.attack(&team1));
}