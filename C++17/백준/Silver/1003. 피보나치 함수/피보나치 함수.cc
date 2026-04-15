#include <iostream>

using namespace std;

int zero[41] = { 1,0, };
int one[41] = { 0,1, };

void computing() {
	for (int j = 2; j <= 40; j++) {
		zero[j] = zero[j - 1] + zero[j - 2];
		one[j] = one[j - 1] + one[j - 2];
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	computing();
	int test, number;
	cin >> test;

	for (int i = 0; i < test; i++) {
		cin >> number;
		cout << zero[number] << " " << one[number] << '\n';
	}

}