#ifndef CONNECT__H
#define CONNECT__H

#include "View.h"
#include "Controller.h"

class Connect{
public:
    Connect(int dim, int connect);
    ~Connect(){delete v;}
    void updateView(){ v->display(board); }
    
    void play();
    
    
private:
    
    View* v;
    vector<int> board;
    int dim;
    int connect;
   // vector< vector<int > > playerMoves;
    
};



#endif
