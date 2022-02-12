#ifndef CONNECT__H
#define CONNECT__H

#include "Include.h"
#include "View.h"

using std::vector;
class Connect{
public:
    Connect(int dim, int connect,int playerCount,int bots);
    ~Connect(){delete v;}
    
    void play();
    
    
private:
    
    View* v;
    vector<int> board;
    int dim;
    int connect;
    int playerCount;
    int bots;
    vector<std::set<int> > winSets;
    void fillWinSequences();
    bool matchSequence(std::set<int> moves,int key);
    
};



#endif
