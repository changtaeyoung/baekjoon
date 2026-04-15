#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    double n, lost;
    int x;

    cin >> n >> x;

    lost = n * (x / 100.0);
    n -= lost;

    cout << fixed << setprecision(6) << (lost / n) * 100;
    return 0;
}