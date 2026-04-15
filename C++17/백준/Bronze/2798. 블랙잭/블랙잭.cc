#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n, m, card, max = -1;
	vector<int> card_arr;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> card;
		card_arr.push_back(card);
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (card_arr[i] + card_arr[j] + card_arr[k] == m) {
					cout << m;
					return 0;
				}
				else {
					if (card_arr[i] + card_arr[j] + card_arr[k] > max && card_arr[i] + card_arr[j] + card_arr[k] <= m) {
						max = card_arr[i] + card_arr[j] + card_arr[k];
					}
				}
			}
		}
	}
	cout << max;
	return 0;
}