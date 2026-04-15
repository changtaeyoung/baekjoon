#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	vector<string> add_number;
	vector<int> sums;
	int cur_pos = 0, pos;
	string add_sep = "+", mi_sep = "-";

	while ((pos = str.find(mi_sep, cur_pos)) != string::npos) {
		int len = pos - cur_pos;
		string res = str.substr(cur_pos, len);
		add_number.push_back(res);
		cur_pos = pos + 1;
	}
	add_number.push_back(str.substr(cur_pos));

	
	for (int i = 0; i < add_number.size(); i++) {
		cur_pos = 0, pos = 0;
		int sum = 0;

		while ((pos = add_number[i].find(add_sep, cur_pos)) != string::npos) {
			int len = pos - cur_pos;
			int add_res = stoi(add_number[i].substr(cur_pos, len));
			sum += add_res;
			cur_pos = pos + 1;
		}
		sum += stoi(add_number[i].substr(cur_pos));
		
		sums.push_back(sum);
	}
	
	int result = 0;
	for (int i = 0; i < sums.size(); i++) {
		if (i == 0) {
			result += sums[i];
		}
		else {
			result -= sums[i];
		}
	}

	cout << result;
}