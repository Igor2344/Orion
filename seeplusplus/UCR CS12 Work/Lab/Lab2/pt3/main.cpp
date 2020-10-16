#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
    string inputFile;
    string outputFile;
    vector<int> nums;
    int v;
    int avg = 0;
    
   
    // Assign to inputFile value of 2nd command line argument
    inputFile = argv[1];
    // Assign to outputFile value of 3rd command line argument
    outputFile = argv[2];
    // Create input stream and open input csv file.
    ifstream fin;
    fin.open(inputFile);
    // Verify file opened correctly.
    if(!fin.is_open()){
        cout << "Error opening " << inputFile << endl;
        return 1;
    }
    // Output error message and return 1 if file stream did not open correctly.
    
    // Read in integers from input file to vector.
    while(fin >> v){
        nums.push_back(v);
        fin.ignore();
    }
    // Close input stream.
    fin.close();
   
    // Get integer average of all values read in.
    for(unsigned i = 0; i < nums.size(); ++i){
        avg +=nums.at(i);
    }
    avg = avg/(nums.size());
   
    // Convert each value within vector to be the difference between the original value and the average.
    for(unsigned i = 0; i < nums.size(); ++i){
        nums.at(i) = nums.at(i) - avg;
    }
    // Create output stream and open/create output csv file.
    ofstream fout;
    fout.open(outputFile);
    // Verify file opened or was created correctly.
    if(!fout.is_open()){
        cout << "Error opening " << outputFile << endl;
        return 1;
    }
    // Output error message and return 1 if file stream did not open correctly.
   
    // Write converted values into ouptut csv file, each integer separated by a comma.
    for(unsigned i = 0; i < nums.size()-1; ++i){
        fout << nums.at(i) << ",";
    }
    fout << nums.at(nums.size()-1);
   
    // Close output stream.
    fout.close();
    return 0;
}