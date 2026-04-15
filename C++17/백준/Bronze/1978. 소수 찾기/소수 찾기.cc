#include <iostream>

using namespace std;

int main(void) {
	int arr[100] = { 0 };
	int cnt = 0, divcnt = 0;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 1; j <= arr[i]; j++) {
			if (arr[i] % j == 0) {
				divcnt++;
			}
		}	
		if (divcnt == 2) {
			cnt++;
		}
		divcnt = 0;
	}
	cout << cnt << endl;
	return 0;
}