#include <iostream>
using namespace std;

int main(void) {
	int* arr = new int[10000000];
	int n = 0;
	cin >> n;
	int num, max = 0, min = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[i] = num;
	}
	max = arr[0];
	min = arr[0];
	for (int i = 0; i < n; i++) {
		max = max > arr[i] ? max : arr[i];
		min = min < arr[i] ? min : arr[i];
	}
	cout << min << endl;
	cout << max << endl;
	delete[] arr;
	return 0;
}