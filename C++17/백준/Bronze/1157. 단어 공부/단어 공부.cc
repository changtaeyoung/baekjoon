#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(void) {
	string s;
	cin >> s;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	int alparr[26] = {};
	int max = alparr[0], res;
	int resultnum = 0;
	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}

	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < alphabet.length(); j++) {
			alparr[(int)alphabet.find(s[i])]++;
		}
	}
	for (int i = 0; i < alphabet.length(); i++) {
		alphabet[i] = toupper(alphabet[i]);
	}
	for (int i = 0; i < 26; i++) {
		if (max > alparr[i]) {
			max = max;
		}
		else if (max == alparr[i]) {
			resultnum++;
		}
		else {
			max = alparr[i];
			res = i;
			resultnum = 0;
		}

	}
	if (resultnum > 0) {
		cout << "?" << endl;
	} 
	else {
		cout << alphabet[res] << endl;
	}
	return 0;
}