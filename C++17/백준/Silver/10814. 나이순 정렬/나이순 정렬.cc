#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(const pair<int, string>& a, const pair<int, string>& b) {
	return a.first < b.first;
}

int main(void) {
	int member, age;
	string name;
	pair<int, string> member_info;
	vector<pair<int, string>> member_arr;
	cin >> member;

	for (int i = 0; i < member; i++) {
		cin >> age >> name;
		member_info.first = age;
		member_info.second = name;
		member_arr.push_back(member_info);
	}

	stable_sort(member_arr.begin(), member_arr.end(), compare);

	for (int i = 0; i < member_arr.size(); i++) {
		cout << member_arr[i].first << " " << member_arr[i].second << '\n';
	}
}