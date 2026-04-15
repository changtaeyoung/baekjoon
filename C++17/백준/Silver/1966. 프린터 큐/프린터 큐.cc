#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int tc, n, target, imp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> tc;
    for (int i = 0; i < tc; i++) {
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        cin >> n >> target;

        for (int j = 0; j < n; j++) {
            cin >> imp;

            q.push({imp, j});
            pq.push(imp);
        }
        int ans = 0;
        while(!pq.empty()) {
            if (pq.top() == q.front().first) {
                ans++;
                if (q.front().second == target) {
                    break;
                }
                pq.pop();
                q.pop();
            }
            else {
                pair<int, int> p = q.front();
                q.pop();
                q.push(p);
            }
        }
        cout << ans << '\n';
        ans = 0;
    }
    return 0;
}