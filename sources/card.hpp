#pragma once
#include <iostream>

namespace ariel{
  using namespace std;

class Card{
    private:
      int value;
      string type;
    public:
        Card(int value,string type);
        Card();
        int getValue();
        string getType();
        string getValueString();
};

}