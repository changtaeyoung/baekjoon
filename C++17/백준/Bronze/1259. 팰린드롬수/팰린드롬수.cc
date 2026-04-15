#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	string str, revstr;
	while (1) {
		cin >> str;
		for (int i = str.length() - 1; i >= 0; i--) {
			revstr+= str[i];
		}
		if (str == "0") {
			break;
		}
		else if (str.compare(revstr) == 0) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}
		revstr = "";
	}	
	return 0;
}