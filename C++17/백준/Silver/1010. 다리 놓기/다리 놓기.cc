#include <iostream>

using namespace std;

int main(void) {
	int tCase;
	cin >> tCase;

	for (int i = 0; i < tCase; i++) {
		int n, m, tmp;
		long long answer = 1;
		cin >> n >> m;

		if ((m - n) == 0) {
			cout << '1' << '\n';
		}
		else {
			if (m < n) {
				tmp = m;
				m = n;
				n = tmp;
			}
			int temp = n + 1, cnt = 1;

			while (1) {
				if (cnt == (m - n + 1)) {
					break;
				}

				answer *= temp;
				answer /= cnt;
				temp++;
				cnt++;
			}
			cout << answer << '\n';
		}
	}
	return 0;
}