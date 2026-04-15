#include <iostream>
#include <algorithm>

using namespace std;
int arr[500001] = { 0, };

int main(void) {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	
	int sum = 0;
	int res1;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	if (sum >= 0) {
		res1 = (int)((double)sum / n + 0.5);
	}
	else {
		res1 = (int)((double)sum / n - 0.5);
	}

	int res2;
	res2 = arr[(n - 1) / 2];

	int res3;
	int cnt = 0;
	int cnt1[8001] = { 0, };
	for (int i = 0; i < n; i++) {
		cnt1[arr[i] + 4000]++;
	}
	int max_mode = *max_element(cnt1, cnt1 + 8001);
	for (int i = 0; i < 8001; i++) {
		if (cnt1[i] == max_mode) {
			cnt++;
			res3 = i - 4000;
		}
		if (cnt == 2) {
			break;
		}
	}

	int res4;
	res4 = arr[n - 1] - arr[0];

	cout << res1 << "\n";
	cout << res2 << "\n";
	cout << res3 << "\n";
	cout << res4 << "\n";
}