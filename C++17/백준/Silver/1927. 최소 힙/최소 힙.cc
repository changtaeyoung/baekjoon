#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unsigned int calNum, num;
	priority_queue<int, vector<int>, greater<int>> numarr;

	cin >> calNum;
	for (int i = 0; i < calNum; i++) {
		cin >> num;
		if (num != 0) {
			numarr.push(num);
		}
		else if (num == 0) {
			if (numarr.empty()) {
				cout << '0' << "\n";
			}
			else {
				cout << numarr.top() << "\n";
				numarr.pop();
			}
		}
	}
	return 0;
}