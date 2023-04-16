#include "game.hpp"
#include <algorithm>
#include <random>

namespace ariel{

    Game::Game(Player &player1,Player &player2):p1(player1),p2(player2){
        this->numOfDraw = 0;
        this->rounds=0;
        this->isDone = false;
        p1.play();
        p2.play();

        int j=4;
        string shape;
        while (j>0)
        {
            if(j==4)shape="Hearts";
            if(j==3)shape="Spades";
            if(j==2)shape="Clubs";
            if(j==1)shape="Diamonds"; 
            for(int i=2; i<=14; i++){
            this->deck.push_back(Card(i,shape));        
            }
            j--;
        }
        this->shuffling();   
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

    void Game::playTurn(){  
        this->rounds++;
        if(isDone){
            throw ("the game is over");
            return;
        }

        if (&p1==&p2){
            throw ("this is the same player!!");
            return;
        } 

        if(this->p1.stacksize() == 0 || this->p2.stacksize() == 0){
            isDone = true;
            return;
        }
        else{
            Card p1Card=this->p1.throwCard();
            Card p2Card=this->p2.throwCard();
            table.push_back(p2Card);
            table.push_back(p1Card);
            if(p1Card.getValue()==2 && p2Card.getValue()==14){
                for(Card c:table){
                    p1.setCardWin(c);
                    p1.winCard();
                }
                table.clear();
                this->winner=p1.getName();
                lastTurn=p1.getName()+" play "+p1Card.getValueString()+" of "+p1Card.getType()+" "+p2.getName()+" play "+p2Card.getValueString()+" of "+p2Card.getType()+" "+winner+" win\n";
                log+=lastTurn;
            }
            else if(p1Card.getValue()==14 && p2Card.getValue()==2){
                for(Card c:table){
                    p2.setCardWin(c);
                    p2.winCard();
                }
                table.clear();
                this->winner=p2.getName();
                lastTurn=p1.getName()+" play "+p1Card.getValueString()+" of "+p1Card.getType()+" "+p2.getName()+" play "+p2Card.getValueString()+" of "+p2Card.getType()+" "+winner+" win\n";
                log+=lastTurn;   
            }
            else if(p1Card.getValue()>p2Card.getValue()){
                for(Card c:table){
                    p1.setCardWin(c);
                    p1.winCard();
                }
                table.clear();
                this->winner=p1.getName();
                lastTurn=p1.getName()+" play "+p1Card.getValueString()+" of "+p1Card.getType()+" "+p2.getName()+" play "+p2Card.getValueString()+" of "+p2Card.getType()+" "+winner+" win\n";
                log+=lastTurn;
            }
            else if(p1Card.getValue()<p2Card.getValue()){
                for(Card c:table){
                    p2.setCardWin(c);
                    p2.winCard();
                }
                table.clear();
                this->winner=p2.getName();
                lastTurn=p1.getName()+" play "+p1Card.getValueString()+" of "+p1Card.getType()+" "+p2.getName()+" play "+p2Card.getValueString()+" of "+p2Card.getType()+" "+winner+" win\n";
                log+=lastTurn;    
                }
            else{
                lastTurn=p1.getName()+"  play "+p1Card.getValueString()+"  of "+p1Card.getType()+"  "+p2.getName()+"  play "+p2Card.getValueString()+"  of "+p2Card.getType()+" draw ";
                numOfDraw++;
                rounds+=2;
                table.push_back(p1.throwCard());
                table.push_back(p2.throwCard());
                log+=lastTurn;
                if(p1.stacksize() == 0 && p2.stacksize() == 0){
                    p2.setCardWin(table.back());
                    table.pop_back();
                    p1.setCardWin(table.back());
                    table.pop_back();
                }
                if(p1.stacksize() == 1 && p2.stacksize() == 1){
                    p2.setCardWin(table.back());
                    table.pop_back();
                    p1.setCardWin(table.back());
                    table.pop_back();
                    p1Card=p1.throwCard();
                    p1.setCardWin(p1Card);
                    p2Card=p2.throwCard();
                    p2.setCardWin(p2Card);
                }
                
                if(p1.stacksize()>1 && p2.stacksize()>1){
                   playTurn();
                }
            }
        }
    }

    void Game::printLastTurn(){
        cout << this->lastTurn << endl;
    }

    void Game::playAll(){
        while(!isDone || this->p1.stacksize() != 0){
            playTurn();
        }
    }

    void Game::printWiner(){
        
        if (this->p1.stacksize() == 0 && this->p2.stacksize() == 0){
            if (this->p1.cardesTaken() > this->p2.stacksize()){
                this->theWinner=p1.getName();
                p1.winCard();
            }
            else if (this->p2.cardesTaken() < this->p1.cardesTaken()){
                this->theWinner=p2.getName();
                p2.winCard();   
            }
            cout << this->theWinner+" won's this game!" << endl;
        }
    }

    void Game::printLog(){
        cout << this->log << endl;
    }

    void Game::printStats(){
        string temp1=state(p1);
        string temp2=state(p2);
        cout<<temp1<<endl;
        cout<<temp2<<endl;
    }

    
    int Game::getNumOfDraw(){
        return this->numOfDraw;
    }
     string Game:: drawRate(Player &player){
        double rate=(numOfDraw/this->rounds)*100;
        string str=to_string(rate);
        return str;

     }
    int Game:: winRate(Player &player){
        int temp=player.cardesTaken()/2;
        int rate=(temp/(1*rounds))*100;
        return rate;
        

    }
    string Game::state(Player &player){
        string str="{\n"+player.getName()+" win rate is: "+ to_string((double)winRate(player))+
        "amount of rounds:" + to_string(rounds)
         +" he won's "+to_string(player.cardesTaken()/2)+ " cards "
        +" draw rate is: "+ drawRate(player)+" he draws "+to_string(numOfDraw)+" times \n"+"}";
        return str;
    }   
}

