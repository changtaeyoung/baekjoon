#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> set;

void add(int num) {
	bool isNum = false;
	for (int i = 0; i < set.size(); i++) {
		if (num == set[i]) {
			isNum = true;
			break;
		}
	}
	if (!isNum) {
		set.push_back(num);
	}
}

void remove(int num) {
	bool isNum = false;
	int index;
	for (int i = 0; i < set.size(); i++) {
		if (num == set[i]) {
			isNum = true;
			index = i;
			break;
		}
	}
	if (isNum) {
		set.erase(set.begin() + index);
	}
}

void check(int num) {
	bool isNum = false;
	for (int i = 0; i < set.size(); i++) {
		if (num == set[i]) {
			isNum = true;
			break;
		}
	}
	if (isNum) {
		cout << 1 << "\n";
	}
	else {
		cout << 0 << "\n";
	}
}

void toggle(int num) {
	bool isNum = false;
	for (int i = 0; i < set.size(); i++) {
		if (num == set[i]) {
			isNum = true;
			break;
		}
	}
	if (isNum) {
		remove(num);
	}
	else {
		add(num);
	}
}

void all() {
	set.clear();
	for (int i = 1; i <= 20; i++) {
		set.push_back(i);
	}
}

void empty() {
	set.clear();
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test, number;
	string str, order;
	
	cin >> test;
	cin.ignore();
	for (int i = 0; i < test; i++) {
		getline(cin, str);

		if (str.find(" ") != -1) {
			order = str.substr(0, str.find(" "));
			number = stoi(str.substr(str.find(" ") + 1, str.length()));
		}
		else {
			order = str;
		}

		if (order == "add") {
			add(number);
		}
		else if (order == "remove") {
			remove(number);
		}
		else if (order == "check") {
			check(number);
		}
		else if (order == "toggle") {
			toggle(number);
		}
		else if (order == "all") {
			all();
		}
		else if (order == "empty") {
			empty();
		}
	}
}