#include <iostream>

using namespace std;

 int main(void) {
	int N, T;
	cin >> T;
	long long tri[101] = { 1,1,1, };

	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 3; j < N; j++) {
			tri[j] = tri[j - 3] + tri[j - 2];
		}
		cout << tri[N - 1] << "\n";
	}
	return 0;
}