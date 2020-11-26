#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n);

 void pfibo(int n) { //cannot take 0 as input
	 int primes = 0;
	 vector<int> f = { 1,1 };
	 while (primes < n) {
		 f.push_back(f.at(f.size() - 1) + f.at(f.size() - 2)); //adds last two values in vector to form new number, pushes back to end
		 if (isPrime(f.at(f.size() - 1))) { //checks if newly formed number is prime, if so, prints it out
			 primes++;
			 cout << f.at(f.size() - 1);
			 if (primes < n) {
				 cout << ", ";
			 }
		 }
	 }
}

 bool isPrime(int n) {
	 if (n == 2) {
		 return true;
	 }
	 else if (n > 2 && n % 2 != 0) {
		 for (unsigned i = 2; i < n; i++) {
			 if (n % i == 0) {
				 return false;
			 }
		 }
		 return true;
	 }
	 return false;
}

 int main() {
	 int n;
	 cout << "Enter the value for (n): ";
	 cin >> n;
	 cout << endl << "Generated Fibonacci Prime numbers up to (" << n << "): " << endl;
	 pfibo(n);
 }