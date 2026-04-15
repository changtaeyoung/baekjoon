#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
	int testcase, number;
	stack<int> s;
	vector<char> v;
	int cnt = 1;

	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> number;
		while (cnt <= number) {
			s.push(cnt);
			cnt += 1;
			v.push_back('+');
		}
		if (s.top() == number) {
			s.pop();
			v.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}
