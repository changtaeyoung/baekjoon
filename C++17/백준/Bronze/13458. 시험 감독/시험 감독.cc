#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(void) {
	int testroom, total_sup, sub_sup;
	
	cin >> testroom;
	vector<int> testmem(testroom);
	int t_suv, sub_suv = 0;

	for (int i = 0; i < testroom; i++) {
		cin >> testmem[i];
	}

	cin >> total_sup >> sub_sup;
	long long sum=0;

	for (int i = 0; i < testroom; i++) {
		if (testmem[i] <= total_sup) {
			sum++;
		}
		else {
			sum += (testmem[i] - total_sup) / sub_sup + 1;
			if ((testmem[i] - total_sup) % sub_sup != 0) {
				sum++;
			}
		}
	}
	cout << sum;
	return 0;
}