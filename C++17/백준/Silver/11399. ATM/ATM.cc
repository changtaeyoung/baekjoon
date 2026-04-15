#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int test;
	cin >> test;

	vector<int> vec(test);
	vector<int> sum(test);

	for (int i = 0; i < test; i++) {
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	int sumeach = 0;

	for (int i = 0; i < test; i++) {
		sumeach += vec[i];
		sum[i] = sumeach;
	}

	int ans = 0;
	for (int i = 0; i < test; i++) {
		ans += sum[i];
	}

	cout << ans;
	return 0;
}