#include <iostream>

using namespace std;

int numbering[11] = { 0, };

void precomputing() {
	numbering[1] = 1;
	numbering[2] = 2;
	numbering[3] = 4;

	for (int i = 4; i < 11; i++) {
		numbering[i] = numbering[i - 3] + numbering[i - 2] + numbering[i - 1];
	}
}

int main(void) {
	int test, num;
	cin >> test;

	precomputing();

	for (int i = 0; i < test; i++) {
		cin >> num;
		cout << numbering[num] << '\n';
	}
}