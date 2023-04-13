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
        vector<Card> table;
        vector<string> turns;
        string lastTurn;
        string winner;
        vector<Card> deck;
        void shuffling();
    public:
        Game();
        Game(Player &p1,Player &p2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        string convert(int n);
};

#endif
