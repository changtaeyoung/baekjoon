#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num, num2, sum = 0;
    vector<int> a;
    vector<int> b;

    cin >> num;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < num; j++) {
            cin >> num2;
            if (i == 0) {
                a.push_back(num2);
            }
            else if (i == 1) {
                b.push_back(num2);
            }
        }
    }
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
    for (int i = 0; i < num; i++) {
        sum += (a[i] * b[i]);
    }

    cout << sum;
    return 0;
}