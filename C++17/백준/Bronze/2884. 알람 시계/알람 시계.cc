#include <iostream>

using namespace std;

int main(void) {
	int h = 0, m = 0;
	cin >> h >> m;
	if (m >= 45 && m < 60) {
		cout << h << " " << m-45 << endl;
	}
	else {
		if (h == 0) {
			cout << 23 << " " << m + 60 - 45 << endl;
		}
		else if (h > 0 && h <= 23)
			cout << h - 1 << " " << m + 60 - 45 << endl;
	}
	return 0;
}