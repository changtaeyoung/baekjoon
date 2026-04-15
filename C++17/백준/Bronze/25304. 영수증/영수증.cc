#include <iostream>

using namespace std;

int main(void) {
	int total = 0;
	cin >> total;
	int many = 0;
	cin >> many;
	int a = 0, b = 0;
	int sum = 0;
	for (int i = 1; i <= many; i++) {
		cin >> a >> b;
		sum += a * b;
	}
	if (sum == total) {
		cout << "Yes" << endl;
	}
	else
		cout << "No" << endl;
	return 0;
}