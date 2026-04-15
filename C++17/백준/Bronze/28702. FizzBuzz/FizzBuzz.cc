#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	string str;
	vector<string> str_vec;

	int ans;

	for (int i = 0; i < 3; i++) {
		cin >> str;
		str_vec.push_back(str);
	}

	for (int i = 0; i < 3; i++) {
		if ((int)str_vec[i][0] >= 48 && (int)str_vec[i][0] <= 57) {
			if (i == 0) {
				ans = stoi(str_vec[i]) + 3;
			}
			else if (i == 1) {
				ans = stoi(str_vec[i]) + 2;
			}
			else if (i == 2) {
				ans = stoi(str_vec[i]) + 1;
			}
		}
	}

	if (ans % 3 == 0 && ans % 5 == 0) {
		cout << "FizzBuzz";
	}
	else if (ans % 3 == 0 && ans % 5 != 0) {
		cout << "Fizz";
	}
	else if (ans % 3 != 0 && ans % 5 == 0) {
		cout << "Buzz";
	}
	else if (ans % 3 != 0 && ans % 5 != 0) {
		cout << ans;
	}

	return 0;
}