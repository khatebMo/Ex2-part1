#pragma once

#include "player.hpp"


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
        bool isDone;
        int rounds;
    
    public:
        Game(Player &player1,Player &player2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();    
        int getNumOfDraw();
        string drawRate(Player &player);
        int winRate(Player &player);
        string state(Player &player);
       
 };
}