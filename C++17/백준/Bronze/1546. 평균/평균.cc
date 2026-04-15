#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n, score, max = -1, sum = 0;


	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> score;
		sum += score;
		if (score > max) {
			max = score;
		}
	}

	cout << (double)100 * sum / max / n;
}