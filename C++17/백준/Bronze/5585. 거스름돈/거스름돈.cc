#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int cnt[6] = { 0, };

int main(void) {
	int cost;
	cin >> cost;
	int num = 1000 - cost;
	while (num != 0) {
		if (num >= 500) {
			for (int i = 0; i < (int)(num / 500); i++) {
				cnt[0]++;
			}
			num = num % 500;
		}
		else if (num >= 100 && num < 500) {
			for (int i = 0; i < (int)(num / 100); i++) {
				cnt[1]++;
			}
			num = num % 100;
		}
		else if (num >= 50 && num < 100) {
			for (int i = 0; i < (int)(num / 50); i++) {
				cnt[2]++;
			}
			num = num % 50;
		}
		else if (num >= 10 && num < 50) {
			for (int i = 0; i < (int)(num / 10); i++) {
				cnt[3]++;
			}
			num = num % 10;
		}
		else if (num >= 5 && num < 10) {
			for (int i = 0; i < (int)(num / 5); i++) {
				cnt[4]++;
			}
			num = num % 5;	
		}
		else if (num >= 1 && num < 5) {
			for (int i = 0; i < (int)(num / 1); i++) {
				cnt[5]++;
			}
			num = num % 1;
		}
	}
	int sum = 0;
	for (int i = 0; i < 6; i++) {
		sum += cnt[i];
	}
	cout << sum;
	return 0;
}