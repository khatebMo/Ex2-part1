#include "game.hpp"
#include "player.hpp"
#include <algorithm>
#include <random>
using namespace std;
namespace ariel{
Game::Game (Player &player1, Player &player2):p1(player1),p2(player2){

    int j=4;
    string shape;
    while (j>0)
    {
        if(j==4)shape="Hearts";
        if(j==3)shape="Spades";
        if(j==2)shape="Clubs";
        if(j==1)shape="Diamonds"; 
        for(int i=2;i<=14;i++){
        this->deck.push_back(Card(convert(i),shape));        
        }
        j--;

    }
    for(Card c:deck){
        cout<<c.getValue()<<c.getType()<<endl;
    }
    this->shuffling();



}
void Game::playAll(){
    while (p1.stacksize()!=0||p2.stacksize()!=0)
    {
        playTurn();
    }
    
}
void Game::playTurn(){
    if (p1.stacksize()==0||p2.stacksize()==0)
    {
        throw "the game is over";
    }
    
    if (&p1==&p2)
    {
        throw "this is the same player!!";
    }    
    Card p1Card=this->p1.throwCard();
    Card p2Card=this->p2.throwCard();
    table.push_back(p2Card);
    table.push_back(p1Card);
    if(p1Card.getValue()>p2Card.getValue()){
        for(Card c:table){
        p1.setCardWin(c);
        }
        table.clear();
        this->winner=p1.getName();
        lastTurn=p1.getName()+" play "+p1Card.getValueString()+" of "+p1Card.getType()+" "+p2.getName()+" play "+p2Card.getValueString()+" of "+p2Card.getType()+" "+winner+" win\n";
        log+=lastTurn;
    }
    else if(p1Card.getValue()<p2Card.getValue()){
        for(Card c:table){
        p2.setCardWin(c);
        }
        table.clear();
        this->winner=p2.getName();
        lastTurn=p1.getName()+" play "+p1Card.getValueString()+" of "+p1Card.getType()+" "+p2.getName()+" play "+p2Card.getValueString()+" of "+p2Card.getType()+" "+winner+" win\n";
        log+=lastTurn;    
        }
    else{
        lastTurn=p1.getName()+"  play "+p1Card.getValueString()+"  of "+p1Card.getType()+"  "+p2.getName()+"  play "+p2Card.getValueString()+"  of"+p2Card.getType()+"draw ";
        table.push_back(p1.throwCard());
        table.push_back(p2.throwCard());
        log+=lastTurn;
        if(p1.stacksize()==1&&p2.stacksize()){
            p2.setCardWin(table.back());
            table.pop_back();
            p1.setCardWin(table.back());
            table.pop_back();

        }
        if(p1.stacksize()>1||p2.stacksize()>1){
            playTurn();
        }
    }


}
void Game::printLastTurn(){

    cout<<lastTurn<<endl;

}
void Game::printLog(){
   cout<<log<<endl;
    

}
void Game::printStats(){
    string w1 = to_string(p1.getWinRate());
    string d1 = to_string(p1.getWinRate());
    string w2 = to_string(p2.getWinRate());
    string d2 = to_string(p2.getWinRate());
    
    string numOfDraws1;
    cout<<"{ "+p1.getName()+" win rate is: "+w1+ " heeeee" +"draw rate is: "+d1+"he draws "+numOfDraws1+"times"
    +p2.getName()+" win rate is: "+w2+ " heeeee" +"draw rate is: "+d2+"he draws "+"times" +"}"<< endl;

}
void Game::printWiner(){
    this->theWinner="adnan";
    cout<<theWinner<<endl;
    
}
string Game::convert(int n){
    if (n<1||n>13)
    {
        throw "incurruct input";
    }
    
    if (n==14)
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
    random_device r;
    mt19937 f(r());
    shuffle(this->deck.begin(),this->deck.end(),f);
    for (size_t i = 0; i < 52; i++)
    {
        if (i%2==1)
        {
            this->p1.setHand(deck[i]);
        }
        else{
            this->p2.setHand(deck[i]);
        }
        
    }
    
}
int Game::getNumOfDraw(){
    return this->numOfDraw;

}

}
