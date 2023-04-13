#ifndef PLAYER
#define PLAYER
#include <string>
#include <stdio.h>
#include <stack>
#include "card.hpp"
#include <vector>
using namespace std;
namespace ariel
{
};
using namespace ariel;

class Player
{

private:
    string name;
    int NumOfCardWin;
   
    int numOfWins;
    int gamesPlayed;

public:
     vector<Card> hand;
    int numOfDraws;
    vector<Card> cardsWin;
    Player(const string &name);
    Player();
    int stacksize();
    int cardesTaken();
    double getWinRate();
    string getName();
    Card throwCard();
};

#endif
