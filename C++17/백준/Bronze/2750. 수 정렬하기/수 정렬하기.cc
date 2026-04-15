#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int numCnt, num;
	vector<int> vec;
	cin >> numCnt;

	for (int i = 0; i < numCnt; i++) {
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
	return 0;
}