#include "Connect.h"





Connect::Connect(int dim, int connect){
//    string temp = "./wins 7 9 > wins.text";
//    temp[7] = boardDim + 48;
//    temp[9] = connectToWin + 48;
//    //cout<<"Executing: "<<temp<<endl;
//    const char* cmd = temp.c_str();
//    system(cmd);
    
    v = new View();
    this->dim = dim;
    this->connect = connect;
    
    int size = dim * dim;
    for(int i = 0; i < size; i++){
        board.push_back(i);
    }
    
    
    
}

void Connect::play(){
    updateView();
    Controller *p1 = new UserInput();
    Controller *ai = new AI();
    
    int turn = 1;
    while(true){
        Controller *c;
        if( turn == 1)
            c = p1;
        else
            c = ai;
        int pos = c->getInput(board);
        board[pos] = turn * -1;
        updateView();
        turn = 3 - turn;
    }
    
    
    
    
    
}
