#include "card.hpp"
using namespace std;
Card::Card(string value,string type){
    this->type=type;
    this->value=value;
}
string Card::getType(){
  return this->type;
}
int Card::getValue(){
    if (this->value=="Ace")
    {
        return 1;
    }
    if (this->value=="Two")
    {
        return 2;
    }
    if (this->value=="Three")
    {
        return 3;
    }
    if (this->value=="Four")
    {
        return 4;
    }
    if (this->value=="Five")
    {
        return 5;
    }
    if (this->value=="Six")
    {
        return 6;
    }
    if (this->value=="Seven")
    {
        return 7;
    }
    if (this->value=="Eight")
    {
        return 8;
    }if (this->value=="Nine")
    {
        return 9;
    }
    if (this->value=="Ten")
    {
        return 10;
    }
    if (this->value=="Jack")
    {
        return 11;
    }
    if (this->value=="Queen")
    {
        return 12;
    }
    if (this->value=="King")
    {
        return 13;
    }
    throw "error!";
}
string Card::getValueString(){
    return value;
}

