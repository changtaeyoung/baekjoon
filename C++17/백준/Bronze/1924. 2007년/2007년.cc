#include <iostream>
#include <string>

using namespace std;

int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
string day[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };

int main(void) {
	int x, y;
	cin >> x >> y;
	int sum = 0;
	if (x == 1) {
		cout << day[(y - 1) % 7];
	}
	else if (x > 1) {
		for (int i = 0; i < x - 1; i++) {
			sum += month[i];
		}
		sum += y;
		cout << day[(sum - 1) % 7];
	}
	return 0;
}