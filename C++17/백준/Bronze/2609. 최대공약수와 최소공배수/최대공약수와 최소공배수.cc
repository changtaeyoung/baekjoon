#include <iostream>
using namespace std;

int getNum(int a, int b) {
	if (b == 0) {
		return a;
	}
	else
		return getNum(b, a % b);
}

int main(void) {
	int a, b;
	cin >> a >> b;
	int temp = 0, rest = 0;
	if (b > a) {
		temp = a;
		a = b;
		b = temp;
	}
	cout << getNum(a, b) << endl;
	cout << a * b / getNum(a, b) << endl;

	
	return 0;
}