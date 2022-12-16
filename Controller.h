#ifndef CONTROLLER__H
#define CONTROLLER__H

#include "cmath" 

using std::vector;
class Controller{
public:
    Controller(){};
    virtual int getInput(vector<int> v)=0;
    
    
};

class UserInput: public Controller{
public:
    UserInput(){};
    int getInput(vector<int> v){
        int num = 0;
        std::vector<int>::iterator it = v.end();
        while(it == v.end()){
            std::string line ="A"; // to start the loop 
            while(!isdigit(line[0]) ){
                std::getline(std::cin,line);
            }
            num = atoi(line.c_str());
            it = find (v.begin(),v.end(),num);
        }
        return num;
    }
    
};

// PICKS A RANDOM NUMBER GIVEN A LIST OF VECTORS 
class AI:public Controller{
    
public:
    AI(){};
    int getInput(vector<int> v){
        srand(time(0));
        int num = 0;
        std::vector<int>::iterator it = v.end();
        while(it == v.end()){
            num = rand() % v.size();
            it = find (v.begin(),v.end(),num);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        
        return num;
    }
    
};

class BaisedAI : public Controller{

    int id; // holds a reference to which number it is . 

public:
    BaisedAI(int id): id(-id) {};
    int getInput(vector<int> v){
        int n =  sqrt(v.size());
        int row = getMaxRow(v,n); 
        int col = getMaxCol(v,n); 
        std::vector<int>::iterator it = v.end();
        int choice = 0; 

        if(row == col == 0){
            row = rand() % n; 
            col = rand() % n;
        }  
        int misses = -1;
        while(it == v.end()){
            misses++;
            if(row > col)
                choice = row*n + rand() % n;
            else 
                choice = (rand() % n ) * n + col;
            it = find (v.begin(),v.end(),choice);  
            if(misses % 10 == 0){
                row = rand() % n; 
                col = rand() % n;
            }

        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        return choice; 
    }
    int getMaxRow(vector<int> v,int rows){
        int maxScore = 0; 
        int maxRow  = 0; 
        for(int i = 0; i < rows; i++){
            int score = 0; 
            for(int j = 0; j < rows; j++){
                int index = i * rows + j; 
                if(v[index] == id){
                    score++; 
                }
            }
            if(score > maxScore){
                maxScore = score;
                maxRow  = i; 
            }

        }
        return maxRow; 
    }
      int getMaxCol(vector<int> v,int col){
        int maxScore = 0; 
        int maxRow  = 0; 
        for(int i = 0; i < col; i++){
            int score = 0; 
            for(int j = 0; j < col; j++){
                int index = j * col + i; 
                if(v[index] == id){
                    score++; 
                }
            }
            if(score > maxScore){
                maxScore = score;
                maxRow  = i; 
            }

        }
        return maxRow; 
    }

    
};






#endif
