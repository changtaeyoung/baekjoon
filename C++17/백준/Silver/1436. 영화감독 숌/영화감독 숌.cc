#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int n, i = 0, cnt = 0;
	string num;
	cin >> n;

	while (1) {
		i++;
		num = to_string(i);
		if (num.find("666") != string::npos) {
			cnt++;
		}
		if (cnt == n) {
			break;
		}
	}
	cout << i;
	return 0;
}