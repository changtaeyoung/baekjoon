#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	long long n, k, length, low, high, mid = 0, cnt = 0, max = -1, sum = 0;
	cin >> n >> k;
	vector<long long> vec;

	for (int i = 0; i < n; i++) {
		cin >> length;
		vec.push_back(length);
		sum += vec[i];
	}

	sort(vec.begin(), vec.end());
	low = 1;
	high = sum / k;

	while (low <= high) {
		mid = (low + high) / 2;
		for (int i = 0; i < vec.size(); i++) {
			cnt += vec[i] / mid;
		}
		if (cnt >= k) {
			low = mid + 1;
			if (mid > max) {
				max = mid;
			}
		}
		else {
			high = mid - 1;
		}
		cnt = 0;
	}
	cout << max;
	
	return 0;
}