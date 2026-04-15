#include <iostream>
#include <algorithm>

using namespace std;

int dp[50001];

int main() {
	int n, cnt = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		dp[i] = i;

		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	
	cout << dp[n];
	return 0;
}