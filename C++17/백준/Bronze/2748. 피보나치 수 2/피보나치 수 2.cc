#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long arr[91] = { 0, };

int main(void) {
	int n;
	cin >> n;
	arr[0] = 0;
	arr[1] = 1;
	
	for (int i = 0; i < n - 1; i++) {
		arr[i + 2] = arr[i] + arr[i + 1];
	}
	cout << arr[n];
	return 0;
}