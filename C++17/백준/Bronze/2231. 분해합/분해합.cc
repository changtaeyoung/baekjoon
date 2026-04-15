#include <iostream>

using namespace std;

int sum(int num) {
	int sum = 0;
	while (num > 0) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		if ((i + sum(i)) == n) {
			cout << i;
			return 0;
		}
	}
	cout << "0";
	return 0;
}