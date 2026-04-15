#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	return a.length() < b.length();
}

int main(void) {
	int test_times;
	string str;
	set<string> str_set;
	vector<string> str_arr;

	cin >> test_times;

	for (int i = 0; i < test_times; i++) {
		cin >> str;
		if (str_set.find(str) == str_set.end()) {
			str_set.insert(str);
			str_arr.push_back(str);
		}
	}

	sort(str_arr.begin(), str_arr.end(), compare);

	for (int i = 0; i < str_arr.size(); i++) {
		cout << str_arr[i] << '\n';
	}
}