// This program implements the Monte Carlo Method for estimating the value of PI.
	   
#include <iostream>
#include <cstdlib>
#include <cmath>
   
using namespace std;
   
// given the coordinates of a point (x,y) computes if the point is inside or on the circle 
// centered at origin with radius r. Returns 'true' if it is inside or on the circle, 'false' otherwise.
// DO NOT use the sqrt function here. Just compare to r squared.
bool isInside(double x, double y, double r) {
    bool truf = false;
    
    double distsqr = (x*x) + (y*y);
    if(distsqr <= r*r){
        truf = true;
    }
    return truf;
}

// given s, the size of the side of a square that is centered at the origin, 
// chooses a random coordinates inside the square, and calls isInside function 
// to test if the point is inside the circle or not.
bool throwDart(int s) {
   int x, y; 
   // assign x and y to two random integers between -s/2 and s/2 
    x = (-s/2) + rand() % ((s/2)-(-s/2)+1);
    y = (-s/2) + rand() % ((s/2)-(-s/2)+1);
   //Call the isInside function and return its output. 
    return isInside(x, y, (s/2));
   //You do not have to cast x & y to doubles, it is done automatically.

}

int main() {
   srand(333);
   int side; // this is the side of the square and is also our resolution. 
   int tries;  // this is the number of tries.

   //Ask the user for the size (integer) of a side of the square
    cout << "Please input the size of the square: " << endl;
    cin >> side;
    cout << "Please input the number of tries: " << endl;
    cin >> tries;
    
   //Get the users input using cin

   //Ask the user for the number of tries using cout.
 
   //Get the users input using cin.
 
 
   int inCount = 0; //counter to track number of throws that fall inside the circle

   for(int i = 0; i < tries; ++i) {
      //throw a dart using throwDart method and increment the counter depending on its output.
        if(throwDart(side) == true){
            inCount = inCount + 1;
        }
   }

   //Compute and display the estimated value of PI. Make sure you are not using integer division.
    
    cout << "Pi must be: " << (4.0 * (inCount/static_cast<double>(tries))) << endl;
   return 0;
}