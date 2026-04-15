#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
	int testlength;
	string testcase;

	cin >> testlength;

	stack<char> st;

	for (int i = 0; i < testlength; i++) {
		bool balance = true;
		cin >> testcase;
		for (int j = 0; j < testcase.length(); j++) {
			if (testcase[j] == '(') {
				st.push(testcase[j]);
			}
			else if (testcase[j] == ')') {
				if (st.empty()) {
					balance = false;
					break;
				}
				st.pop();
			}
		}
		if (balance && st.empty()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		while (!st.empty()) {
			st.pop();
		}
	}
	return 0;
}