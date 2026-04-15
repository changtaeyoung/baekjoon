#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int card[100] = { 0, };
    for (int i = 0; i < n; i++) {
        cin >> card[i];
    }
    int sum = 0, min=500000;
    int goal;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                sum = card[i] + card[j] + card[k];
                if (sum <= m && m - sum < min) {
                    min = m - sum;
                    goal = sum;
                }
            }
        }
    }
    cout << goal;
    return 0;
}