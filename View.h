#ifndef VIEW__H
#define VIEW__H

#include<vector>

using std::vector;

class View{
public:
    View(){
        sigils = new char[2];
        sigils[0] = 'X';
        sigils[1] = 'Y';
    }
    ~View(){}
    virtual void display(vector<int> board);
    void gameOver(int turn);
private:
    char* sigils;
};





#endif
