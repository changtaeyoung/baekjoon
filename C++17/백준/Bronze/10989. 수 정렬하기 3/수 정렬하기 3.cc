#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int num;
	int arr[10001] = { 0 };

 	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[a]++;
	}

	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << i << "\n";
		}
	}
	return 0;
}