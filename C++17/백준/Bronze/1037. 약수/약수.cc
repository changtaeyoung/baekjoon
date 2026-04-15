#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[51] = { 0, };

int main(void) {
	int n;
	cin >> n;

	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[i] = num;
	}

	sort(arr, arr + n);

	cout << arr[0] * arr[n - 1];
	return 0;
}