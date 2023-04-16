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
            string getName();
            Card throwCard();
            int getNumOfWin();
            int getRounds();
            
            void play();
            void winCard();
    };
}
