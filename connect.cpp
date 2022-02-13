 #include "Include.h"


using std::set;
Connect::Connect(int dim, int connect,int playerCount,int bots){
    std::string temp = "./wins ";
    temp += std::to_string(dim) +" " + std::to_string(connect);
    temp += " > wins.text";
   
    //cout<<"Executing: "<<temp<<endl;
    const char* cmd = temp.c_str();
    system(cmd);
    
    this->dim = dim;
    this->connect = connect;
    this->playerCount = playerCount;
    this->bots = bots;
  
    int size = dim * dim;
    for(int i = 0; i < size; i++){
        board.push_back(i);
    }
    
    fillWinSequences();
    
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
void Connect::play(){
    v = new View(playerCount + bots);
    
    vector<Controller *> controllers;
    for(int i = 0; i < playerCount;i++){
        Controller *player = new UserInput();
        controllers.push_back(player);
    }
    
    for(int i = 0; i < bots;i++ ){
        Controller *ai = new AI();
        controllers.push_back(ai);
    }
    set<int> moves[playerCount+bots];
    
    bool game = false;
    int moveCount = 0;
    
    int turn = 1;
    while(!game){
        v->display(board);
        v->prompt(turn);
        Controller *c;
        set<int> s;
        c = controllers[turn-1];
        int pos = c->getInput(board);
        board[pos] = turn * -1;
        moveCount++;
        
        moves[turn-1].insert(pos);
        s = moves[turn -1];
        
        
        if(moveCount >= (playerCount+bots) * (connect-1) + 1){
            game = matchSequence(s,pos);
        }
        if(!game)turn++;
        if(turn == playerCount+bots+1) turn = 1;
        if( moveCount == dim*dim && !game){
            game = true;
            turn = 0;
        }
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    v->display(board);
    v->gameOver(turn);
    
    
    
    
    
}
