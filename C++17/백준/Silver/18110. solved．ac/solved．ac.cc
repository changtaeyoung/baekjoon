#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}

	vector<int> vec(n);
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		vec[i] = num;
	}

	float ex = n * 0.15;
	ex = round(ex);
	sort(vec.begin(), vec.end());

	int sum = 0;
	for (int i = ex; i < n - ex; i++) {
		sum += vec[i];
	}

	float res = sum / (double)(n - 2*ex);
	res = round(res);

	cout << res;
	return 0;
}