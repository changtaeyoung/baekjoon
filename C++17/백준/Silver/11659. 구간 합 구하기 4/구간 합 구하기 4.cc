#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int number_cnt, sum_cnt, v1, v2, number;
	cin >> number_cnt >> sum_cnt;

	vector<int> numbers_arr(number_cnt + 1);
	numbers_arr[0] = 0;
	for (int i = 1; i <= number_cnt; i++) {
		cin >> number;
		numbers_arr[i] = numbers_arr[i - 1] + number;
	}

	for (int i = 0; i < sum_cnt; i++) {
		cin >> v1 >> v2;
		cout << numbers_arr[v2] - numbers_arr[v1 - 1] << '\n';
	}
}