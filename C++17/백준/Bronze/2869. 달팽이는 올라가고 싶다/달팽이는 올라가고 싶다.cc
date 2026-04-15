#include <iostream>
using namespace std;

int main(void) {
	int a, b, v;
	cin >> a >> b >> v;
	cout << (int)(v - b - 1) / (a - b) + 1;
	return 0;
}