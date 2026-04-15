#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n; //500!은 longlong의 범위도 넘기 때문
	int ans = 0;
	for (int i = 5; i <= n; i *= 5) {
		ans += (n / i); //0이 나오는건 10의 배수를 곱할때. 2*5로 소인수 분해 가능
	}// 2와 5중 수가 더 적은거를 출력하면 됨. 2의 배수가 훨씬 많으므로 5의 배수를 체크.
	cout << ans;
	return 0;
}