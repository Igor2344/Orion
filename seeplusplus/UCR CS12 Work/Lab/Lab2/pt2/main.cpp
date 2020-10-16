#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

int charCnt(string name, char c);


int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

int charCnt(string name, char c){
    ifstream fin;
    string letters;
    int count = 0;
    fin.open(name);
    
    if(!fin.is_open()){
        cout << "Error opening " << name << endl;
        exit(1);
    }
    while(getline(fin, letters)){
    for(unsigned i = 0; i < letters.size(); ++i){
        if(c == letters.at(i)){
            count++;
        }
    }
    }
    return count;
}
