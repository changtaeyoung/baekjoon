#include <iostream>

using namespace std;

int main(void) {
	int a = 0, b = 0, c = 0;
	int max=0;
	cin >> a >> b >> c;
	 
	if (a == b && b == c) {
		cout << 10000 + a * 1000 << endl;
	}
	else if (a != b && b != c && a != c) {
		max = a > b ? a : b;
		max = max > c ? max : c;
		cout << max * 100 << endl;
	}
	else {
		if (a == b) {
			cout << 1000 + a * 100 << endl;
		}
		else if (a == c) {
			cout << 1000 + a * 100 << endl;
		}
		else if (b == c) {
			cout << 1000 + b * 100 << endl;
		}
	}
	return 0;
}