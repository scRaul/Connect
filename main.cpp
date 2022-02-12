#include "Connect.h"


using std::cout;
using std::cin;
void menu();
int getMode();
void howTo();
Connect * setUp();

int main(){
    
    Connect* c = setUp();
    c->play();
    return 0;
}
void menu(){
    cout<<"\n\n\n";
    cout<<"\t\tCONNECT\n";
    cout<<"\n\t1) single player \n\t2) multiplayer\n\t3) how to play\n";
    cout<<"\n\tenter a game mode\n";
}
int getMode(){
    menu();
    char game = '-';
    while( game != '1' && game != '2'){
        cin >> game;
        if(game == '3'){
            howTo();
            cin>>game;
            menu();
        }
    }
    return game - 48;
}
void howTo(){
    View v(3);
    vector<int > board;
    for(int i = 0; i < 9; i++){
        board.push_back(i);
    }
    board[0] = board[4] = board[8] = -2;
    board[1] = board[6] = -3;
    cout<<"\n\n\n";
    cout<<"\t\tHOW TO PLAY\n";
    cout<<"The goal is to connect n letters in a row\nthis can be done, horizontal, vertical, or \ndiagonal wise\nFor example if playing on a 4 x 4 board,with the goal\nof connecting 4, one way to win would look like this\n\n";
    v.display(board);
    cout<<"Y WINS!\n";
    
    cout<<"\npress any key to go back to menu\n ";
}
Connect * setUp(){
    int mode = getMode();
    int bots=0,players=1,n=3, count=3;
    std::string p = "p";
    if(mode == 2){
        cout<<"Enter number of many players (1-26): ";
        while(!isdigit(p[0])){
            cin >> p;
        }
        players = atoi(p.c_str());
    }
    p = "p";
    if(players < 10){
        cout<<"Enter number of bots (0-10):";
        while(!isdigit(p[0])){
            cin >> p;
        }
        bots = atoi(p.c_str());
    }
    p = "p";
    cout<<"Enter n x n dimension (3 - 25): ";
    while(!isdigit(p[0])){
        cin >> p;
    }
    n =atoi(p.c_str());
    p = "p";
    cout<<"Enter number of connections to win (3 - 25): ";
    while(!isdigit(p[0])){
        cin >> p;
    }
    count =atoi(p.c_str());
    cout<<"\n\n\n";
    Connect *c = new Connect(n,count,players,bots);
    return c;
}
