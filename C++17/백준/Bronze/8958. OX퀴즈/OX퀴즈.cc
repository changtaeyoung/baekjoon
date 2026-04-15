#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	char arr[80] = "";
	int sum = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr;	
		for (int j = 0; j < strlen(arr); j++) {
			if (arr[j] == 'O') {
				cnt++;
				sum += cnt;
			}
			else if (arr[j] == 'X') {
				cnt = 0;
			}
		}
		cout << sum << endl;
		sum = 0;
		cnt = 0;
	}
	

	return 0;
}