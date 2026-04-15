#include <iostream>

using namespace std;

int main(void) {
	int num[42] = {};
	int a;
	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		cin >> a;
		num[a % 42]++;
	}
	for (int i = 0; i < 42; i++) {
		if (num[i] != 0) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}