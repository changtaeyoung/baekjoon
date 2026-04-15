#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long number, sum = 0, res;

    cin >> number;

    if (number <= 1) {
        cout << number << '\n';
        return 0;
    }

    long double ld = number;
    res = (long long)((sqrtl)(1.0 + 8.0*ld) - 1.0) / 2.0;
    cout << res;
    return 0;
}