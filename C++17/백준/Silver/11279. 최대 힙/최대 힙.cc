#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int calNum, num;
	priority_queue<int, vector<int>> numarr;
	cin >> calNum;

	for (int i = 0; i < calNum; i++) {
		cin >> num;
		
		if (num == 0) {
			if (numarr.empty()) {
				cout << '0' << '\n';
			}
			else {
				cout << numarr.top() << '\n';
				numarr.pop();
			}
		}
		else {
			numarr.push(num);
		}
	}
	return 0;
}