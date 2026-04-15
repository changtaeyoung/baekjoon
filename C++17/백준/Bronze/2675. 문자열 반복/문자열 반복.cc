#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int t, r;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> r;
		string arr;
		cin >> arr;
		
		for (int j = 0; j < arr.length(); j++) {
			for (int k = 0; k < r; k++) {
				cout << arr[j];
			}
		}
		cout << "\n";
	}
	return 0;
}
