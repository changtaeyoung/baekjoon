#include <iostream>

using namespace std;

int solvProb(int n) {
	if (n >= 1000) {
		return 1;
	}
	return 0;
}

int lev(int u, int l) {
	if ((u >= 8000 ) || (l >= 260)) {
		return 1;
	}
	return 0;
}


int main(void) {
	int N, U, L;
	cin >> N >> U >> L;

	if (solvProb(N) == 0) {
		cout << "Bad";
		return 0;
	}
	if (lev(U, L) == 1) {
		cout << "Very Good";
	}
	else if (lev(U, L) == 0) {
		cout << "Good";
	}
	return 0;
}