#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void readData(const string &fileName, vector<double> &flightPathAngle, vector<double> &coefOfLift);
double interpolation(double flpa, const vector<double> &flightPathAngle, const vector<double> &coefOfLift);
bool isOrdered(const vector<double> &flightPathAngle);
void reorder(vector<double> &flightPathAngle, vector<double> &coefOfLift);

int main(int argc, char *argv[]){
    string inputF;
    string outputF;
    vector<double> fpa;
    vector<double> col;
    
    
    
    inputF = argv[1];
    
    readData(inputF, fpa, col);
}
void readData(const string &fileName, vector<double> &flightPathAngle, vector<double> &coefOfLift){
    ifstream fin;
    double ttemp;
    
    fin.open(fileName);
    if(!fin.is_open()){
        cout << "Error opening " << fileName << endl;
        exit(1);
    }
    while(fin >> ttemp){
        flightPathAngle.push_back(ttemp);
        fin >> ttemp;
        coefOfLift.push_back(ttemp);
    }
    if(flightPathAngle.size() != coefOfLift.size()){
        cout << "Error writing to vectors - uneven size " << endl;
        exit(1);
    }
}

double interpolation(double flpa, const vector<double> &flightPathAngle, const vector<double> &coefOfLift){
    int index1 = 0;
    double a;
    double b = flpa;
    double c;
    double fa;
    double fc;
    for(unsigned i = 0; i < flightPathAngle.size(); ++i){
        if(flightPathAngle.at(i) == flpa){
            return coefOfLift.at(i);
        }
        else if(flightPathAngle.at(i) > flpa){
            index1 = i-1;
        }
    }
    a = flightPathAngle.at(index1);
    c = flightPathAngle.at(index1+1);
    fa = coefOfLift.at(index1);
    fc = coefOfLift.at(index1+1);
    return (fa + ((b-a)/(c-a))*(fc-fa));
}

bool isOrdered(const vector<double> &flightPathAngle){
    bool truf = false;
    if(flightPathAngle.size() >1){
        for(unsigned i = 1; i < flightPathAngle.size(); ++i){
            if(flightPathAngle.at(i) >= flightPathAngle.at(i-1)){
                truf = true;
            }
        }
    }
    else if(flightPathAngle.size() == 0 || flightPathAngle.size() == 1){
        truf = true;
    }
    return truf;
}

void reorder(vector<double> &flightPathAngle, vector<double> &coeOfLift){
    vector<double> newfpa;
    vector<double> newcol;
    int index = 0;
    double low;
    for(unsigned i = 0; i < flightPathAngle.size(); ++i){
        low = flightPathAngle.at(i);
        for(unsigned j = i+1; j < flightPathAngle.size()-1; ++j){
            if(flightPathAngle.at(j) < low){
                low = flightPathAngle.at(j);
                index = j;
            }
        }
        flightPathAngle.at(index) = flightPathAngle.at(i);
        flightPathAngle.at(i) = low;
    }  
}