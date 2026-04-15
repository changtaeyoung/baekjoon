#include <iostream>

using namespace std;

int fuc(int num) {
	if (num == 1) {
		return 1;
	}
	else if (num == 2) {
		return 2;
	}
	else if (num == 3) {
		return 4;
	}
	return(fuc(num - 1) + fuc(num - 2) + fuc(num - 3));
}

int main(void) {
	int n;
	cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		cout << fuc(num) << "\n";
	}
	return 0;
}