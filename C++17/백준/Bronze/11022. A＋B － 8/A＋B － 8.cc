#include <iostream>

using namespace std;

int main(void) {
	int n = 0;
	cin >> n;
	int a = 0, b = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		cout << "Case #" << i << ": ";
		cout << a << " + " << b << " = " << a + b << endl;
	}
	return 0;
}