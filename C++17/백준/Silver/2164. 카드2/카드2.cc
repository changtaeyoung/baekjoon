#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	queue<int> card_arr;
	int card;

	cin >> card;

	for (int i = 1; i <= card; i++) {
		card_arr.push(i);
	}

	while (card_arr.size() > 1) {
		card_arr.pop();
		int tmp = card_arr.front();
		card_arr.pop();
		card_arr.push(tmp);
	}

	cout << card_arr.front();
}