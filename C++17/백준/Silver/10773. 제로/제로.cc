#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;


int main(void) {
	int test;
	cin >> test;
	deque<int> dq;
	int sum = 0;
	for (int i = 0; i < test; i++) {
		int num;
		cin >> num;
		dq.push_back(num);
		if (num == 0) {
			dq.pop_back();
			dq.pop_back();
		}
	}
	for (int i =0; i < dq.size(); i++) {
		sum += dq[i];
	}
	cout << sum;
	return 0;
}