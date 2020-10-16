#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      const Rational add(const Rational &additive) const; 
      const Rational subtract(const Rational &subtractive) const; 
      const Rational multiply(const Rational &multiplier) const; 
      const Rational divide(const Rational &divisor) const;
      void simplify();
      void display() const;
   private:
      int gcd(int n, int d) const;
};

// Implement Rational class member functions here
Rational::Rational(int n, int d){
    numerator = n;
    denominator = d;
}
Rational::Rational(int n){
    numerator = n;
    denominator = 1;
}
Rational::Rational(){
    numerator = 0;
    denominator = 1;
}

const Rational Rational::add(const Rational &additive) const{
    return Rational(numerator*additive.denominator + denominator*additive.numerator, denominator*additive.denominator);
    
}
const Rational Rational::subtract(const Rational &subtractive) const{
    return Rational(numerator*subtractive.denominator - denominator*subtractive.numerator, denominator*subtractive.denominator);
}
const Rational Rational::multiply(const Rational &multiplier)const{
    return Rational(numerator*multiplier.numerator, denominator*multiplier.denominator);
}
const Rational Rational::divide(const Rational &divisor)const{
    return Rational(numerator*divisor.denominator, denominator*divisor.numerator);
}
void Rational::display() const{
    cout << this->numerator << " / " << this->denominator;
}
int Rational::gcd(int n, int d)const{
    int r;
    while(d != 0){
        r = n%d;
        n = d;
        d = r;
    }
    return n;
}
void Rational::simplify(){
    int gcd1;
    gcd1 = gcd(numerator, denominator);
    
    numerator = numerator/gcd1;
    denominator = denominator/gcd1;
}

// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

