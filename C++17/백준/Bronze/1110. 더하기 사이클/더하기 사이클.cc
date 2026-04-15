#include <iostream>

using namespace std;

int main(void) {
	int n = 0;
	cin >> n;
	int a = 0, b = 0;
	int c = 0, d = 0, e = n;
	for (int i = 1;; i++) {
		a = e / 10;
		b = e % 10;
		c = a + b;
		d = c % 10;
		e = b * 10 + d;
		if (e == n) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}