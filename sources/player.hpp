#ifndef PLAYER
#define PLAYER
#include <string>
#include <iostream>
#include "card.hpp"
#include <vector>
using namespace std;
namespace ariel
{
class Player
{

private:
    string name;
    int NumOfCardWin;
    int numOfWins;
    int gamesPlayed;
    vector<Card> hand;
    vector<Card> cardsWin;
public:
    vector<Card> getHand();
    vector<Card> getCardWin();
    void setHand(Card &card);
    void setCardWin(Card &card);
    Player(const char* name);
    Player();
    int stacksize();
    int cardesTaken();
    double getWinRate();
    double getDrawRate();
    string getName();
    Card throwCard();
};
}
#endif
