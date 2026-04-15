#include <iostream>

using namespace std;

int main(void) {
	int tCase, num1, num2;
	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		cin >> num1 >> num2;
		if (num1 == 1 || num2 == 1) {
			cout << num1 * num2 << '\n';
		}
		else if(num1 > num2) {
			for (int j = 1;; j++) {
				if ((num1 * j) % num2 == 0) {
					cout << num1 * j << '\n';
					break;
				}
			}
		}
		else if (num1 < num2) {
			for (int k = 1;; k++) {
				if ((num2 * k) % num1 == 0) {
					cout << num2 * k << '\n';
					break;
				}
			}
		}
		else if (num1 == num2) {
			cout << num1 << '\n';
		}
	}
	return 0;
}