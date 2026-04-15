#include <iostream>

using namespace std;

int coinarr[10] = {};

int main() {
	int n, k, cnt = 0;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coinarr[i];
		if (coinarr[i] == 0) {
			return -1;
		}
	}
	int j = n-1;
	while (k != 0) {
		if (coinarr[j] > k) {
			j--;
		}
		else {
			cnt += k / coinarr[j];
			k %= coinarr[j];
			j = n-1;
		}
	}
	cout << cnt << endl;
	return 0;
}