#include "player.hpp"

namespace ariel{


Player::Player(const char* name){
  this->name=name;
}
Player::Player(){}

     
int Player::stacksize(){
    return this->hand.size();
}
       
     
int Player::cardesTaken(){
  return this->cardsWin.size();

}
double Player::getWinRate(){
  double winRate=(this->numOfWins/this->gamesPlayed)*100;
  return winRate;
}
Card Player::throwCard(){
  Card temp=hand.back();
  hand.pop_back();
  return temp;

}
string Player::getName(){
  return name;
}
vector<Card> Player :: getHand(){
  return this->hand;
}
 vector<Card> Player :: getCardWin(){
  return this->cardsWin;

 }
 void Player::setHand(Card &card){
  this->hand.push_back(card);
 }
 void Player::setCardWin(Card &card){
  this->cardsWin.push_back(card);
 }

    
}


