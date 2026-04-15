#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	int m, n;
	cin >> m >> n;
	int sum = 0, cnt = 0;
	vector<int> vec;
	for (int i = m; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) {
				cnt++;
			}
		}
		if (cnt == 2) {
			vec.push_back(i);
		}
		cnt = 0;
	}

	if (vec.size() == 0) {
		cout << "-1";
	}
	else {
		for (int i = 0; i < vec.size(); i++) {
			sum += vec[i];
		}
		cout << sum << "\n";
		cout << vec[0];
	}

	return 0;
}