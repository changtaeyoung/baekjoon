#include <iostream>

using namespace std;

int main(void) {
	int num;
	cin >> num;

	while (num > 1) {
		for (int i = 2; i <= num; i++) {
			if (num % i == 0) {
				num = num / i;
				cout << i << '\n';
				break;
			}
		}
	}
	return 0;
}