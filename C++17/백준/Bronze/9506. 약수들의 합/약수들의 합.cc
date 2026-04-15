#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	while (1) {
		int tCase;
		vector<int> numarr;
		int sum = 0;
		cin >> tCase;

		if (tCase == -1) {
			break;
		}
		else {
			for (int i = 1; i <= tCase; i++) {
				if (tCase % i == 0 && i != tCase) {
					sum += i;
					numarr.push_back(i);
				}
			}
			if (sum == tCase) {
				cout << tCase << " = ";
				for (int i = 0; i < numarr.size(); i++) {
					if (i != numarr.size() - 1) {
						cout << numarr[i] << " + ";
					}
					else if (i == numarr.size() - 1) {
						cout << numarr[i];
					}
				}
				cout << '\n';
			}
			else {
				cout << tCase << " is NOT perfect." << '\n';
			}
		}
		numarr.clear();
	}
	return 0;
}