#include<iostream>
#include<vector>

/*
  Find all posible ways to connect m in a row
 inside of a n x n grid
 @command line arg 1 is the dimension of the grid
 @command line arg 2 is the number of elements to
 connect
 */
using namespace std;


void printVector(vector<int> list, int m){
    if(list.size() >= m){
        int start = 0;
        int end = list.size()-(m-1);
        for(int k = start; k < end; k++){
            for(int l = 0; l < m; l++){
                cout<<list[k + l];
                if(l < m-1)
                    cout<<",";
            }
            cout<<endl;
        }
    }
}
void printHorizontalWins(int n, int m){
    int c = n - ( m - 1);
    for(int i = 0; i < n; i++){
        int base = n * i;
        for(int j = 0; j < c; j++){
            int start = base + j;
            for(int k = 0; k < m; k++){
                cout<<start + k;
                if(k < m-1)
                    cout<<",";
            }
            cout<<endl;
        }
    }
}
void printVerticalWins(int n, int m){
    int c = n - ( m - 1);
    for(int i = 0; i < n; i ++ ){
        int base = 0 + i;
        for(int j = 0; j < c; j++){
            int start = base + (j*n);
            for(int k = 0; k < m; k++){
                cout<<start + (n*k);
                if(k < m-1){
                    cout<<",";
                }
            }
            cout<<endl;
        }
    }
}
void printTDR(int n,int m){
    for(int i = 0; i < n; i++ ){
        int x = i;
        vector<int> list;
        for(int j = 0; j< n; j++){
            x = i + (n+1)*j;
            list.push_back(x);
            if( (x+1) % n == 0)
                j =n;
        }
        printVector(list,m);
    }
}
void printTDL(int n, int m){
    int p = n - 1;
    for(int i = 0; i < n; i++ ){
        int x = i;
        vector<int> list;
        for(int j = 0; j < n; j++){
            x = i +  p * j;
            list.push_back(x);
            if( x / n == (x+p)/n)
                j = n;
        }
        printVector(list,m);
    }
}
void printBDL(int n, int m){
    int s = n*n;
    int e = s - n;
    //-2 to not double count
    for(int i = s-2; i >=e; i--){
        int x = i;
        vector<int> list;
        for(int j = 0; j < n; j++){
            x =i - ((n+1) * j);
            list.push_back(x);
            if( x / n == (x+(n-1))/n)
                j = n;
        }
        printVector(list,m);
    }
}
void printBDR(int n, int m){
    //+1 to not double count
    for(int i = (n*(n-1)+1);i < n*n; i++){
        int x = i;
        vector<int> list;
        for(int j = 0; j < n; j++){
            x =i - ((n-1) * j);
            list.push_back(x);
            if((x+1) % n == 0 )
                j = n;
        }
        printVector(list,m);
    }
}
void printDiagnolWins(int n, int m){
    printTDR(n,m);
    printTDL(n,m);
    printBDL(n,m);
    printBDR(n,m);
}
void printAllPossibleWins(int n, int m){
    printDiagnolWins(n,m);
    printHorizontalWins(n,m);
    printVerticalWins(n,m);
}
int main(int argc,char* argv[]){
    
    if(argc < 3) exit(-1);
    int n = stoi(argv[1]);
    int m = stoi(argv[2]);
    printAllPossibleWins(n,m);
    
    return 0;
}
