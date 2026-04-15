#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[101][101];

int main() {
    int testcase, cnt = 0, n, m;
    cin >> testcase;

    while(testcase--) {
        cin >> n >> m;
        for (int i = m; i < m + 10; i++) {
            for (int j = n; j < n + 10; j++) {
                if(!a[i][j]) {
                    cnt++;
                    a[i][j] = 1;
                }
            }
        }
    }

    cout << cnt;
    return 0;
}