#include <iostream>
#include <string>

using namespace std;

int arr[26] = { 0, };

int main() {
	string str;
	cin >> str;

	for (char c : str) {
		arr[c - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}
}