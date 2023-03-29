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
    game.playTurn();
    CHECK_NOTHROW(game.printWiner());

    CHECK_THROWS(game.printWiner()); // no winner because the game doesn't start
    CHECK_THROWS(game.printLog()); // no logs because the game doesn't start
    CHECK_THROWS(game.printStats()); // no stats because the game doesn't start
    CHECK_THROWS(game.printLastTurn()); // no stats of last turn because the game doesn't start
 

}



