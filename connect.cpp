 #include "Include.h"


using std::set;
Connect::Connect(int dim, int connect,int playerCount,int bots){
    std::string temp = "./wins ";
    temp += std::to_string(dim) +" " + std::to_string(connect);
    temp += " > wins.text";
   
    //cout<<"Executing: "<<temp<<endl;
    const char* cmd = temp.c_str();
    system(cmd);
    //set up game 
    this->dim = dim;
    this->connect = connect;
    this->playerCount = playerCount;
    this->bots = bots;
  
    int size = dim * dim;
    for(int i = 0; i < size; i++){
        board.push_back(i);
    }
    
    fillWinSequences(); // calculate all possible win sequnces 
    
}
 // calculate all possible win sequnces 
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
// if a set of moves exists in the set of win sequnces return true 
// elese return false, @param key is used to filter the winning sets 
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
        Controller *ai = new BaisedAI(controllers.size()+1);
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
        board[pos] = turn *-1; // write the turn to the board as a negative// as current value is positive
        moveCount++; 
        
        moves[turn-1].insert(pos); // keep track of the player moves 
        s = moves[turn -1];  // hold a reference to this set 
        
        // if more than or equal to min amount of moves needed to win 
        if(moveCount >= (playerCount+bots) * (connect-1) + 1){
            game = matchSequence(s,pos); // try a match a winning sequence of moves 
        }
        if(!game)turn++;
        if(turn == playerCount+bots+1) turn = 1;
        if( moveCount == dim*dim && !game){
            game = true;
            turn = 0;
        }
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    v->display(board);  // update the board
    v->gameOver(turn); // check if this turn caused the game to be over
}
