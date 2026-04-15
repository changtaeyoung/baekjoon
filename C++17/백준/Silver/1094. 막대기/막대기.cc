#include <iostream>

using namespace std;

int main() {
    int len, cnt = 0;
    cin >> len;

    while (len > 1) {
        if (len % 2 == 1) {
            cnt++;
        }
        len /= 2;
    }

    cout << cnt + 1;
    return 0;
}