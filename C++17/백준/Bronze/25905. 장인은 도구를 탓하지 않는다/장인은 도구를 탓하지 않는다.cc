#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    double poss, res = 1.0;
    vector<double> possi;

    for (int i = 0; i < 10; i++) {
        cin >> poss;
        possi.push_back(poss);
    }

    sort(possi.rbegin(), possi.rend());

    for (int i = 0; i < 9; i++) {
        res *= possi[i] / (i + 1);
    }
    cout << fixed << setprecision(6) << res * 1000000000;
    return 0;
}