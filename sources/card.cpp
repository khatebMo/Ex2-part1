#include "card.hpp"
using namespace std;
namespace ariel{

    Card::Card(){}
    
    Card::Card(int value,string type){
        this->type=type;
        this->value=value;
    }

    string Card::getType(){
    return this->type;
    }

    int Card::getValue(){
        return this->value;
    }

    string Card::getValueString(){

            string str;
            if(this->getValue() == 14){
                str = "Ace";
            }
            else if(this->getValue() == 13){
                str = "King";
            }
            else if(this->getValue() == 12){
                str = "Queen";
            }
            else if(this->getValue() == 11){
                str = "Jack";
            }
            else{
                str = to_string(this->value);
            }
        return str;
    }
}