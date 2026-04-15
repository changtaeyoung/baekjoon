#include <iostream>

using namespace std;

int n, m, cnt = 0;

char road[600][600];
int dist[600][600];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int startX, int startY) {
    if(road[startX][startY] == 'P') {
        cnt++;
    }
    dist[startX][startY] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = startX + dx[i];
        int ny = startY + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m || road[nx][ny] == 'X') {
            continue;
        }

        if ((road[nx][ny] == 'O' && dist[nx][ny] == 0) || (road[nx][ny] == 'P' && dist[nx][ny] == 0)) {
            dfs(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x, y;
    char d;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d;
            road[i][j] = d;
            if (d == 'I') {
                x = i;
                y = j;
            }
        }
    }

    dfs(x, y);

    if (cnt == 0) {
        cout << "TT";
    }
    else {
        cout << cnt;
    }

    return 0;
}