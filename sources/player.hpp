#pragma once
#include "card.hpp"
#include <string>
#include <vector>

namespace ariel{
    class Player
    {

        private:
            string name;
            int NumOfCardWin;
            int numOfWins;
            int gamesPlayed;
            vector<Card> hand;
            vector<Card> cardsWin;
            string state;
        public:            
            Player(const char *name);
            Player();
            vector<Card> getHand();
            vector<Card> getCardWin();
            void setHand(Card &card);
            void setCardWin(Card &card);
            int stacksize();
            int cardesTaken();
            double getWinRate();
            double getDrawRate();
            string getName();
            Card throwCard();
            void win();
            int getNumOfWin();
            int getRounds();
    };
}
