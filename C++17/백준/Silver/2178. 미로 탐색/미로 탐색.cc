#include <iostream>
#include <queue>
#include <string>
#include <utility> 

using namespace std;

int n, m;

int maze[101][101];
int dist[101][101]; 

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void bfs(int startX, int startY) {
    queue<pair<int, int>> q;

    q.push({ startX, startY });
    dist[startX][startY] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }

            if (maze[nx][ny] == 1 && dist[nx][ny] == 0) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++) {
            maze[i][j] = str[j - 1] - '0';
        }
    }

    bfs(1, 1);

    cout << dist[n][m] << endl;

    return 0;
}