#ifndef CARD_HPP
#define CARD_HPP
#include <iostream>
using namespace std;
namespace ariel{

class Card{
    private:
      string value;
      string type;
    public:
        Card(string value,string type);
        Card();
        int getValue();
        string getType();
        string getValueString();
};

}
#endif