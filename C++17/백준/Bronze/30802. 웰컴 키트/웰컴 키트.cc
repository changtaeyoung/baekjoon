#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int memberNum;
	int num, t, p;
	vector<int> shirts;

	int ansT = 0, ansP = 0, ansP_1 = 0;

	cin >> memberNum;
	for (int i = 0; i < 6; i++) {
		cin >> num;
		shirts.push_back(num);
	}
	cin >> t >> p;

	for (int i = 0; i < 6; i++) {
		if (shirts[i] % t == 0) {
			ansT += (shirts[i] / t);
		}
		else {
			ansT += ((shirts[i] / t) + 1);
		}
	}

	ansP = memberNum / p;
	ansP_1 = memberNum % p;

	cout << ansT << '\n';
	cout << ansP << ' ' << ansP_1;
	return 0;
}