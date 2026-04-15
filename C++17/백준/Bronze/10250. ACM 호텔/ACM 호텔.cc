#include <iostream>
using namespace std;

int main(void) {
	int t, h, w, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> h >> w >> n;
		int h1, w1;
		h1 = n % h;
		w1 = n / h;
		if (h1 > 0) {
			w1++;
		}
		else
			h1 = h;
		cout << h1 * 100 + w1 << endl;
	}
	return 0;
}