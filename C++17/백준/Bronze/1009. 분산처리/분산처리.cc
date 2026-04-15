#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(void) {
	int test;
	cin >> test;

	int a, b, tmp = 1;
	for (int i = 0; i < test; i++) {
		cin >> a >> b;
		for (int j = 0; j < b; j++) {
			tmp = (tmp * a) % 10;
		}
		if (tmp == 0) {
			cout << "10" << "\n";
		}
		else {
			cout << tmp << "\n";
		}
		tmp = 1;
	}
	return 0;
}