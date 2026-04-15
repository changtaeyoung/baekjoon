#include <iostream>
using namespace std;
int getNum(int a, int b) {
	if (b == 1) {
		return 1;
	}
	else if (a == 0) {
		return b;
	}
	else
		return(getNum(a - 1, b) + getNum(a, b - 1));
}

int main(void) {
	int t, k, n;
	cin >> t;
	int sum = 0;
	for (int i = 0; i < t; i++) {
		cin >> k >> n;
		cout << getNum(k, n) << endl;
		
	}
	return 0;
}