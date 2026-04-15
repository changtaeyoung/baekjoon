#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec;
	int num;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; i++) {
		long long sum = vec[i] * (n - i);
		if (sum > ans)
			ans = sum;
	}
	cout << ans;
	return 0;
}