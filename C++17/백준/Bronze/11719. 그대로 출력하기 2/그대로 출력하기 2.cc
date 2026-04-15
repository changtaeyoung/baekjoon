#include <iostream>
#include <string>
using namespace std;

int main() {
	string arr[100];
	for (int i = 0; i < 100; i++) {
		getline(cin, arr[i]);
	}
	for (int i = 0; i < 100; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}