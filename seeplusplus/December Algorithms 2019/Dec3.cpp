#include <array>
#include <iostream>

using namespace std;
bool isSorted(int arr[], unsigned sz);

void decimate(int arr[], unsigned sz){
	while (!isSorted(arr, sz)) {
		sz = sz/2;
	}
	for (unsigned i = 0; i < sz; i++) {
		cout << arr[i];
	}
}

bool isSorted(int arr[], unsigned sz) {
	bool isSort = false;
	for (unsigned i = 0; i < sz - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	int nam[] = { 1,2,3,2,1 };
	decimate(nam, 5);
}