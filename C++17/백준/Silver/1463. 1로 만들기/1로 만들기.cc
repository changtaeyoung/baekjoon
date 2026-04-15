#include <iostream>

using namespace std;

int main(void) {
	int number, cnt[1000001] = { 0,0,1,1, };
	cin >> number;

	for (int i = 4; i <= number; i++) {
		if (i % 3 != 0 && i % 2 != 0) {
			cnt[i] = cnt[i - 1] + 1;
		}
		else if (i % 2 == 0 && i % 3 == 0) {
			cnt[i] = min(cnt[i / 2] + 1, cnt[i / 3] + 1);
		}
		else if (i % 3 == 0) {
			cnt[i] = min(cnt[i / 3] + 1, cnt[i - 1] + 1);
		}
		else if (i % 2 == 0) {
			cnt[i] = min(cnt[i / 2] + 1, cnt[i - 1] + 1);
		}
	}
	cout << cnt[number];
}