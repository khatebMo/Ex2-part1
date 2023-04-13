#include "game.hpp"
#include "player.hpp"
#include <algorithm>
using namespace std;
namespace ariel{};

Game::Game(){

}
Game::Game (Player &p1, Player &p2){
    int j=4;
    string shape;
    this->p1=p1;
    this->p2=p2;
    while (j>0)
    {
        if(j==4)shape="Hearts";
        if(j==3)shape="Spades";
        if(j==2)shape="Clubs";
        if(j==1)shape="Diamonds"; 
        for(int i=1;i<=13;i++){
        deck.push_back(Card(convert(i),shape));        
        }
        j--;

    }
    this->shuffling();
    
    if (p1.stacksize()!=26||p2.stacksize()!=26)
    {
        throw"error!";
    }
    //p1.stacksize()=0;


}
void Game::playAll(){
   
    

}
void Game::playTurn(){
    
    
    Card p1Card=this->p1.throwCard();
    Card p2Card=this->p2.throwCard();
    table.push_back(p2Card);
    table.push_back(p1Card);
    if(p1Card.getValue()>p2Card.getValue()){
        // p1.cardsWin.push_back(p1Card);
        // p1.cardsWin.push_back(p2Card);
        p1.cardsWin.insert(p1.cardsWin.end(), table.begin(), table.end());
        table.clear();
        this->winner=p1.getName();
        lastTurn=p1.getName()+"play"+p1Card.getValueString()+"of"+p1Card.getType()+p2.getName()+"play"+p2Card.getValueString()+"of"+p2Card.getType()+winner+"win";
    }
    else if(p1Card.getValue()<p2Card.getValue()){
        // p2.cardsWin.push_back(p1Card);
        // p2.cardsWin.push_back(p2Card);
        p2.cardsWin.insert(p2.cardsWin.end(), table.begin(), table.end());
        table.clear();
        this->winner=p2.getName();
        lastTurn=p1.getName()+"play"+p1Card.getValueString()+"of"+p1Card.getType()+p2.getName()+"play"+p2Card.getValueString()+"of"+p2Card.getType()+winner+"win";
    }
    else{
        p1.numOfDraws++;
        p2.numOfDraws++;
        lastTurn=p1.getName()+"play"+p1Card.getValueString()+"of"+p1Card.getType()+p2.getName()+"play"+p2Card.getValueString()+"of"+p2Card.getType()+"draw";
        table.push_back(p1.throwCard());
        table.push_back(p2.throwCard());
        playTurn();
    }


}
void Game::printLastTurn(){
    cout<<lastTurn;

}
void Game::printLog(){

}
void Game::printStats(){

}
void Game::printWiner(){
    cout<<winner;
    
}
string Game::convert(int n){
    if (n<1||n>13)
    {
        throw "incurruct input";
    }
    
    if (n==1)
    {
        return "Ace";
    }
    if (n==2)
    {
        return "Two";
    }
    if (n==3)
    {
        return "Three";
    }
    if (n==4)
    {
        return "Four";
    }
    if (n==5)
    {
        return "Five";
    }
    if (n==6)
    {
        return "Six";
    }
    if (n==7)
    {
        return "Seven";
    }
    if (n==8)
    {
        return "Eight";
    }if (n==9)
    {
        return "Nine";
    }
    if (n==10)
    {
        return "Ten";
    }
    if (n==11)
    {
        return "Jack";
    }
    if (n==12)
    {
        return "Queen";
    }
    if (n==13)
    {
        return "King";
    }
    throw"incurrct input";
}
void Game::shuffling(){
     int count=0;
     unsigned int index;
     
     for (int i=1;i<27;i++)
     {
       index = (int)rand() % (52 - count);
       count++;
       swap(deck[index],deck[deck.size()-2]);
        p1.hand.push_back(deck.back());
       
     }
     p2.hand.insert(p2.hand.begin(),deck.begin(),deck.end());
      
     
}

