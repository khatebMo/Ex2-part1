#include "doctest.h"
#include <string>
#include <iostream>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include <stdexcept>

using namespace std;
using namespace ariel;

TEST_CASE("test winner "){
    Player p1("rami");
    Player p2("sami"); 
    Game game(p1,p2);
    game.playAll();
    CHECK_NOTHROW(game.printWiner());

}
TEST_CASE("Test stacksize function"){
    Player p1("mor");
    Player p2("nati");
    Game game(p1,p2);
    CHECK(p1.stacksize()==0);//before start the game
    game.playTurn();
    CHECK(p1.stacksize()>0);//after start the game
}
TEST_CASE("Test cardesTaken function"){
    Player p1("mor");
    Player p2("nati");
    Game game(p1,p2);
    CHECK(p1.cardesTaken()==0);//before start the game
    CHECK_NOTHROW(p2.cardesTaken());//before start the game
    game.playAll();
    CHECK(p1.cardesTaken()==52);//at the end there is one winner
    CHECK(p2.cardesTaken()==52);
}
   
TEST_CASE("test printStats function"){
    Player p1("mor");
    Player p2("nati");
    Game game(p1,p2);
    CHECK_NOTHROW(game.printStats());//before start the game
    game.playAll();
    CHECK_NOTHROW(game.printStats());
}
TEST_CASE("test playTurn function"){
    Player p1("mor");
    Player p2("nati");
    Game game(p1,p2);
    CHECK_EQ(p1.cardesTaken(),p2.cardesTaken());
    game.playTurn();
    CHECK_NE(p1.cardesTaken(),p2.cardesTaken());
}
TEST_CASE("test printLog function"){
    Player p1("mor");
    Player p2("nati");
    Game game(p1,p2);
    CHECK_NOTHROW(game.printLog());
    
 }
TEST_CASE("test game"){
    Player p1("mor");
    Player p2("nati");
    Game game(p1,p2); 
    CHECK_NOTHROW(game.playAll());
    CHECK_EQ(p1.stacksize(), 0);
    CHECK_EQ(p2.stacksize(), 0);
    CHECK_GE(p1.cardesTaken(),0);
    CHECK_GE(p2.cardesTaken(),0);
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());

}




