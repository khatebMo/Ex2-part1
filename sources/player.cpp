#include "player.hpp"

namespace ariel{

  Player::Player(){}

  Player::Player(const char *name){
    this->name = name;
  }

  string Player::getName(){
    return this->name;
  }

  vector<Card> Player::getHand(){
    return this->hand;
  }

  vector<Card> Player::getCardWin(){
    return this->cardsWin;
  }

  void Player::setHand(Card &card){
    this->hand.push_back(card);
  }

  void Player::setCardWin(Card &card){
    this->cardsWin.push_back(card);
  }

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
  void Player::win(){
    this->numOfWins++;
  }

  

  Card Player::throwCard(){
    Card card = this->hand.back();
    this->hand.pop_back();
    return card;
  }
  int Player::getNumOfWin(){
    return this->numOfWins;
  }
  int Player::getRounds(){
    return gamesPlayed;
  }
}


