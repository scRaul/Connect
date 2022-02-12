#ifndef CONTROLLER__H
#define CONTROLLER__H



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
            std::string line ="A";
            while(!isdigit(line[0]) ){
                std::getline(std::cin,line);
            }
            num = atoi(line.c_str());
            it = find (v.begin(),v.end(),num);
        }
        return num;
    }
    
};
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
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
        
        return num;
    }
    
};





#endif
