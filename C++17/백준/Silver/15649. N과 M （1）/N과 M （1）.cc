#include <iostream>

using namespace std;

int n, m;
int buffer[9];
int visited[9] = {0, };

void dfs(int idx) {
    if (idx == m) {
        for (int i = 0; i < m; i++) {
            cout << buffer[i] << " ";
        }
        cout << '\n';
    }
    else {
        for (int i = 1; i <= n; i++) {
            if(!visited[i]) {
                visited[i] = 1;
                buffer[idx] = i;
                dfs(idx + 1);
                visited[i] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    dfs(0);
    return 0;
}