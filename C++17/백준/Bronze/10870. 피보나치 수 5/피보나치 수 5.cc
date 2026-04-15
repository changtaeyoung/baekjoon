#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	int arr[21] = { 0, };
	arr[1] = 1;
	for (int i = 0; i <= n - 2; i++) {
		arr[i + 2] = arr[i] + arr[i + 1];
	}
	cout << arr[n];
	return 0;
}