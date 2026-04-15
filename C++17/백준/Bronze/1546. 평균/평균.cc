#include <iostream>

using namespace std;

int main(void) {

	int n = 0;
	cin >> n;
	int score = 0;
	float sum = 0;
	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> score;
		sum += score;
		if (score > max) {
			max = score;
		}
	}

	cout << 100.0 * sum / n / max << endl;
}