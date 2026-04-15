#include <iostream>
#include <cstring>

using namespace std;

int tc, ans_ab = 0, ans_disab = 0;
char picture[101][101];
int visited[101][101];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs_ab(int stX, int stY, char target) {
    int cx = stX;
    int cy = stY;
    visited[stX][stY] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];

        if (nx < 0 || ny < 0 || nx >= tc || ny >= tc || visited[nx][ny] == 1) {
            continue;
        }
        
        if (picture[nx][ny] == target) {
            dfs_ab(nx, ny, target);
        }
    }
}

void dfs_disab(int stX, int stY, char target) {
    int cx = stX;
    int cy = stY;
    visited[stX][stY] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];

        if (nx < 0 || ny < 0 || nx >= tc || ny >= tc || visited[nx][ny] == 1) {
            continue;
        }
        
        if (target != 'B') { // R or G 이니까.
            if (picture[nx][ny] == 'R' || picture[nx][ny] == 'G') { // R과 G는 같은 dfs를 돌도록 해야해.
                dfs_disab(nx, ny, target);
            }
        }
        else {
            if (picture[nx][ny] == target) {
                dfs_disab(nx, ny, target);
            }
        }
    }
}

int main() {
    /*
        그림판이 주어질거야. R,G,B가 들어오는.
        그러면 R과 G이면 동일 색상으로 간주해서 dfs, 적록색약이 아닌 사람의 수도 찾아야하니까 제대로 저장되도록
        그리고 동일하게 dfs하면 될 것 같음.    
        R, G, B에 따라서 또 달라지니까 dfs한테 주는 것이 좋아보임.
    */

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> tc;

    for (int i = 0; i < tc; i++) {
        for (int j = 0; j < tc; j++) {
            cin >> picture[i][j];
        }
    }

    for (int i = 0; i < tc; i++) {
        for (int j = 0; j < tc; j++) {
            if (!visited[i][j]) {
                dfs_ab(i, j, picture[i][j]);
                ans_ab++;
            }
        }
    }

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < tc; i++) {
        for (int j = 0; j < tc; j++) {
            if (!visited[i][j]) {
                dfs_disab(i, j, picture[i][j]);
                ans_disab++;
            }
        }
    }

    cout << ans_ab << ' ' << ans_disab;
    return 0;
}