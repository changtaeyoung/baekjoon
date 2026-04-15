#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> scoreSum;
    int score, max = -1, idx = 0;

    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            cin >> score;
            sum += score;
        }
        scoreSum.push_back(sum);
    }

    for (int i = 0; i < scoreSum.size(); i++) {
        if (max < scoreSum[i]) {
            max = scoreSum[i];
            idx = i;
        }
    }

    cout << idx + 1 << " " << scoreSum[idx];
    return 0;
}