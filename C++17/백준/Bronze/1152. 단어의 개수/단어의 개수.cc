#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(void) {
	string arr;
	getline(cin, arr);
	int cnt = 1;
	for (int i = 0; i < arr.length(); i++) {
		if (arr[i] == ' ') {
			cnt++;
		}
	}
	if (arr[0] == ' ') {
		cnt--;
	}
	if (arr[arr.length() - 1] == ' ') {
		cnt--;
	}
	cout << cnt << endl;
	return 0;
}