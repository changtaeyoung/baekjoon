#include <iostream>

using namespace std;

int main(void) {
	int arr[1000] = { 0 };
	int n, stu;
	cin >> n;
	int score;
	double aver;
	for (int i = 0; i < n; i++) {
		cin >> stu;
		int sum = 0;
		for (int j = 0; j < stu; j++) {
			cin >> score;
			arr[j] = score;
			sum += arr[j];
		}
		aver = (double)sum / stu;
		int cnt = 0;
		for (int j = 0; j < stu; j++) {
			if (arr[j] > aver) {
				cnt++;
			}
		}
		cout << fixed;
		cout.precision(3);
		cout << 100.0 * cnt / stu << "%" << endl;
	}
	return 0;
}