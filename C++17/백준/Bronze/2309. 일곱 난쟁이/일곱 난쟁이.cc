#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int tall[10];
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		int height;
		cin >> height;
		tall[i] = height;
		sum += height;
	}
	sort(tall, tall + 9);
	for (int i = 0; i < 8; i++) {
		for (int j = 1; j < 9; j++) {
			if (sum - (tall[i] + tall[j]) == 100) {
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j) {
						cout << tall[k] << '\n';
					}
				}
				return 0;
			}
		}
	}
	return 0;
}