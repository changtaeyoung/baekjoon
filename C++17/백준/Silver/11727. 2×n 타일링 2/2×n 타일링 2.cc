#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int arr[1001] = { 0,1,3, };

	for (int i = 3; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] * 2;
		arr[i] %= 10007;
	}
	cout << arr[n] << "\n";
	return 0;
}