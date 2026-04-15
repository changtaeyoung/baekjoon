#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tree_num, tree_length;
	long long need_length;
	vector<int> tree_arr;
	cin >> tree_num >> need_length;

	for (int i = 0; i < tree_num; i++) {
		cin >> tree_length;
		tree_arr.push_back(tree_length);
	}
	sort(tree_arr.begin(), tree_arr.end());

	int left = 0;
	int right = tree_arr[tree_arr.size() - 1];
	int mid, result = 0;

	while (left <= right) {
		long long sum = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < tree_arr.size(); i++) {
			if (mid < tree_arr[i]) {
				sum += (tree_arr[i] - mid);
			}
		}
		
		if (need_length <= sum) {
			result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << result;
}