#include "IntVector.h"
#include <iostream>
using namespace std;

int main(){
    IntVector trial = IntVector(10,3);
    if(trial.empty()){
        cout << "trial empty is true" << endl;
    }
    else{
        cout << "trial empty is false" << endl;
    }
    cout << trial.at(4) << endl;
    cout << trial.front() << endl;
    cout << trial.back() << endl;
    
    cout << "before insert " << endl;
    for(unsigned i = 0; i < 10; ++i){
        cout << trial.at(i) << endl;
    }
    cout << endl;
    
    trial.insert(6, 5);
    
    cout << "after insert" << endl;
    for(unsigned i = 0; i < 11; ++i){
        cout << trial.at(i) << endl;
    }
    
    trial.erase(6);
    
    cout << "after erase" << endl;
    for(unsigned i = 0; i < 10; ++i){
        cout << trial.at(i) << endl;
    }
    
    trial.push_back(7);
    
    cout << "after push_back" << endl;
    for(unsigned i = 0; i < 11; ++i){
        cout << trial.at(i) << endl;
    }
    
    trial.pop_back();
    
    cout << "after push_back" << endl;
    for(unsigned i = 0; i < 10; ++i){
        cout << trial.at(i) << endl;
    }
    
    trial.resize(3, 6);
    
    cout << "after resize < sz" << endl;
    for(unsigned i = 0; i < 3; ++i){
        cout << trial.at(i) << endl;
    }
    cout << "cap: " << trial.capacity() << endl;
    
    trial.resize(7, 5);
    
    cout << "after resize > sz but < cap" << endl;
    for(unsigned i = 0; i < 7; ++i){
        cout << trial.at(i) << endl;
    }
    cout << "cap: " << trial.capacity() << endl;
    
    trial.resize(41, 7);
    
    cout << "after resize > cap" << endl;
    for(unsigned i = 0; i < 41; ++i){
        cout << trial.at(i) << endl;
    }
    cout << "cap: " << trial.capacity() << endl;
    return 0;
}