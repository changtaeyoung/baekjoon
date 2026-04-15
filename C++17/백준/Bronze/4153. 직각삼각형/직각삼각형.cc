#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b, c, temp;
	int max = 0;
	while (1) {
		cin >> a >> b >> c;
		if ((c > a && a > b) || (c > b && b > a)) {
			if (pow(c, 2) == pow(a, 2) + pow(b, 2)) {
				cout << "right" << endl;
			}
			else {
				cout << "wrong" << endl;
			}
		}
		else if ((b > a && a > c) || (b > c && c > a)) {
			if (pow(b, 2) == pow(a, 2) + pow(c, 2)) {
				cout << "right" << endl;
			}
			else {
				cout << "wrong" << endl;
			}
		}
		else if ((a > b && b > c) || (a > c && c > b)) {
			if (pow(a, 2) == pow(c, 2) + pow(b, 2)) {
				cout << "right" << endl;
			}
			else {
				cout << "wrong" << endl;
			}
		}
		else if (a == 0 && b == 0 && c == 0) {
			break;
		}
	}

	return 0;
}