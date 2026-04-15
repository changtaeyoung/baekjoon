#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "1" << "\n";
		return 0;
	}
	int sum = 1;
	for (int i = 0; sum <= 1000000000; i++) {
		sum += 6 * i;
		if (sum >= n) {
			cout << i + 1 << "\n";
			break;
		}
	}
	return 0;
}