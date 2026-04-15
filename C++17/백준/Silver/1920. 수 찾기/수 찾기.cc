#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, num;
	vector<int> n_arr, m_arr;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		n_arr.push_back(num);
	}
	sort(n_arr.begin(), n_arr.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		bool inArr = false;
		cin >> num;
		if (binary_search(n_arr.begin(), n_arr.end(), num)) {
			inArr = true;
		}
		if (inArr) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
}