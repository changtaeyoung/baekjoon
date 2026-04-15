#include <iostream>

using namespace std;

int main(void) {
	int num;
	cin >> num;

	int cnt = 0;
	if (num < 100) {
		for (int i = 1; i <= num; i++) {
			cnt++;
		}
	}
	else if (num >= 100 && num <= 1000) {
		for (int i = 1; i <= 99; i++) {
			cnt++;
		}
		for (int i = 100; i <= num; i++) {
			if (((i / 100) - (i % 100) / 10) == (i % 100) / 10 - i % 10){
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}