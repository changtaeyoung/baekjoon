#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {
	int test, clothes;
	string what, where;
	cin >> test;

	for (int i = 0; i < test; i++) {
		cin >> clothes;
		map<string, int> clothing;

		for (int j = 0; j < clothes; j++) {
			cin >> what >> where;
			clothing[where]++;
		}
		int sum = 1;
		for (auto a : clothing) {
			sum *= (a.second + 1);
		}
		cout << sum - 1 << "\n";
	}
	return 0;
}