#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int sevenish_number(int in){
    vector<int> pof7 = {1};
    int powcont = 1;
    int temp;
    int tempsize;
    while(pof7.size() <= in){
        pof7.push_back(pow(7, powcont));
        temp = pof7.at(pof7.size()-1);
        tempsize = pof7.size(); // yup because otherwise the for loop below would keep changing
        for(unsigned i = 0; i < tempsize-1; i++){
            pof7.push_back(temp + pof7.at(i) );
        }
        powcont++;
    }
    return pof7.at(in-1);
}

int main(){
    cout << sevenish_number(1) << endl;
    cout << sevenish_number(2) << endl;
    cout << sevenish_number(3) << endl;
    cout << sevenish_number(4) << endl;
    cout << sevenish_number(5) << endl;
    cout << sevenish_number(6) << endl;
    cout << sevenish_number(7) << endl;
    cout << sevenish_number(8) << endl;
    cout << sevenish_number(9) << endl;
    cout << sevenish_number(10) << endl;
}