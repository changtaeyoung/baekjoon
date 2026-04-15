#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string a, b, res;
	cin >> a >> b;

	for (int i = 2; i >= 0; i--) {
		if (a[i] > b[i]) {
			res = a;
			break;
		}
		else if (a[i] < b[i]) {
			res = b;
			break;
		}
	}
	cout << res[2] << res[1] << res[0];
	return 0;
}