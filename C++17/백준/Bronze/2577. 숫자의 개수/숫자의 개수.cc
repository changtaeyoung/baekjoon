#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int main(void) {
	int a, b, c;
	int num[10] = {};
	cin >> a >> b >> c;
	int res = a * b * c;

	while (res != 0) {
		num[res % 10]++;
		res /= 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << num[i] << endl;
	}
	return 0;
}