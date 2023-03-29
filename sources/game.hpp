#ifndef GAME
#define GAME

#include "player.hpp"

// using namespace std;
// namespace ariel{};
// using namespace ariel;
class Game
{

    private:
        Player p1;
        Player p2;
    public:
        Game();
        Game(Player p1,Player p2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
};

#endif
