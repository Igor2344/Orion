#include <iostream>
using namespace std;

#include "IntList.h"

int main() {
    cout << "\nlist1 constructor called" << endl;
    IntList list1;
    list1.push_front(30);
    list1.push_front(10);
    list1.push_front(20);
    list1.push_front(20);
    cout << "list1: " << list1 << endl;
    list1.remove_duplicates();
    cout << "list1a: " << list1 << endl;
   return 0;
}
