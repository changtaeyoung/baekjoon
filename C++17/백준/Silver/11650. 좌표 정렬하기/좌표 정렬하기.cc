#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int test, x, y;
	pair<int, int> co;
	vector<pair<int, int>> co_arr;
	cin >> test;

	for (int i = 0; i < test; i++) {
		cin >> x >> y;
		co.first = x;
		co.second = y;
		co_arr.push_back(co);
	}

	sort(co_arr.begin(), co_arr.end());

	for (int i = 0; i < co_arr.size(); i++) {
		cout << co_arr[i].first << " " << co_arr[i].second << '\n';
	}
}