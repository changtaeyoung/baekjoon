#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	while (true) {
		string prev_str = str;
		str = str[0] * str.length();
		if (prev_str == str) {
			cout << "FA";
			break;
		}
	}
}