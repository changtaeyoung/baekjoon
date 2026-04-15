#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int person, time, sum_Alltime = 0;
	vector<int> time_arr;
	cin >> person;

	for (int i = 0; i < person; i++) {
		cin >> time;
		time_arr.push_back(time);
	}

	sort(time_arr.begin(), time_arr.end());
	
	for (int i = 0; i < time_arr.size(); i++) {
		int sum = 0;
		for (int j = 0; j <= i; j++) {
			sum += time_arr[j];
		}
		sum_Alltime += sum;
	}
	cout << sum_Alltime;
}