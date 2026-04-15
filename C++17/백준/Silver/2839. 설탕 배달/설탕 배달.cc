#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	int x, y;
	x = n / 5;
	while (true) {
		if (x < 0) {
			cout << "-1";
			return 0;
		}
		if ((n - (5 * x)) % 3 == 0) {
			y = (n - (5 * x)) / 3;
			break;
		}
		x--;
	}
	cout << x + y;
	return 0;
}