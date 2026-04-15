#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> notListen;
vector<string> notSee;
vector<string> notSeenLis;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, cnt = 0;
	string name;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> name;
		notListen.push_back(name);
	}

	for (int i = 0; i < m; i++) {
		cin >> name;
		notSee.push_back(name);
	}
	sort(notListen.begin(), notListen.end());
	sort(notSee.begin(), notSee.end());

	if (notListen.size() > notSee.size()) {
		for (int i = 0; i < m; i++) {
			if (binary_search(notListen.begin(), notListen.end(), notSee[i])) {
				notSeenLis.push_back(notSee[i]);
				cnt++;
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			if (binary_search(notSee.begin(), notSee.end(), notListen[i])) {
				notSeenLis.push_back(notListen[i]);
				cnt++;
			}
		}
	}
	cout << cnt << "\n";

	for (int i = 0; i < notSeenLis.size(); i++) {
		cout << notSeenLis[i] << "\n";
	}
	return 0;
}