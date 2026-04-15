#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int notL_person, notS_person;
	string name;
	set<string> notL_arr, notS_arr, notLS_arr;

	cin >> notL_person >> notS_person;

	for (int i = 0; i < notL_person; i++) {
		cin >> name;
		notL_arr.insert(name);
	}

	for (int i = 0; i < notS_person; i++) {
		cin >> name;
		notS_arr.insert(name);
	}
	
	if (notL_arr.size() < notS_arr.size()) {
		for (const auto& elem: notL_arr) {
			if (notS_arr.find(elem) != notS_arr.end()) {
				notLS_arr.insert(elem);
			}
		}
	}
	else {
		for (const auto& elem : notS_arr) {
			if (notL_arr.find(elem) != notL_arr.end()) {
				notLS_arr.insert(elem);
			}
		}
	}

	cout << notLS_arr.size() << '\n';
	for (const auto& elem : notLS_arr) {
		cout << elem << '\n';
	}
	
}