#include <array>
#include <iostream>
using namespace std;
/*
has index h if atleast h of N papers have h citations

N = 5, index 3,
4,3,0,1,5
iterate through entire array

*/

int h_index(int sz, int arr[]) {
	int index = sz;
	int count = 0;
	for (unsigned j = 0; j < sz; j++) {
		count = 0;
		for (unsigned i = 0; i < sz; i++) {
			if (arr[i] >= index){
				count++;
			}
		}
		if (count < index) {
			index--;
		}
		else {
			return index;
		}
	}
}

int main() {
	int arr[] = { 4, 3, 0, 1, 5 };
	cout << h_index(5, arr);
	return 0;
}