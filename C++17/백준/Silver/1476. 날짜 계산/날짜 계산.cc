#include <iostream>

using namespace std;

int main() {
    int e, s, m, ans;
    cin >> e >> s >> m;

    for (int i = 1; ; i++) {
        if (e == 15) {
            e = 0;
        }

        if (s == 28) {
            s = 0;
        }

        if (m == 19) {
            m = 0;
        }
        
        if (i % 15 == e && i % 28 == s && i % 19 == m) {
            ans = i;
            break;
        }
    }
    cout << ans;
    return 0;
}