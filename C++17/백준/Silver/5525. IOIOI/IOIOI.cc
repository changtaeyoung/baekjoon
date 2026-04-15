#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, m, cnt = 0;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> str;

	string finding_str = "";
	for (int i = 0; i < n; i++) {
		if (finding_str == "") {
			finding_str += "IOI";
		}
		else {
			finding_str += "OI";
		}
	}
	
	int pos, cur_pos = 0;
	while ((pos = str.find(finding_str, cur_pos)) != string::npos) {
		cnt++;
		cur_pos = pos + 1;
	}
	cout << cnt;
}