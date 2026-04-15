#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int main(void) {
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	int sum = 0;
	int res = 0;
	sum = pow(a, 2) + pow(b, 2) + pow(c, 2) + pow(d, 2) + pow(e, 2);
	res = sum % 10;
	cout << res << endl;
	return 0;
}