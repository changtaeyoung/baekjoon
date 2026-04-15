#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

deque<int> dq;
int types;
int counting[10] = { 0, };
int main() {
	int n;
	cin >> n;

	while (n--) {
		int fruit;
		cin >> fruit;
		dq.push_back(fruit);

		if (counting[fruit]++ == 0) {
			types++;
		}

		if (types > 2) {
			int er_fruit = dq.front();
			dq.pop_front();

			if (--counting[er_fruit] == 0) {
				types--;
			}
		}
	}
	cout << dq.size();
}