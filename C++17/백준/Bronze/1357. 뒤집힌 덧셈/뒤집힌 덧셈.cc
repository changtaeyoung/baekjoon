#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	string x, y;
	cin >> x >> y;

	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	int result = stoi(x) + stoi(y);
	string res = to_string(result);
	reverse(res.begin(), res.end());
	
	cout << stoi(res);
	return 0;
}