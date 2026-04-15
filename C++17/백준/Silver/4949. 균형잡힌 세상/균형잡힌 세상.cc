#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {

	while (true) {
		string str;
		stack<char> st;

		getline(cin, str);
		if (str == ".") {
			break;
		}
		bool tnf = true;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(' || str[i] == '[') {
				st.push(str[i]);
			}
			else if (str[i] == ')') {
				if (!st.empty() && st.top() == '(') {
					st.pop();
					tnf = true;
				}
				else {
					tnf = false;
					break;
				}
			}
			else if (str[i] == ']') {
				if (!st.empty() && st.top() == '[') {
					st.pop();
					tnf = true;
				}
				else {
					tnf = false;
					break;
				}
			}
		}
		if (tnf && st.empty()) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}
	}
	return 0; 
}