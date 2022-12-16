#ifndef VIEW__H
#define VIEW__H

#include "Include.h"

using std::vector;

/*
Takes in a list of integers and dsiplays 
them to the terminal 
based on the value.
*/

class View{
public:
    View(int playerCount);
    ~View(){}
    void display(vector<int> board);
    void gameOver(int turn);
    void prompt(int turn);
private:
    char* sigils;
};





#endif
