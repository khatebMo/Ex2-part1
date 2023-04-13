#include "player.hpp"

using namespace ariel;


Player::Player(const string &name){
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


    



