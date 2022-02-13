#include "Include.h"

using std::cout;
using std::endl;

std::string resetColor(){
    return "\x1B[0;30m";
}
std::string getColor(int i){
    int rgb;
    if(i < 0) i *=-1;
    double c = (sqrt(5)-1 ) /2;
    double x = (i * c);
    rgb =  (int)floor( 230 * ( x - (int)floor(x) ) )+1;
    return "\x1B[0;40;"+ std::to_string(rgb*0+1)+";48;5;"+ std::to_string(rgb)+"m";
}
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
        if(board[i] < 0){
            std::string color = getColor(board[i]);
            cout<<color<<std::setw(pad)<<std::right;
            cout<<sigils[(board[i]*-1)-1];
            cout<<resetColor();
        }
        else
            cout<<std::setw(pad)<<std::right<<board[i];
            
        if( (i+1) % n == 0 ){
            cout<<endl;
            if(i < size -1 ){
                int col = (n * pad) + ( 2* (n-1) );
                for(int i = 0; i < col; i++)
                    cout<<'\x1B' << "[0;40;1m"<<":";
                cout<<resetColor()<<endl;
            }
        }
        else {
            cout<<'\x1B' << "[0;40;1m"<<"::"<<resetColor();
        }
    }
    cout<<endl;
}
void View::gameOver(int turn){
    if(turn)
        cout<<getColor(turn)<<sigils[turn-1] <<resetColor()<<" WINS!"<<endl;
    else
        cout<<"DRAW!\n";
}
void View::prompt(int turn){
    cout<<"Player " << getColor(turn)<<sigils[turn-1] <<resetColor()<<" choose a slot...\n";
}
