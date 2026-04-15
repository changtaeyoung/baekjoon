#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int m, n; // m은 가로, n은 세로
int ground[1001][1001];
int visited[1001][1001];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int cnt = 0;

queue<pair<int, int>> q;

void bfs () {
    while (!q.empty()) {
        int cx = q.front().first, cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                continue;
            }

            if (visited[nx][ny] == 0 && ground[nx][ny] != -1) {
                visited[nx][ny] = visited[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n; // m은 가로, n은 세로
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ground[i][j];
            if (ground[i][j] == 1) { // 1인 곳부터 bfs 시작 (하지만 여러개의 1이 있따면? -> 미리 queue에 다 적어 놓는거!!)
                int stX = i, stY = j;
                q.push({stX, stY});
                visited[stX][stY] = 1; // 처음에 큐에 들어간 애도 방문 처리 해줘야하니까
            }
        }
    }

    bfs();
    int max = -999999;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ground[i][j] == 0 && visited[i][j] == 0) { // 빼먹지 말것, ground가 0인 애들 중에서 방문하지 못한 애만 선택
                cout << -1;
                return 0;
            }

            if (max < visited[i][j]) {
                max = visited[i][j];
            }
        }
    }

    cout << max - 1;
    return 0;
}