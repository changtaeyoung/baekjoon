#include <iostream>

using namespace std;

int main(void) {
	int width, height;
	cin >> width >> height;

	if (width == 1 && height == 1) {
		cout << '0' << '\n';
	}
	else {
		cout << (height - 1) + (width - 1) * height << '\n';
	}
	return 0;
}