#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	string str;
	queue<int> q;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "push") {
			cin >> num;
			q.push(num);
		}
		else if (str == "pop") {
			if (q.empty() == 1) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (str == "size") {
			cout << q.size() << "\n";
		}
		else if (str == "empty") {
			cout << q.empty() << "\n";
		}
		else if (str == "front") {
			if (q.empty() == 1) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.front() << "\n";
			}
		}
		else if (str == "back") {
			if (q.empty() == 1) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.back() << "\n";
			}
		}

	}
	return 0;
}