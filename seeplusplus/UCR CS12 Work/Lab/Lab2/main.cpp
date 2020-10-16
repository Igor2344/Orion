#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function


using namespace std;

int fileSum(string name);

int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: " ;
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

int fileSum(string name){
    ifstream inFS;
    int sum = 0;
    int r = 0;
    inFS.open(name);
    
    if(!inFS.is_open()){
        cout << "Error opening " << name << endl;
        exit(1);
    }
    while(inFS >> r){
    //inFS >> r;
    sum = sum + r;
    }
    return sum;
}