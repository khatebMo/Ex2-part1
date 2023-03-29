#ifndef PLAYER
#define PLAYER
#include <string>
#include <stdio.h>
#include <stack>
#include "card.hpp"
using namespace std;
namespace ariel{};
using namespace ariel;

class Player
{ 
 string name;
    private:
        int NumOfCardWin;
        stack <Card> AllCards; 
    
    public:
        int stacksize();
        int cardesTaken();
        Player(string name);
        Player();
    
};


#endif
