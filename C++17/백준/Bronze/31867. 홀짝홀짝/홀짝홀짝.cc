#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cnt_odd = 0, cnt_even = 0;
    string k;

    cin >> n >> k;

    for (char c : k) {
        if ((c - '0') % 2 == 1) {
            cnt_odd++;
        }
        else {
            cnt_even++;
        }
    }

    if (cnt_odd > cnt_even) {
        cout << 1;
    }
    else if (cnt_odd < cnt_even) {
        cout << 0;
    }
    else {
        cout << -1;
    }

    return 0;
}