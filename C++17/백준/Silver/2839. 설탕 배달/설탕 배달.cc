#include <iostream>

using namespace std;

int main(void) {
	int weight;
	int x, y;
	cin >> weight;
	x = weight / 5;

	while (true) {
		if (x < 0) {
			cout << "-1" << endl;
			break;
		}

		if ((weight - (5 * x)) % 3 == 0) {
			y = (weight - (5 * x)) / 3;
			cout << x + y << endl;
			break;
		}
		x--;
	}
	return 0;
}