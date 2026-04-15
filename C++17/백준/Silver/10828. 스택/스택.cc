#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	string str;
	stack<int> st;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "push") {
			int num;
			cin >> num;
			st.push(num);
		}
		else if (str == "pop") {
			if (st.empty() == 0) {
				cout << st.top() << "\n";
				st.pop();
			}
			else {
				cout << "-1" << "\n";
			}
		}
		else if (str == "size") {
			cout << st.size() << "\n";
		}
		else if (str == "empty") {
			cout << st.empty() << "\n";
		}
		else if (str == "top") {
			if (st.empty() == 0) {
				cout << st.top() << "\n";
			}
			else {
				cout << "-1" << "\n";
			}
		}
	}
	return 0;
}