#include "Connect.h"


#include<sstream>
#include<fstream>


using std::set;
Connect::Connect(int dim, int connect){
    std::string temp = "./wins ";
    temp += std::to_string(dim) +" " + std::to_string(connect);
    temp += " > wins.text";
   
    //cout<<"Executing: "<<temp<<endl;
    const char* cmd = temp.c_str();
    system(cmd);
    
    v = new View();
    this->dim = dim;
    this->connect = connect;
    
    int size = dim * dim;
    for(int i = 0; i < size; i++){
        board.push_back(i);
    }
    
    fillWinSequences();
    
}

void Connect::play(){
    updateView();
    Controller *p1 = new UserInput();
    Controller *ai = new AI();
    
    set<int> p1Moves;
    set<int> aiMoves;
    
    bool game = false;
    int moveCount = 0;
    
    int turn = 1;
    while(!game){
        Controller *c;
        set<int> s;
        if( turn == 1)
            c = p1;
        else
            c = ai;
        int pos = c->getInput(board);
        moveCount++;
        board[pos] = turn * -1;
        updateView();
        
        if(turn ==1){
            p1Moves.insert(pos);
            s = p1Moves;
        }
        else{
            aiMoves.insert(pos);
            s = aiMoves;
        }
        
        if(moveCount > connect){
            game = matchSequence(s,pos);
        }
        if( moveCount == dim*dim){
            game = true;
            turn = 3;
        }
        
        turn = 3 - turn;
    }
    
    gameOver(turn);
    
    
    
    
    
}
void Connect::fillWinSequences(){
    std::ifstream infile;
    infile.open("wins.text");
    
    if(infile.fail()){
        std::cerr<<"ERROR\n";exit(-1);
    }
    std::string line;
    while(std::getline(infile,line)){
        std::istringstream strm;
        strm.str(line);
        int n;
        std::set<int> t;
        while(strm >> n){
            t.insert(n);
            char ch;
            strm >> ch;
        }
        winSets.push_back(t);
    }
    infile.close();
}

bool Connect::matchSequence(set<int> moves,int key){
    for(int i = 0; i< winSets.size();i++){
        set<int> s = winSets[i];
        if(s.count(key)){
            bool match = true;
            set<int>::iterator k;
            for(k = s.begin(); k != s.end();k++){
                //if a num from win set isnt in moves
                if(!moves.count(*k)){
                    match = false;
                    k = s.end();
                    k--;
                }
            }
            if(match) return true;
        }
    }
    return false;
}
