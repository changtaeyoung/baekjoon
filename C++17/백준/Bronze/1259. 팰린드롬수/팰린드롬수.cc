#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	bool isPel = false;

	while (true) {
		cin >> str;
		if (str == "0") {
			break;
		}

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == str[str.length() - 1 - i]) {
				isPel = true;
			}
			else {
				isPel = false;
				break;
			}
		}

		if (isPel) {
			cout << "yes" << '\n';
		}
		else {
			cout << "no" << '\n';
		}
	}
}