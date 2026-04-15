#include <iostream>

using namespace std;

int main(void) {
	int num, cnt = 0, i = 1, tmp;
	cin >> num;

	while (1) {
		if (cnt + i < num) {
			cnt += i;
			i++;
		}
		else {
			break;
		}
	}
	i = i + 1;
	tmp = num - cnt;
	if (i % 2 == 0) {
		cout << i - tmp << "/" << tmp;

	}
	else if (i % 2 == 1) {
		cout << tmp << "/" << i - tmp;
	}
	return 0;
}