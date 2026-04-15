#include <iostream>
using namespace std;

int main() {
	char name[100] = "";
	cin >> name;
	for (int i = 0; name[i] != '\0'; i++) {
		cout << name[i];
		if (i != 0 && i % 10 == 9) { 
			cout << "\n";
		}
	}
	return 0;
}