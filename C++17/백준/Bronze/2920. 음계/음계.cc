#include <iostream>

using namespace std;

int main(void) {
	int num[8] = {};
	for (int i = 0; i < 8; i++) {
		cin >> num[i];
	}
	int asc = 0, des = 0;
	for (int i = 0; i < 7; i++) {
		if (num[i] > num[i + 1]) {
			des++;
		}
		else if (num[i] < num[i + 1]) {
			asc++;
		}
	}
	if (des == 7) {
		cout << "descending" << endl;
	}
	else if (asc == 7) {
		cout << "ascending" << endl;
	}
	else {
		cout << "mixed" << endl;
	}
	return 0;
}