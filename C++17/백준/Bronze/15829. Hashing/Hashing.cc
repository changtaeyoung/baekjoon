#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
int m = 1234567891;

using namespace std;

int main(void) {
	int test;
	scanf("%d", &test);
	vector<char> v(test);

	for (int i = 0; i < test; i++) {
		scanf(" %c", &v[i]);
		v[i] = v[i] - 96;
	}
	long long sum = 0;
	long long r = 1;
	for (int i = 0; i < test; i++) {
		sum = (sum + v[i] * r) % m;
		r = (r * 31) % m;
	}
	printf("%lld", sum);
	return 0;
}