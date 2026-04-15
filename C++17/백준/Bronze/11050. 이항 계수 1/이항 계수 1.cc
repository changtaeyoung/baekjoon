#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	int fac1 = 1;
	for (int i = 1; i <= n; i++) {
		fac1 *= i;
	}
	int fac2 = 1;
	for (int i = 1; i <= k; i++) {
		fac2 *= i;
	}
	int fac3 = 1;
	for (int i = 1; i <= n - k; i++) {
		fac3 *= i;
	}
	int res;
	res = fac1 / (fac2 * fac3);
	cout << res << "\n";
	return 0;
}