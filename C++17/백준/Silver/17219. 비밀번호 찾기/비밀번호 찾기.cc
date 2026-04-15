#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, string> pass;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	string site, password, isSite;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> site >> password;
		pass.insert({ site, password });
	}

	for (int i = 0; i < m; i++) {
		cin >> isSite;
		if (pass.find(isSite) != pass.end()) {
			cout << pass.find(isSite)->second << "\n";
		}
	}
	return 0;
}