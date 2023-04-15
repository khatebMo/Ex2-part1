#ifndef GAME
#define GAME

#include "player.hpp"

// using namespace std;
// 
// using namespace ariel;
namespace ariel{
 class Game
 {

    private:
        Player &p1;
        Player &p2;
        vector<Card> table;
        string log;
        string lastTurn;
        string winner;
        vector<Card> deck;
        void shuffling();
        int numOfDraw;
        string theWinner;
    public:
        Game(Player &player1,Player &player2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        string convert(int n);
        int getNumOfDraw();
 };
}
#endif
