#include "Connect.h"


using std::cout;
using std::cin;

void menu();
int getMode();
void howTo();
void colorLogo();
Connect * setUp();


int main(){
    cout<<"adjust terminal width to 101\n";
    Connect* c = setUp();
    c->play();
    return 0;
}
void menu(){
    colorLogo();
    cout<<"\n\t1) Play\n\t3) how to play\n";
    cout<<"\n\tenter a game mode\n";
}
int getMode(){
    menu();
    char game = '-';
    while( game != '1'){
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
    if(mode == 1){
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
    cout<<"Enter board size (3 - 25): ";
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
void colorLogo(){
    std::ifstream infile;
    infile.open("logo.text");
    if(infile.fail()){
        cout<<"missing logo.text file\n";
        exit(1);
    }
    char n;
    while(infile.get(n)){
    switch(n){
        case '#':    cout << '\x1B' << "[0;37;41m"; break;  // white on red
        case '%':    cout << '\x1B' << "[0;37;44m"; break;  // white on blue
        case '&':    cout << '\x1B' << "[0;37;45m"; break;  // white on magenta
        case '(':    cout << '\x1B' << "[0;37;46m"; break;  // white on cyan
        case '*':    cout << '\x1B' << "[0;37;40m"; break;  // white on black
        case ',':    cout << '\x1B' << "[0;31m"; break;     // red on white
        case '/':    cout << '\x1B' << "[0;34m"; break;     // blue on white
        case '@':    cout << '\x1B' << "[0;1;42m"; break;   // bold black on green
        default:
        case 0:    cout << '\x1B' << "[0;30m"; break;  // black on white (default)
    }
        cout<<" ";
    }
}
