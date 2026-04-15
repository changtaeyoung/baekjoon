#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	vector<int> arr;
	vector<int> sort_arr;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
		sort_arr.push_back(num);
	}

	sort(sort_arr.begin(), sort_arr.end());
	
	sort_arr.erase(unique(sort_arr.begin(), sort_arr.end()), sort_arr.end());

	for (int i = 0; i < n; i++) {
		int idx = lower_bound(sort_arr.begin(), sort_arr.end(), arr[i]) - sort_arr.begin();
		cout << idx << ' ';
	}
}