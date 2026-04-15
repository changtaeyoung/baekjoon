#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int sum = 0;
	char num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		sum += (num - '0');
	}
	cout << sum << endl;
	return 0;
}