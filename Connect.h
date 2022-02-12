#ifndef CONNECT__H
#define CONNECT__H

#include "View.h"
#include "Controller.h"
#include<set>

class Connect{
public:
    Connect(int dim, int connect);
    ~Connect(){delete v;}
    void updateView(){ v->display(board); }
    void gameOver(int turn){ v->gameOver(turn);}
    
    void play();
    
    
private:
    
    View* v;
    vector<int> board;
    int dim;
    int connect;
    vector<std::set<int> > winSets;
    void fillWinSequences();
    bool matchSequence(std::set<int> moves,int key);
    
};



#endif
