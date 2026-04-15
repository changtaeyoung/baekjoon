#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n;
	vector<int> vn;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		vn.push_back(num);
	}
	sort(vn.begin(), vn.end());

	cin >> m;
	int num1;
	for (int i = 0; i < m; i++) {
		cin >> num1;
		auto l = lower_bound(vn.begin(), vn.end(), num1);
		auto r = upper_bound(vn.begin(), vn.end(), num1);
		cout << r - l << " ";
	}
	cout << "\n";
	return 0;
}