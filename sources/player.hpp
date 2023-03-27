// #ifndef PLAYER
// #define PLAYER
#include <string>
#include <stdio.h>
#include <stack>
#include "card.hpp"
using namespace std;
namespace ariel{}
using namespace ariel;
using namespace std;

class player
{ 
 
private:
    string name;
    int NumOfCardWin;
    stack <card> AllCards; 
    void stacksize();
    void cardesTaken();
    stack<adanan> s;
public:
    player(string name);
    player();
    
};












//#endif
