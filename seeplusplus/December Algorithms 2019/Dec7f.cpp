#include <iostream>
#include <string>
#include <queue>

using namespace std;

void q() {
	int n;
	cout << "Enter N: ";
	cin >> n;
	queue<string> q;
	queue<string> q2;
	queue<string> q3;
	string input;
	string filter;
	string comp;
	cout << endl << "Enter (token no, id): " << endl;
	cin.ignore();
	for (unsigned i = 0; i < n; i++) {
		getline(cin, input);
		q.push(input);
	}
	cout << "Enter k: ";
	cin >> filter;
	comp = q.front(); // "(1, a)"
	int idlength = comp.find(")") - comp.find(" ") - 1; // (5 - 3 = 2) - 1 = 1
	comp = comp.substr(comp.find(" ") + 1, idlength);
	while (comp != filter) {
		q2.push(q.front());
		q.pop();
		if (!q.empty()) {
			comp = q.front(); // "(1, a)"
			int idlength = comp.find(")") - comp.find(" ") - 1; // (5 - 3 = 2) - 1 = 1
			comp = comp.substr(comp.find(" ") + 1, idlength);
		}
	}
	q3.push(q.front());
	q.pop();
	while (!q2.empty()) {
		q3.push(q2.front());
		q2.pop();
	}
	while (!q.empty()) {
		q3.push(q.front());
		q.pop();
	}
	cout << "The order is: " << endl;
	while (!q3.empty()) {
		cout << q3.front() << endl;
		q3.pop();
	}
}

int main() {
	q();
}