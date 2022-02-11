#include "View.h"
#include <cmath>
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;

void View::display(vector<int> board){
    int size = board.size();
    int n = sqrt(size);
    int pad = 2*n / 10 + 1;
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
