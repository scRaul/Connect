#include "Include.h"

using std::cout;
using std::endl;

View::View(int playerCount){
    
    sigils = new char[playerCount];
    for(int i = 0; i < playerCount;i++){
        sigils[i] = (char) 'Z' - i;
    }
}

void View::display(vector<int> board){
    int size = board.size();
    int n = sqrt(size);
    int pad = log10(size) + 1;
    for(int i = 0; i < size; i++){
        if(board[i] < 0)
            cout<<std::setw(pad)<<std::right<<sigils[(board[i]*-1) - 1];
        else
            cout<<std::setw(pad)<<std::right<<board[i];
            
        if( (i+1) % n == 0 ){
            cout<<endl;
            if(i < size -1 ){
                int col = (n * pad) + ( 2* (n-1) );
                for(int i = 0; i < col; i++)
                    cout<<":";
                cout<<endl;
            }
        }
        else cout<<"::";
    }
    cout<<endl;
}
void View::gameOver(int turn){
    if(turn)
        cout<<sigils[turn-1] <<" WINS!"<<endl;
    else
        cout<<"DRAW!\n";
}
void View::prompt(int turn){
    cout<<"Player " << sigils[turn-1] <<" choose a slot...\n";
}
